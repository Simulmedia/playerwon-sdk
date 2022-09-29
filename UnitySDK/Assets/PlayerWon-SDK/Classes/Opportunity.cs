using System;
using System.Collections.Generic;
using UnityEngine;

namespace PlayerWON
{
    /// <summary>
    /// Opportunity class handles the determined opportunity from the API
    /// </summary>
    [Serializable]
    public class Opportunity
    {
        [SerializeField]
        private string creativeUrl;

        [SerializeField]
        private int length;

        [SerializeField]
        private string receipt;

        public string CreativeURL { get { return creativeUrl; } }
        public int Length { get { return length; } }
        public string Receipt { get { return receipt; } }
    }

    /// <summary>
    /// OpportunityWrapper is a wrapper for the opportunity class
    /// Opportunities from the API still come in JSON array format so it's handled as a list
    /// </summary>
    [Serializable]
    internal class OpportunityWrapper
    {
        public List<Opportunity> opportunities = new List<Opportunity>();

        public Opportunity GetOpportunity()
        {
            if (OpportunitiesPopulated())
            {
                return opportunities[0];
            }

            return null;
        }
        public string GetVideoURL()
        {
            if (OpportunitiesPopulated())
            {
                return opportunities[0].CreativeURL;
            }
            return String.Empty;
        }

        public bool OpportunitiesPopulated()
        {
            return opportunities.Count > 0;
        }
    }

}
