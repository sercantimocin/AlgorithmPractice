// ArrayAndStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>   
#include <cstring> 
using namespace std;

//1.1 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures?
bool isUniqueAllChars_1_1(string text)
{
	bool chars[256] = { false };

	for (int i = 0; i < text.length(); i++)
	{
		int asciiCode = text[i];
		if (chars[asciiCode])
		{
			return false;
		}

		chars[asciiCode] = true;
	}

	return true;
}

//1.2 Write code to reverse a C-Style String(C-String means that “abcd” is represented as five characters, including the null character )
void  reverseStr_1_2(char * str)
{
	char * arrEnd = str;

	while (*arrEnd)
	{
		arrEnd++;
	}

	arrEnd--;
	char temp;

	while (str < arrEnd)
	{
		temp = *str;
		*str++ = *arrEnd;
		*arrEnd-- = temp;
	}
}

// 1.3 
// Design an algorithm and write code to remove the duplicate characters in a string without using any additional buﬀer NOTE: One or two additional variables are fne
// An extra copy of the array is not
// FOLLOW UP
// Write the test cases for this method
string removeDuplicateChars_1_3(string text)
{
	int charLength = text.length() - 1;
	int currentIndex = 1;

	for (int i = 1; i < text.length(); i++)
	{
		char currentChar = text[i];
		int j = 0;
		for (; j < i; j++)
		{
			char comparingChar = text[j];
			if (currentChar == comparingChar)
			{
				break;
			}
		}

		if (j == i)
		{
			text[currentIndex] = text[i];
			currentIndex++;
		}
	}

	text[currentIndex] = 0;

	return text;
}

//1.4 Write a method to decide if two strings are anagrams or not for abc cba
bool isAnagram(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}

	int compareArray[256] = { 0 };

	for (int i = 0; i < s1.length(); i++)
	{
		compareArray[(int)s1[i]]++;
		compareArray[(int)s2[i]]--;
	}

	for (int i = 0; i < 256; i++)
	{
		if (compareArray[i] != 0)
		{
			return false;
		}
	}

	return true;
}

//1.5 Write a method to replace all spaces in a string with ‘%20’
char * replaceEmpty(string str)
{
	int spaceCount = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if ((int)str[i] == 32)
		{
			spaceCount++;
		}
	}

	int newLength = str.length() + (spaceCount * 2);
	char * newStr = new char[newLength];
	int index = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if ((int)str[i] == 32)
		{
			newStr[index++] = '%';
			newStr[index++] = '2';
			newStr[index++] = '0';
		}
		else
		{
			newStr[index++] = str[i];
		}
	}

	newStr[index] = 0;

	return newStr;
}

//1.8 Assume you have a method isSubstring which checks if one word is a substring of
//another.Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
//only one call to isSubstring(i.e., “waterbottle” is a rotation of “erbottlewat”).
bool rotatedContains(string s1, string s2)
{
	if (s1.length()== s2.length())
	{
		string newS1 = s1 + s1;
		return newS1.find(s2) != string::npos;
	}

	return false;
}


int main()
{
	bool r = isUniqueAllChars_1_1("sercan");
	std::cout << "1.1\nResult:";
	std::cout << r;

	std::cout << "\n1.2\nResult:";
	char arr[] = "sercan";
	reverseStr_1_2(arr);
	std::cout << arr;

	std::cout << "\n1.3\nResult:";
	string result = removeDuplicateChars_1_3("sernecsan");
	std::cout << result;

	std::cout << "\n1.4\nResult:";
	r = isAnagram("ece", "cee");
	std::cout << r;

	std::cout << "\n1.5\nResult:";
	result = replaceEmpty("ser can");
	std::cout << result;

	std::cout << "\n1.8\nResult:";
	r = rotatedContains("apple","pleap");
	std::cout << r;

	cin.get();
	return 0;
}


