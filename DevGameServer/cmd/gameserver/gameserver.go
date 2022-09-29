package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net"
	"net/http"
	"net/url"
	"os"
	"path"
	"strconv"
	"strings"
	"time"
)

func main() {
	logo := `
                     __                     _       ______  _   __
              ____  / /___ ___  _____  ____| |     / / __ \/ | / /
             / __ \/ / __ '/ / / / _ \/ ___/ | /| / / / / /  |/ /
            / /_/ / / /_/ / /_/ /  __/ /   | |/ |/ / /_/ / /|  /
           / .___/_/\__,_/\__, /\___/_/    |__/|__/\____/_/ |_/
          /_/            /____/
                                          Example Game Server
`
	fmt.Println(logo)

	portStr := os.Getenv("PORT")
	credentialsClientID := os.Getenv("CLIENT_ID")
	credentialsSecret := os.Getenv("CLIENT_SECRET")
	gametitleID := os.Getenv("GAMETITLE_ID")

	port, err := strconv.Atoi(portStr)
	if err != nil {
		log.Fatal("env variable PORT should be an integer")
	}
	if len(credentialsClientID) == 0 {
		log.Fatal("missing env variable CLIENT_ID")
	}
	if len(credentialsSecret) == 0 {
		log.Fatal("missing env variable CLIENT_SECRET")
	}
	if len(gametitleID) == 0 {
		log.Fatal("missing env variable GAMETITLE_ID")
	}

	addr := fmt.Sprintf(":%v", port)

	listener, err := net.Listen("tcp", addr)
	if err != nil {
		log.Fatal(err)
	}

	resolvedPort := listener.Addr().(*net.TCPAddr).Port

	fmt.Printf("Running at: http://localhost:%v\n", resolvedPort)
	fmt.Println("Endpoints supported:")
	fmt.Printf("POST http://localhost:%v/login\n", resolvedPort)
	fmt.Println("\nHTTP event log:")

	http.HandleFunc("/", echoHandler) // catch-all for any other endpoints
	http.HandleFunc("/login", loginHandler(credentialsClientID, credentialsSecret, gametitleID, http.DefaultClient))

	log.Fatal(http.Serve(listener, nil))
}

const playerWONAPIAddress = "https://game.simulmedia-apis.com"

func loginHandler(clientID string, secret string, gametitleID string, httpClient *http.Client) http.HandlerFunc {
	type tokenResponse struct {
		AccessToken string `json:"access_token"`
		TokenType   string `json:"token_type"`
		ExpiresIn   int    `json:"expires_in"`
	}
	return func(w http.ResponseWriter, r *http.Request) {
		fmt.Println(time.Now())
		fmt.Println(r)

		values := url.Values{}
		values.Set("client_id", clientID)
		values.Set("client_secret", secret)
		values.Set("grant_type", "client_credentials")
		values.Set("tid", gametitleID)

		idfa := path.Base(r.URL.String())
		if !strings.EqualFold(idfa, "login") {
			values.Set("idfa", idfa)
		}

		req, err := http.NewRequest(http.MethodPost, playerWONAPIAddress+"/token", strings.NewReader(values.Encode()))
		if err != nil {
			fmt.Println(err)
			return
		}
		req.Header.Add("Content-Type", "application/x-www-form-urlencoded")
		res, err := httpClient.Do(req)
		if err != nil {
			fmt.Println(err)
			return
		}
		defer res.Body.Close()
		if res.StatusCode < 200 || res.StatusCode > 299 {
			fmt.Printf("PlayerWON API call failed. Response code: %v\n", res.StatusCode)
			return
		}
		tokenRes := tokenResponse{}
		err = json.NewDecoder(res.Body).Decode(&tokenRes)
		if err != nil {
			fmt.Println(err)
			return
		}

		w.Write([]byte(tokenRes.AccessToken)) // return the access token to the game client
	}
}

func echoHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Println(time.Now())
	fmt.Println(r)
	w.Write([]byte("This path doesn't do anything. Try /login"))
}
