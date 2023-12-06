#pragma once
#include <iostream>

bool isLeapYear(int year)
{
	if ((year % 4) == 0)
 	{
    	if ((year % 100) == 0)
     	{
        	if ((year % 400) == 0)
        	{
            	return true;
         	}

         	else
         	{
             	return false;
         	}
     	}

     	else
     	{
        	return true;
     	}
 	}

	else
	{
    	return false;
	}
}

int Reversed(int testNumber)
{
	int reverseNum = testNumber;
	int reverseLast = 0;

	while (reverseNum > 0)
	{
		// Get last digit by moding 10 
		int lastDigit = reverseNum % 10;

		// Reverse last digit
		reverseLast = (reverseLast * 10) + lastDigit;

		// Remove last digit from number
		reverseNum = reverseNum / 10;
	}

	if (reverseLast != testNumber)
	{
		return false;
	}
	else
	{
		return true;
	}

}
bool isAPalindrome(int testNumber)
{
	int reverseNum = testNumber;
	int reverseLast = 0;

	if (testNumber < 0)
	{
		return false;
	}

	if (testNumber > 0 && testNumber < 10)
	{
		return true;
	}

	while (reverseNum > 0)
	{
		// Get last digit by moding 10 
		int lastDigit = reverseNum % 10;

		// Reverse last digit
		reverseLast = (reverseLast * 10) + lastDigit;

		// Remove last digit from number
		reverseNum = reverseNum / 10;
	}

	if (reverseLast != testNumber)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool isAPrimeNumber(int numbertoTest)
{
	return false;
}
int input5CharsConvertToInt()
{
	int returnInt = 0;
	char inputChar;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputChar;
		//check if its a digit.
		//do something

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	return 0;
}
void drawRightAngledTriangle()
{

}
void drawIsocelesTriangle()
{

}
void drawIsocelesTriangle2()
{

}

int find(int size, int arr[], int toFind)
{
	return -1;
}
int find2ndLargest(int size, int arr[])
{
	return -1;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	return;
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{

	return false;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{

	return true;
}
int frequencyCount(int size, int arr[], int value)
{

	return 0;
}
int countDuplicates(int size, int arr[])
{

	return 0;
}
void reverse(int size, int arr[])
{
	return;
}
int rotateLeft(int size, int arr[])
{
	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	return false;
}
int wordCounter(int size, char characters[])
{
	return 0;
}