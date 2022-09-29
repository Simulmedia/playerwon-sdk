using System;
using UnityEngine.Events;

namespace PlayerWON
{
    [Serializable]
    internal class AuthorizationSuccessful : UnityEvent<string>
    {

    }

    [Serializable]
    internal class OpportunityEvent<Opportunity> : UnityEvent<Opportunity>
    {

    }

    [Serializable]
    internal class StartEvent<Opportunity> : UnityEvent<string, Opportunity>
    {

    }

    [Serializable]
    internal class CompleteEvent<Opportunity> : UnityEvent<string, Opportunity>
    {

    }

    [Serializable]
    internal class ProgressEvent<Opportunity, int32> : UnityEvent<string, Opportunity, int32>
    {

    }

    [Serializable]
    internal class AbortEvent<Opportunity, String, int32> : UnityEvent<string, Opportunity, String, int32>
    {

    }
}
