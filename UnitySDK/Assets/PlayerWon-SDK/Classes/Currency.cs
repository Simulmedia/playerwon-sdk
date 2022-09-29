using UnityEngine;
using System.Collections.Generic;

namespace PlayerWON
{
    [System.Serializable]
    public class Currency
    {
        [SerializeField]
        private string cur;

        [SerializeField]
        private int val;

        [SerializeField]
        private int d;

        [SerializeField]
        private int t;

        private Currency(string currency, int value, int digits, int type)
        {
            cur = currency;
            val = value;
            d = digits;
            t = type;
        }

        /// <summary>
        /// Constructor for a currency
        /// </summary>
        /// <param name="currency">The name of the currency</param>
        /// <param name="value">The value of the currency</param>
        /// <param name="digits">The number of digits from the right the decimal should be placed</param>
        /// <param name="type">The currency type</param>
        /// <param name="currencyName">Only needed/used if the name of the currency is set to In_Game, e.g. Gems, Gold, Caps</param>
        public Currency(SupportedCurrencies currency, int value, int digits, CurrencyType type, string currencyName = null)
            : this(currency != SupportedCurrencies.In_Game ? DataLibrary.CurrencyDictionary[currency] : currencyName, value, digits, (int)type)
        {

        }
    }

    [System.Serializable]
    public class CurrencyArray
    {
        public List<Currency> Currencies = new List<Currency>();

        public CurrencyArray(List<Currency> cur)
        {
            Currencies = cur;
        }
        public CurrencyArray() : this(new List<Currency>())
        {

        }
    }
}
