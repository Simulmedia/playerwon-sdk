using System;
using System.Text;
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Video;
using UnityEngine.Events;

namespace PlayerWON
{
    [RequireComponent(typeof(VideoPlayer))]
    public class Bridge : MonoBehaviour
    {
        internal const string SDK_VERSION = "0.1.0";
        internal static Guid sdkGuid = Guid.NewGuid();

        #region Singleton
        private static Bridge instance;
        public static Bridge Instance { get { return instance; } }
        #endregion

        #region General

        [Header("General")]

        [SerializeField, Tooltip("If you want the same instance of the PlayerWON Asset to live from scene to scene - set to true.  Default: false.")]
        private bool dontDestroyOnLoad;

        [SerializeField, Tooltip("If true, sends crash reports, event logs, and other telemetry data to PlayerWON")]
        private bool sendPlayerWONTelemetry = true;

        #endregion

        #region References

        [Header("Mandatory References")]

        [SerializeField]
        private RenderTexture renderTexture;

        private VideoPlayer videoPlayer;
        public VideoPlayer VideoPlayer { get { return videoPlayer; } }


        #endregion

        #region API Events

        [Header("API Events")]

        [SerializeField, Tooltip("Event that is invoked when Authorization has been achieved")]
        private AuthorizationSuccessful authorizationSuccessful = new AuthorizationSuccessful();

        /// <summary>
        /// Subscribes to the AuthorizationSuccessful event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToAuthorizationSuccessful(UnityAction<string> callback)
        {
            authorizationSuccessful.AddListener(callback);
        }
        /// <summary>
        /// Unsubscribes from the AuthorizationSuccessful event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToAuthorizationSuccessful(UnityAction<string> callback)
        {
            authorizationSuccessful.RemoveListener(callback);
        }

        [SerializeField, Tooltip("Event that is called when an opportunity has been retrieved from the API")]
        private OpportunityEvent<Opportunity> opportunityEvent = new OpportunityEvent<Opportunity>();

        /// <summary>
        /// Subscribes to the OpportunityEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToOpportunityEvent(UnityAction<Opportunity> callback)
        {
            opportunityEvent.AddListener(callback);
        }
        /// <summary>
        /// Unsubscribes from the OpportunityEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToOpportunityEvent(UnityAction<Opportunity> callback)
        {
            opportunityEvent.RemoveListener(callback);
        }

        [SerializeField, Tooltip("When the opportunity has started.")]
        private StartEvent<Opportunity> startEvent = new StartEvent<Opportunity>();

        /// <summary>
        /// Subscribes to the StartEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToStartEvent(UnityAction<string, Opportunity> callback)
        {
            startEvent.AddListener(callback);
        }
        /// <summary>
        /// Unubscribes from the StartEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToStartEvent(UnityAction<string, Opportunity> callback)
        {
            startEvent.RemoveListener(callback);
        }

        [SerializeField, Tooltip("The progress of the current opportunity playback.  Invoked at 25%, 50%, and 75%")]
        private ProgressEvent<Opportunity, int> progressEvent = new ProgressEvent<Opportunity, int>();

        /// <summary>
        /// Subscribes to the ProgressEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToProgressEvent(UnityAction<string, Opportunity, int> callback)
        {
            progressEvent.AddListener(callback);
        }
        /// <summary>
        /// Unsubscribes from the ProgressEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToProgressEvent(UnityAction<string, Opportunity, int> callback)
        {
            progressEvent.RemoveListener(callback);
        }

        [SerializeField, Tooltip("When the opportunity has completed.")]
        private CompleteEvent<Opportunity> completeEvent = new CompleteEvent<Opportunity>();

        /// <summary>
        /// Subscribes to the CompleteEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToCompleteEvent(UnityAction<string, Opportunity> callback)
        {
            completeEvent.AddListener(callback);
        }
        /// <summary>
        /// Unsubscribes from the CompleteEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToCompleteEvent(UnityAction<string, Opportunity> callback)
        {
            completeEvent.RemoveListener(callback);
        }

        [SerializeField, Tooltip("If the opportunity has been aborted.")]
        private AbortEvent<Opportunity, string, int> abortEvent = new AbortEvent<Opportunity, string, int>();

        /// <summary>
        /// Subscribes to the AbortEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToAbortEvent(UnityAction<string, Opportunity, string, int> callback)
        {
            abortEvent.AddListener(callback);
        }
        /// <summary>
        /// Unsubscribes from the AbortEvent event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeToAbortEvent(UnityAction<string, Opportunity, string, int> callback)
        {
            abortEvent.RemoveListener(callback);
        }

        #endregion

        #region Video Events

        [Header("Video Events")]

        [SerializeField, Tooltip("Event that is invoked when the VideoPlayer has been prepared with the ad.")]
        private UnityEvent videoPrepared = new UnityEvent();

        /// <summary>
        /// Subscribes to the VideoPrepared event
        /// </summary>
        /// <param name="callback"></param>
        public void SubscribeToVideoPrepared(UnityAction callback)
        {
            videoPrepared.AddListener(callback);
        }

        /// <summary>
        /// Unsubscribes from the VideoPrepared event
        /// </summary>
        /// <param name="callback"></param>
        public void UnsubscribeFromVideoPrepared(UnityAction callback)
        {
            videoPrepared.RemoveListener(callback);
        }

        #endregion

        #region Error Handling

        [Header("Error Handling")]

        [SerializeField, Tooltip("Event to handle errors on the API's side.  Tie functionality into the event.")]
        private ErrorHandler errorHandler = new ErrorHandler();

        #endregion

        #region Private Members
        private string authToken;
        private ClientDetails clientDetails;
        private Opportunity opportunity;
        private bool quarterInvoked, halfInvoked, threeQuartersInvoked;
        #endregion

        #region Unity Methods

        private void OnEnable()
        {
            if (videoPlayer == null)
            {
                videoPlayer = GetComponent<VideoPlayer>();
            }
            if (videoPlayer)
            {
                videoPlayer.source = VideoSource.Url;
                videoPlayer.isLooping = false;
                videoPlayer.playOnAwake = false;
                videoPlayer.prepareCompleted += OnVideoPlayerPrepared;
                videoPlayer.started += OnVideoStart;
                videoPlayer.loopPointReached += OnVideoCompleted;
                if (renderTexture)
                {
                    videoPlayer.targetTexture = renderTexture;
                }
                if (videoPlayer.targetTexture)
                {
                    videoPlayer.targetTexture.Release();
                }
            }

            authorizationSuccessful.AddListener(OnAuthorization);
            opportunityEvent.AddListener(PrepareOpportunity);
            startEvent.AddListener(OpportunityHasStarted);
            progressEvent.AddListener(OpportunityInProgress);
            completeEvent.AddListener(OpportunityHasCompleted);
            abortEvent.AddListener(OpportunityHasAborted);

            FlipQuarterFlagsTo(false);
        }
        private void OnDisable()
        {
            if (videoPlayer)
            {
                videoPlayer.prepareCompleted -= OnVideoPlayerPrepared;
                videoPlayer.started -= OnVideoStart;
                videoPlayer.loopPointReached -= OnVideoCompleted;
                if (videoPlayer && videoPlayer.targetTexture)
                {
                    videoPlayer.targetTexture.Release();
                }
            }

            authorizationSuccessful.RemoveListener(OnAuthorization);
            opportunityEvent.RemoveListener(PrepareOpportunity);
            startEvent.RemoveListener(OpportunityHasStarted);
            progressEvent.RemoveListener(OpportunityInProgress);
            completeEvent.RemoveListener(OpportunityHasCompleted);
            abortEvent.RemoveListener(OpportunityHasAborted);

            FlipQuarterFlagsTo(false);
        }
        private void Awake()
        {
            if (instance != null && instance != this)
            {
                errorHandler.InvokeError(String.Format("There is already a PlayerWON.Bridge present in the scene. {0} is being destroyed.", gameObject.name));
                Destroy(gameObject);
                return;
            }
            instance = this;

            if (dontDestroyOnLoad)
            {
                DontDestroyOnLoad(gameObject);
            }

            videoPlayer = GetComponent<VideoPlayer>();
        }
        private void Update()
        {
            if (videoPlayer.isPlaying)
            {
                CheckOpportunityProgress();
            }
        }

        #endregion

        #region Opportunity Controls

        /// <summary>
        /// Plays the opportunity
        /// </summary>
        public void PlayOpportunity()
        {
            if (videoPlayer.isPrepared)
            {
                videoPlayer.Play();
                FlipQuarterFlagsTo(false);
            }
        }

        /// <summary>
        /// Stops/Aborts the opportunity playback
        /// </summary>
        /// <param name="reason"></param>
        public void StopOpportunity(int reason)
        {
            int time = (int)videoPlayer.time;
            videoPlayer.Stop();
            videoPlayer.targetTexture.Release();
            OpportunityAbortReasons r = (OpportunityAbortReasons)reason;
            abortEvent.Invoke(authToken, opportunity, r.ToString(), time);
            FlipQuarterFlagsTo(false);
            PrepareOpportunity(opportunity);
        }

        #endregion

        #region Public Methods

        /// <summary>
        /// Provides useful initializing telemetry
        /// </summary>
        /// <param name="idfa">Unique identifier (not GamerTag) for the player</param>
        /// <param name="unity_ver">The version of Unity the game is running on</param>
        /// <param name="gametitle_id">The title of the game</param>
        public void Init(string idfa, string unity_ver, string gametitle_id)
        {
            InitializedMessage initMessage = new InitializedMessage(MessageType.init, idfa, SDK_VERSION, unity_ver, gametitle_id, sdkGuid.ToString(), "Bridge initialized");
            StartCoroutine(errorHandler.SendTelemetry(initMessage));
        }

        /// <summary>
        /// Starts the coroutine that makes the /session API call
        /// Sets the AuthorizationToken if the internal reference has not yet been set
        /// </summary>
        /// <param name="details"></param>
        /// <param name="token"></param>
        public void CallSession(SessionDetails details, string token = null)
        {
            if (token == null && authToken == null)
            {
                string error = "CallSession() : AuthorizationToken is null.  No AuthorizationToken has been found internally";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            if (details == null)
            {
                string error = "CallSession() : SessionDetails is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (authToken == null)
            {
                authToken = token;
            }

            StartCoroutine(POSTSession(authToken, details));
        }

        /// <summary>
        /// Authorizes the client/player to recieve ads.
        /// </summary>
        /// <param name="serverURL"></param>
        public void AuthorizeClient(string serverURL)
        {
            StartCoroutine(GetAuthorization(serverURL));
        }

        /// <summary>
        /// Starts the coroutine that makes the /opportunity API call
        /// Will set the internal reference for ClientDetails if it has not already been set
        /// </summary>
        /// <param name="clientDetails"></param>
        public void RetrieveOpportunityFromAPI(ClientDetails details = null)
        {
            if (details == null && clientDetails == null)
            {
                string error = "RetrieveOpportunityFromAPI() : ClientDetails is null.  No ClientDetails have been found internally.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (clientDetails == null)
            {
                clientDetails = details;
            }
            StartCoroutine(GetOpportunities(authToken, clientDetails));
        }

        /// <summary>
        /// Sets the ClientDetails
        /// Can be done via RetrieveOpportunityFromAPI method
        /// </summary>
        /// <param name="details"></param>
        public void SetClientDetails(ClientDetails details)
        {
            if (details == null)
            {
                string error = "SetClientDetails() : ClientDetails is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            clientDetails = details;
        }

        /// <summary>
        /// Method that returns a floored float representation of the time left in the opportunity based on the current time of the playback and the length of the ad used
        /// e.g. a value of 2.5 will return 2
        /// </summary>
        /// <returns></returns>
        public float TimeLeftInOpportunityFloored()
        {
            if(!videoPlayer.isPrepared)
            {
                string error = "Video Player is not prepared yet, cannot calculate time left in opportunity.";
                errorHandler.InvokeError(error);
                if(sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return 0.0f;
            }

            return Mathf.Floor((float)videoPlayer.length - (float)videoPlayer.time);
        }

        /// <summary>
        /// Method that returns the raw float representation of how much time is left in the opportunity playback
        /// </summary>
        /// <returns></returns>
        public float TimeLeftInOpportunityRaw()
        {
            if (!videoPlayer.isPrepared)
            {
                string error = "Video Player is not prepared yet, cannot calculate time left in opportunity.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return 0.0f;
            }

            return (float)videoPlayer.length - (float)videoPlayer.time;
        }

        #endregion

        #region Callback Handling

        /// <summary>
        /// Listener that is fired upon successful Authorization
        /// </summary>
        /// <param name="token"></param>
        private void OnAuthorization(string token)
        {
            if (token == null)
            {
                string error = "OnAuthorization() : AuthorizationToken is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            authToken = token;
        }

        /// <summary>
        /// Make sure the VideoPlayer has the necessary settings and prepare the video
        /// </summary>
        /// <param name="opp"></param>
        private void PrepareOpportunity(Opportunity opp)
        {
            if (opp == null)
            {
                string error = "PrepareOpportunity() : Opportunity is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            opportunity = opp;
            videoPlayer.url = opportunity.CreativeURL;
            videoPlayer.Prepare();
        }

        /// <summary>
        /// Listener that fires when the VideoPlayer has prepared the video to play
        /// </summary>
        /// <param name="player"></param>
        private void OnVideoPlayerPrepared(VideoPlayer player)
        {
            videoPrepared.Invoke();
        }

        /// <summary>
        /// Listener that fires when the VideoPlayer has started its playback
        /// </summary>
        /// <param name="player"></param>
        private void OnVideoStart(VideoPlayer player)
        {
            startEvent.Invoke(authToken, opportunity);
        }

        /// <summary>
        /// Listener the fires when the VideoPlayer has completed its playback
        /// </summary>
        /// <param name="player"></param>
        private void OnVideoCompleted(VideoPlayer player)
        {
            completeEvent.Invoke(authToken, opportunity);
            videoPlayer.targetTexture.Release();
            FlipQuarterFlagsTo(false);
            RetrieveOpportunityFromAPI();
        }

        /// <summary>
        /// Starts the coroutine that makes the /start API call.
        /// </summary>
        /// <param name="authToken"></param>
        /// <param name="opportunity"></param>
        private void OpportunityHasStarted(string token, Opportunity opp)
        {
            if (token == null)
            {
                string error = "OpportunityHasStarted() : AuthorizationToken is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            if (opp == null)
            {
                string error = "OpportunityHasStarted() : Opportunity is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (authToken == null)
            {
                authToken = token;
            }
            if (opportunity == null)
            {
                opportunity = opp;
            }

            StartCoroutine(PUTOpportunityStart(authToken, opportunity));
        }

        /// <summary>
        /// Starts the coroutine that makes the /progress API call
        /// </summary>
        /// <param name="authToken"></param>
        /// <param name="opportunity"></param>
        /// <param name="percentageComplete"></param>
        private void OpportunityInProgress(string token, Opportunity opp, int percentageComplete)
        {
            if (token == null)
            {
                string error = "OpportunityInProgress() : AuthorizationToken is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            if (opp == null)
            {
                string error = "OpportunityInProgress() : Opportunity is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (authToken == null)
            {
                authToken = token;
            }
            if (opportunity == null)
            {
                opportunity = opp;
            }

            StartCoroutine(PUTOpportunityProgress(authToken, opportunity, percentageComplete));
        }

        /// <summary>
        /// Starts the coroutine that makes the /completed API call
        /// </summary>
        /// <param name="token"></param>
        /// <param name="opportunity"></param>
        private void OpportunityHasCompleted(string token, Opportunity opp)
        {
            if (token == null)
            {
                string error = "OpportunityHasCompleted() : AuthorizationToken is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            if (opp == null)
            {
                string error = "OpportunityHasCompleted() : Opportunity is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (authToken == null)
            {
                authToken = token;
            }
            if (opportunity == null)
            {
                opportunity = opp;
            }

            StartCoroutine(PUTOpportunityComplete(authToken, opportunity));
        }

        /// <summary>
        /// Starts the coroutine that makes the /abort API call
        /// </summary>
        /// <param name="authToken"></param>
        /// <param name="opportunity"></param>
        /// <param name="reasonForAbort"></param>
        /// <param name="secondsAtAbort"></param>
        private void OpportunityHasAborted(string token, Opportunity opp, string reasonForAbort, int secondsAtAbort)
        {
            if (token == null)
            {
                string error = "OpportunityHasAborted() : AuthorizationToken is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }
            if (opp == null)
            {
                string error = "OpportunityHasAborted() : Opportunity is null.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            if (authToken == null)
            {
                authToken = token;
            }
            if (opportunity == null)
            {
                opportunity = opp;
            }

            StartCoroutine(PUTOpportunityAbort(authToken, opportunity, reasonForAbort, secondsAtAbort));
        }

        #endregion

        #region Coroutine HTTP Requests


        /// <summary>
        /// Session API call
        /// </summary>
        /// <param name="token"></param>
        /// <param name="clientDetails"></param>
        /// <returns></returns>
        private IEnumerator POSTSession(string token, SessionDetails sessionDetails)
        {
            string sessionDetailJson = JsonUtility.ToJson(sessionDetails);
            string opportunityURL = "https://game.simulmedia-apis.com/session";

            string authString = token;

            using (UnityWebRequest request = new UnityWebRequest(opportunityURL, "POST"))
            {
                byte[] bodyRaw = Encoding.UTF8.GetBytes(sessionDetailJson);
                request.uploadHandler = (UploadHandler)new UploadHandlerRaw(bodyRaw);
                request.downloadHandler = (DownloadHandler)new DownloadHandlerBuffer();
                request.SetRequestHeader("Content-Type", "application/json");
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }
            }
        }


        /// <summary>
        /// Requests authorization from the API
        /// </summary>
        /// <param name="serverURL"></param>
        /// <returns></returns>
        private IEnumerator GetAuthorization(string serverURL)
        {
            using (UnityWebRequest request = new UnityWebRequest(serverURL, "POST"))
            {
                request.downloadHandler = (DownloadHandler)new DownloadHandlerBuffer();

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }

                authToken = "Bearer" + " " + request.downloadHandler.text;
                if (authToken == null)
                {
                    string error = "GetAuthorization() : AuthorizationToken could not be loaded from API.";
                    errorHandler.InvokeError(error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }

                authorizationSuccessful.Invoke(authToken);
            }
        }

        /// <summary>
        /// Coroutine to retreive an opportunity from the API
        /// </summary>
        /// <param name="authToken"></param>
        /// <param name="clientDetails"></param>
        /// <returns></returns>
        private IEnumerator GetOpportunities(string token, ClientDetails clientDetails)
        {
            string clientDetailsJson = JsonUtility.ToJson(clientDetails);
            string opportunityURL = "https://game.simulmedia-apis.com/opportunity";

            string authString = token;

            using (UnityWebRequest request = new UnityWebRequest(opportunityURL, "POST"))
            {
                byte[] bodyRaw = Encoding.UTF8.GetBytes(clientDetailsJson);
                request.uploadHandler = (UploadHandler)new UploadHandlerRaw(bodyRaw);
                request.downloadHandler = (DownloadHandler)new DownloadHandlerBuffer();
                request.SetRequestHeader("Content-Type", "application/json");
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }

                OpportunityWrapper opportunity = new OpportunityWrapper();
                JsonUtility.FromJsonOverwrite(request.downloadHandler.text, opportunity);
                if (opportunity == null)
                {
                    string error = "GetOpportunities() : Opportunity could not be loaded from API.";
                    errorHandler.InvokeError(error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }

                opportunityEvent.Invoke(opportunity.GetOpportunity());
            }
        }

        /// <summary>
        /// Coroutine to tell the API that the opportunity has started playing
        /// </summary>
        /// <param name="token"></param>
        /// <param name="opportunity"></param>
        /// <returns></returns>
        private IEnumerator PUTOpportunityStart(string token, Opportunity opportunity)
        {
            string startURL = "https://game.simulmedia-apis.com/start/" + opportunity.Receipt;
            string authString = token;

            using (UnityWebRequest request = UnityWebRequest.Put(startURL, authString))
            {
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }
            }
        }

        /// <summary>
        /// Coroutine to tell the API that the opportunity has played until completion
        /// </summary>
        /// <param name="token"></param>
        /// <param name="opportunity"></param>
        /// <returns></returns>
        private IEnumerator PUTOpportunityComplete(string token, Opportunity opportunity)
        {
            string completeURL = "https://game.simulmedia-apis.com/complete/" + opportunity.Receipt;
            string authString = token;

            using (UnityWebRequest request = UnityWebRequest.Put(completeURL, authString))
            {
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }
            }
        }

        /// <summary>
        /// Coroutine to tell the API what progress the opportunity playback is at.  Done in Quarter intervals
        /// </summary>
        /// <param name="token"></param>
        /// <param name="opportunity"></param>
        /// <param name="percentageOfVideoProgress"></param>
        /// <returns></returns>
        private IEnumerator PUTOpportunityProgress(string token, Opportunity opportunity, int percentageOfVideoProgress)
        {
            string progressURL = "https://game.simulmedia-apis.com/progress/" + opportunity.Receipt + "?p=" + percentageOfVideoProgress;
            string authString = token;

            using (UnityWebRequest request = UnityWebRequest.Put(progressURL, authString))
            {
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }
            }
        }

        /// <summary>
        /// Coroutine to tell the API that the opportunity playback has been abort at a specific time stamp and why
        /// </summary>
        /// <param name="token"></param>
        /// <param name="opportunity"></param>
        /// <param name="reasonForAbort"></param>
        /// <param name="secondsIntoVideo"></param>
        /// <returns></returns>
        private IEnumerator PUTOpportunityAbort(string token, Opportunity opportunity, string reasonForAbort, int secondsIntoVideo)
        {
            string abortURL = "https://game.simulmedia-apis.com/abort/" + opportunity.Receipt + "?reason=" + reasonForAbort + "&t=" + secondsIntoVideo;
            string authString = token;

            using (UnityWebRequest request = UnityWebRequest.Put(abortURL, authString))
            {
                request.SetRequestHeader("Authorization", authString);

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    errorHandler.InvokeError(request.error);
                    if (sendPlayerWONTelemetry)
                    {
                        GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), request.error, StackTraceUtility.ExtractStackTrace());
                        StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                    }
                    yield break;
                }
            }
        }

        #endregion

        #region Helpers

        /// <summary>
        /// Checks the progress of the VideoPlayer playback
        /// </summary>
        private void CheckOpportunityProgress()
        {
            if (videoPlayer.frameCount <= 0)
            {
                string error = "FrameCount <= 0.  No video can be played.";
                errorHandler.InvokeError(error);
                if (sendPlayerWONTelemetry)
                {
                    GeneralMessage errorMessage = new GeneralMessage(MessageType.error, sdkGuid.ToString(), error, StackTraceUtility.ExtractStackTrace());
                    StartCoroutine(errorHandler.SendTelemetry(errorMessage));
                }
                return;
            }

            float percentage = GetProgressPercentage((float)videoPlayer.frame, (float)videoPlayer.frameCount);
            if (percentage >= 25 && percentage < 50 && !quarterInvoked)
            {
                progressEvent.Invoke(authToken, opportunity, 25);
                quarterInvoked = true;
            }
            else if (percentage >= 50 && percentage < 75 && !halfInvoked)
            {
                progressEvent.Invoke(authToken, opportunity, 50);
                halfInvoked = true;
            }
            else if (percentage >= 75 && percentage < 100 && !threeQuartersInvoked)
            {
                progressEvent.Invoke(authToken, opportunity, (75);
                threeQuartersInvoked = true;
            }
        }

        /// <summary>
        /// Converts the frame counts into a percentage
        /// </summary>
        /// <param name="curr"></param>
        /// <param name="max"></param>
        /// <returns></returns>
        private float GetProgressPercentage(float curr, float max)
        {
            return (curr / max) * 100;
        }

        /// <summary>
        /// Flips the flags used to make sure the 25, 50, and 75 % events are only fired once
        /// </summary>
        /// <param name="value"></param>
        private void FlipQuarterFlagsTo(bool value)
        {
            quarterInvoked = value;
            halfInvoked = value;
            threeQuartersInvoked = value;
        }
        #endregion
    }
}

