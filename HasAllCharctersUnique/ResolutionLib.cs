using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ArrayAndStrings
{
    public interface ISolutionLib
    {
        bool IsUniqueAllChars_1_1(string text);
        void ReverseStr_1_2(string str);
        string RemoveDuplicateChars_1_3(string text);
    }

    public class SolutionLib : ISolutionLib
    {
        //1.1 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures?
        public bool IsUniqueAllChars_1_1(string text)
        {
            bool[] chars = new bool[256];

            foreach (char chr in text)
            {
                int asciiCode = (int)chr;
                if (chars[asciiCode])
                {
                    return false;
                }

                chars[asciiCode] = true;
            }

            return true;
        }

        //1.2 Write code to reverse a C-Style String(C-String means that “abcd” is represented as five characters, including the null character )
        public void ReverseStr_1_2(string str)
        {
            for (int i = (str.Length - 1); i >= 0; i--)
            {
                Console.Write(str[i]);
            }

            Console.WriteLine();
        }

        // 1.3 
        // Design an algorithm and write code to remove the duplicate characters in a string without using any additional buﬀer NOTE: One or two additional variables are fne
        // An extra copy of the array is not
        // FOLLOW UP
        // Write the test cases for this method
        public string RemoveDuplicateChars_1_3(string text)
        {
            int charLength = text.Length - 1;
            int currentIndex=0;

            for (int i = 0; i < charLength; i++)
            {
                char currentChar = text[i];
                for (int j = i + 1; j < charLength; j++)
                {
                    char comparingChar = text[j];
                    if (currentChar == comparingChar)
                    {
                        break;
                    }

                    currentIndex++;
                }
            }

            return text;
        }
    }
}
