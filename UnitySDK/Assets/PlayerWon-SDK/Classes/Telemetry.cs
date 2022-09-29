using System;
using System.Text;
using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.Networking;

namespace PlayerWON
{
    [Serializable]
    public class ErrorHandler
    {
        [SerializeField]
        private UnityEvent<string> error = new UnityEvent<string>();
        internal UnityEvent<string> Error { get { return error; } }

        public void InvokeError(string errorMessage)
        {
            error.Invoke(errorMessage);
        }

        internal IEnumerator SendTelemetry(ITelemetryMessage message)
        {
            string messageJson = JsonUtility.ToJson(message);
            string telemetryURL = "https://game.simulmedia-apis.com/sdk/telemetry";

            using (UnityWebRequest request = new UnityWebRequest(telemetryURL, "POST"))
            {
                byte[] bodyRaw = Encoding.UTF8.GetBytes(messageJson);
                request.uploadHandler = (UploadHandler)new UploadHandlerRaw(bodyRaw);
                request.downloadHandler = (DownloadHandler)new DownloadHandlerBuffer();
                request.SetRequestHeader("Content-Type", "application/json");

                yield return request.SendWebRequest();

                if (request.result != UnityWebRequest.Result.Success)
                {
                    //TODO: I'm hesitant to catch this error with the same coroutine.
                    //Seems like a good way to get an infinite loop
                    yield break;
                }
            }
        }
    }

    [Serializable]
    internal class GeneralMessage : ITelemetryMessage
    {
        [SerializeField]
        private string type;

        [SerializeField]
        private string sdk_id;

        [SerializeField]
        private string message;

        [SerializeField]
        private string stack_trace;

        public GeneralMessage(MessageType _type, string _sdk_id, string _message, string _stack_trace = null)
        {
            type = _type.ToString();
            sdk_id = _sdk_id;
            message = _message;
            stack_trace = _stack_trace;
        }
    }

    [Serializable]
    internal class InitializedMessage : ITelemetryMessage
    {
        [SerializeField]
        private string type;

        [SerializeField]
        private string idfa;

        [SerializeField]
        private string pw_sdk_ver;

        [SerializeField]
        private string engine_ver;

        [SerializeField]
        private string gametitle_id;

        [SerializeField]
        private string sdk_id;

        [SerializeField]
        private string message;

        public InitializedMessage(MessageType _type, string _idfa, string _pw_sdk_ver, string _unity_ver, string _gametitle_id, string _sdk_id, string _message = null)
        {
            type = _type.ToString();
            idfa = _idfa;
            pw_sdk_ver = _pw_sdk_ver;
            engine_ver = "Unity " + _unity_ver;
            gametitle_id = _gametitle_id;
            sdk_id = _sdk_id;
            message = _message;
        }
    }

    internal interface ITelemetryMessage
    {

    }

    internal enum MessageType
    {
        error,
        init,
        auth
    }
}
