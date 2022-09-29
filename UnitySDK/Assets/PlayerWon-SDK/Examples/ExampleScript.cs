using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Video;


using PlayerWON;


public class ExampleScript : MonoBehaviour
{
    public GameObject opportunityButton;
    public GameObject playButton;
    public GameObject stopButton;
    public Text timerText;
    public GameObject adDisplay;

    //Player's unique ID provided by the game server
    private string IDFA = "abcd1234";

    private void Awake()
    {
        opportunityButton.SetActive(false);
        playButton.SetActive(false);
        stopButton.SetActive(false);
        timerText.gameObject.SetActive(false);
        adDisplay.SetActive(false);
    }


    private void Start()
    {
        if(Bridge.Instance)
        {
            Bridge.Instance.Init(IDFA, Application.unityVersion, Application.productName);
        }
    }

    private void Update()
    {
        if(Bridge.Instance)
        {
            if(Bridge.Instance.VideoPlayer.isPlaying)
            {
                if(timerText.gameObject.activeSelf)
                {
                    timerText.text = Bridge.Instance.TimeLeftInOpportunityFloored().ToString();
                }
            }
        }
    }

    public void Authorize()
    {
        if(Bridge.Instance)
        {
            Bridge.Instance.AuthorizeClient("http://localhost:1337/login");
        }
    }

    public void OnSuccessfulAuthorization(string token)
    {
        opportunityButton.SetActive(true);
    }

    public void GetOpportunity()
    {
        ClientDetails details = new ClientDetails(SupportedCountries.United_States, IDFA, PlatformType.PC, SupportedLanguages.English);
        if(Bridge.Instance)
        {
            Bridge.Instance.SetClientDetails(details);
            Bridge.Instance.RetrieveOpportunityFromAPI(details);
        }
    }

    public void OnSuccessfulOpportunityRetrieval(Opportunity opportunity)
    {
        Debug.Log("Opportunity Retrieved");
    }

    public void OnOpportunityPrepared()
    {
        playButton.SetActive(true);
    }

    public void OnOpportunityComplete(string token, Opportunity opp)
    {
        timerText.text = "";
        timerText.gameObject.SetActive(false);
        stopButton.SetActive(false);
        adDisplay.SetActive(false);
    }

    public void PlayAd()
    {
        adDisplay.SetActive(true);

        if(Bridge.Instance)
        {
            Bridge.Instance.PlayOpportunity();
        }
    }

    public void OnOpportunityStart(string token, Opportunity opportunity)
    {
        timerText.gameObject.SetActive(true);
        playButton.SetActive(false);
        stopButton.SetActive(true);
    }

    public void StopAd(int reason)
    {
        if(Bridge.Instance)
        {
            Bridge.Instance.StopOpportunity(reason);
        }
        adDisplay.SetActive(false);
        playButton.SetActive(true);
        stopButton.SetActive(false);
    }

    public void DebugError(string error)
    {
        Debug.Log(error);
    }
}

