using UnityEngine;

namespace PlayerWON
{
    public class SessionDetails
    {
        [SerializeField]
        private string country;

        [SerializeField]
        private string plat;

        [SerializeField]
        private string lang;

        [SerializeField]
        private string pid;

        [SerializeField]
        private string pid_type;

        [SerializeField]
        private string device;

        [SerializeField]
        private int coppa;

        [SerializeField]
        private int underage;

        [SerializeField]
        private int age;

        [SerializeField]
        private int min_age;

        [SerializeField]
        private int max_age;

        [SerializeField]
        private Gender gg;

        [SerializeField]
        private int ls;

        [SerializeField]
        private Currency lsv;

        [SerializeField]
        private string psd;

        [SerializeField]
        private int gs;

        [SerializeField]
        private int lt;

        [SerializeField]
        private int gdpr;

        [SerializeField]
        private int gdpr_consent;

        private SessionDetails(string _country, string _plat, string _lang, string _pid = null, string _pid_type = null, string _device = null, int _coppa = 0,
            int _underage = 0, int _age = 0, int _min_age = 0, int _max_age = 0, Gender _gg = Gender.n, int _ls = 0, Currency _lsv = null,
            string _psd = null, int _gs = 0, int _lt = 0, int _gdpr = 0, int _gdpr_consent = 0)
        {
            country = _country;
            plat = _plat;
            lang = _lang;
            pid = _pid;
            pid_type = _pid_type;
            device = _device;
            coppa = _coppa;
            underage = _underage;
            age = _age;
            min_age = _min_age;
            max_age = _max_age;
            gg = _gg;
            ls = _ls;
            lsv = _lsv;
            psd = _psd;
            gs = _gs;
            lt = _lt;
            gdpr = _gdpr;
            gdpr_consent = _gdpr_consent;
        }

        /// <summary>
        /// Constructor for Session Details
        /// </summary>
        /// <param name="_country">The player/client's country</param>
        /// <param name="_plat">The platform the player/client is on</param>
        /// <param name="_lang">The language the player/client is using</param>
        /// <param name="_pid">Player GamerTag</param>
        /// <param name="_pid_type">The type of GamerTag</param>
        /// <param name="_device">The player/client's device name</param>
        /// <param name="_coppa">COPPA, Players/Clients above 13 are marked as 0, Players/Clients below are marked as 1</param>
        /// <param name="_underage">Is the player/client underage</param>
        /// <param name="_age">Player/Client's age</param>
        /// <param name="_min_age">Minimum age this player/client can be</param>
        /// <param name="_max_age">Maximum age this player/client can be</param>
        /// <param name="_gg">Player/Client's gender</param>
        /// <param name="_ls">Lifetime Spending. 1 indicates the player/client has made in-game purchases with real money</param>
        /// <param name="_lsv">Lifetime Spend value</param>
        /// <param name="_psd">The date the player first played the game</param>
        /// <param name="_gs">Is this on the game server?</param>
        /// <param name="_lt">Limit tracking. 1 indicates the player/client has opted for limited ad tracking</param>
        /// <param name="_gdpr">GDPR. 1 indicates player/client is in a country under GDPR jurisdiction</param>
        /// <param name="_gdpr_consent">GDPR consent. 1 indicates player/client has given consent. Only valid if _gdpr is 1</param>
        public SessionDetails(SupportedCountries _country, PlatformType _plat, SupportedLanguages _lang, string _pid = "Unknown", PlayerIDType _pid_type = PlayerIDType.Steam, string _device = "Unknown", int _coppa = 0,
            int _underage = 0, int _age = 18, int _min_age = 0, int _max_age = 100, Gender _gg = Gender.n, int _ls = 0, Currency _lsv = null,
            string _psd = null, int _gs = 0, int _lt = 0, int _gdpr = 0, int _gdpr_consent = 0)
            : this(DataLibrary.CountryDictionary[_country], DataLibrary.PlatformDictionary[_plat], DataLibrary.LanguageDictionary[_lang], _pid, DataLibrary.IDTypeDictionary[_pid_type],
                 _device, _coppa, _underage, _age, _min_age, _max_age, _gg, _ls, _lsv, _psd, _gs, _lt, _gdpr, _gdpr_consent)
        {

        }
    }
}
