# PlayerWON Example Game Server
This game server is meant to be run along the PlayerWON SDK or a game under development that doesn't have a server yet.
It supports one `/login/` endpoint which will use the configured PlayerWON API credentials to fetch
a new `Access Token` that should be passed to the game client for each player starting the game.

In a production game, the `/token` API call in this example, would be hosted by your game server.

## Setup before running
To run, the game server requires the following environment variables to be set:
- `PORT` (optional - default is a random empty port)
- `CLIENT_ID`
- `CLIENT_SECRET`
- `GAMETITLE_ID`

### Windows
`set PORT=1122`

### Unix-like
`export PORT=1122`

## Running the server
Run one of the binaries in `/bin`
Supported platforms are:
    - Windows 10/11
    - Linux
    - MacOS

## Endpoints
`POST http://localhost:{PORT}/login/{user_id}`
Returns an Access Token string or an error string.
Note: we call user ID `idfa` on the PlayerWON backend