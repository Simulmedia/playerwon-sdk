using UnityEngine;

namespace PlayerWON
{
    /// <summary>
    /// Client Details class, used to hold details about the client
    /// </summary>
    public class ClientDetails
    {
        [SerializeField]
        private string country;

        [SerializeField]
        private string idfa;

        [SerializeField]
        private string plat;

        [SerializeField]
        private string lang;

        [SerializeField]
        private string ip;

        [SerializeField]
        private int w;

        [SerializeField]
        private int h;

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
        private string slot_id;

        [SerializeField]
        private int ls;

        [SerializeField]
        private Currency lsv;

        [SerializeField]
        private CurrencyArray rv;

        [SerializeField]
        private int gs;

        private ClientDetails(string _country, string _idfa, string _plat, string _lang, string _ip = null, int _w = 0, int _h = 0, string _pid = null, string _pidType = null, string _device = null, int _coppa = 0,
            int _underage = 0, int _age = 0, string _slot_id = null, int _ls = 0, Currency _lsv = null, CurrencyArray _rv = null, int _gs = 0)
        {
            country = _country;
            idfa = _idfa;
            plat = _plat;
            lang = _lang;
            ip = _ip;
            w = _w;
            h = _h;
            pid = _pid;
            pid_type = _pidType;
            device = _device;
            coppa = _coppa;
            underage = _underage;
            age = _age;
            slot_id = _slot_id;
            ls = _ls;
            lsv = _lsv;
            rv = _rv;
            gs = _gs;
        }

        /// <summary>
        /// Client Details Constructor
        /// </summary>
        /// <param name="_country">The player/client's country</param>
        /// <param name="_idfa">The player/client's identification</param>
        /// <param name="_plat">The platform the player/client is on</param>
        /// <param name="_lang">The language the player/client is using</param>
        /// <param name="_ip">The player/client's ip address</param>
        /// <param name="_w">Width in pixels</param>
        /// <param name="_h">Height in pixels</param>
        /// <param name="_pid">Player GamerTag</param>
        /// <param name="_pidType">The type of GamerTag</param>
        /// <param name="_device">The player/client's device name</param>
        /// <param name="_coppa">COPPA, Players/Clients above 13 are marked as 0, Players/Clients below are marked as 1</param>
        /// <param name="_underage">Is the player/client underage</param>
        /// <param name="_age">Player/Client's age</param>
        /// <param name="_slot_id">Game Specific value provided by PlayerWON</param>
        /// <param name="_ls">Lifetime Spending. 1 indicates the player/client has made in-game purchases with real money</param>
        /// <param name="_lsv">Lifetime Spend value</param>
        /// <param name="_rv">The rewards given to the player for watching the ad</param>
        /// <param name="_gs">Is this on the game server?</param>
        public ClientDetails(SupportedCountries _country, string _idfa, PlatformType _plat, SupportedLanguages _lang, string _ip = "127.0.0.1", int _w = 1920, int _h = 1080, string _pid = "Unknown", PlayerIDType _pidType = PlayerIDType.Steam, string _device = "Unknown", int _coppa = 0,
            int _underage = 0, int _age = 18, string _slot_id = "", int _ls = 0, Currency _lsv = null, CurrencyArray _rv = null, int _gs = 0)
            : this(DataLibrary.CountryDictionary[_country], _idfa, DataLibrary.PlatformDictionary[_plat], DataLibrary.LanguageDictionary[_lang], _ip, _w, _h, _pid, DataLibrary.IDTypeDictionary[_pidType],
                  _device, _coppa, _underage, _age, _slot_id, _ls, _lsv, _rv, _gs)
        {

        }
    }
}
