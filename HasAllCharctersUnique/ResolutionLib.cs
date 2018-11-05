using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ArrayAndStrings
{
    public interface ISolutionLib
    {
        bool HasAllCharacters_1_1(string text);
        void ReverseStr_1_2(string str);
    }

    public class SolutionLib : ISolutionLib
    {
        //1.1 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures?
        public bool HasAllCharacters_1_1(string text)
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
        public void ReverseStr_1_2(string str)
        {
            for (int i = (str.Length - 1); i >= 0; i--)
            {
                Console.Write(str[i]);
            }
        }
    }
}
