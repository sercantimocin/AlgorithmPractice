using System;
using System.Linq;

namespace HasAllCharctersUnique
{
    class Program
    {
        static void Main(string[] args)
        {
            var r = HasAllCharacters("AAAAAABCDEFGHIJLMNOPQRSTUVWXYZZZZZ");
            Console.WriteLine(r);
            var k = Console.ReadKey();
        }


        //1.1 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures?
        public static bool HasAllCharacters(string text)
        {
            char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();
            char[] existChars = new char[26];

            foreach (char t in text.ToUpper())
            {
                existChars[t % 65] = t;
            }

            return alphabet.SequenceEqual(existChars);
        }
    }
}
