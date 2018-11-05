using System;
using System.Linq;

namespace HasAllCharctersUnique
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("1.1");
            var r = HasAllCharacters("AAAAAABCDEFGHIJLMNOPQRSTUVWXYZZZZZ");
            Console.WriteLine(r);

            Console.WriteLine("1.2");
            ReverseStr("sercan");

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

        //1.2 Write code to reverse a C-Style String(C-String means that “abcd” is represented as five characters, including the null character )
        public static void ReverseStr(string str)
        {
            for (int i = (str.Length-1); i >= 0; i--)
            {
                Console.Write(str[i]);
            }
        }
    }
}
