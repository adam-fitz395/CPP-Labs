#include <iostream>
#include <cmath>

using namespace std;

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

	return reverseNum;
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
	if (numbertoTest <= 1)
	{
		return false;
	}

	for (int index = 2; index <= sqrt(numbertoTest); index++)
	{
		if (numbertoTest % index == 0)
		{
			return false;
		}
	}

	return true;
}

int input5CharsConvertToInt() {
	int result = 0;
	char inputChar;
	for (int index = 0; index < 5; index++) {
		std::cin >> inputChar;

		// Check if the character is a digit ('0' to '9' in ASCII)
		if (inputChar >= '0' && inputChar <= '9') {
			// Convert the character to an integer and update the result
			result = result * 10 + (inputChar - '0');
		}
		else {
			// If any character is not a digit, return 0
			return 0;
		}
	}
	return result;
}

int convertBinarytoDecimal(int binaryNumber)
{
	int totalDecimal = 0;
	int base = 1; // Initialize base for binary place value

	while (binaryNumber > 0)
	{
		int remainder = binaryNumber % 10; // Extract the last digit

		if (remainder != 0 && remainder != 1)
		{
			// Handle invalid binary digits
			cout << "Invalid binary digit: " << remainder << endl;
			return -1; // Indicate failure
		}

		totalDecimal += remainder * base; // Calculate decimal value
		base *= 2; // Update the base for the next place value
		binaryNumber /= 10; // Move to the next digit
	}

	return totalDecimal;
}
void drawRightAngledTriangle()
{
	for (int index = 1; index <= 4; index++) 
	{
		for (int jindex = 1; jindex <= index; jindex++) 
		{
			cout << "A";
		}
		cout << endl;
	}
}

void drawIsocelesTriangle()
{
	int index = 0;
	int jindex = 0;
	for (index = 1; index <= 4; index++)
		{
			for (jindex = 1; jindex <= index; jindex++)
			{
				cout << "A";
			}
			cout << endl;
		}

		for (int index = 3; index >= 1; index--) 
		{
			for (jindex = 1; jindex <= index; jindex++) 
			{
				cout << "A";
			}
			cout << endl;
		}
}
void drawIsocelesTriangle2()
{
	int index = 0;
	int jindex = 0;
	for (index = 1; index <= 4; index++)
	{
		for (jindex = 1; jindex <= index; jindex++)
		{
			cout << "A";
		}
		cout << endl;
	}

	for (int index = 3; index >= 1; index--)
	{
		for (jindex = 1; jindex <= index; jindex++)
		{
			cout << "A";
		}
		cout << endl;
	}
}

int find(int size, int arr[], int toFind)
{
		for (int index = 0; index < size; index++)
		{
			if (arr[index] == toFind)
			{
				return arr[index];
			}
		}
		
		return -1;
}
int find2ndLargest(int size, int arr[])
{
	int currentNum = 0;
	int secondLargest = INT_MIN;
	int largest = arr[0];

	for (int index = 0; index < size; index++)
	{
		currentNum = arr[index];

		if (size < 2)
		{
			return -1;
		}

		if (currentNum > largest)
		{
			secondLargest = largest;
			largest = currentNum;
		}
		else if (currentNum > secondLargest && currentNum != largest)
		{
			secondLargest = currentNum;
		}
	}

	if (secondLargest == INT_MIN)
	{
		return -1;
	}

	return secondLargest;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	for (int index = 0; index < size; index++)
	{
		arr2[index] = arr1[index];
	}
}

bool insertElement(int size, int count, int insertArr[], int elementToInsert, int insertIndex)
{
	if (insertIndex < 0 || insertIndex > count) 
	{
		return false;
	}

	for (int i = count; i > insertIndex; i--) 
	{
		insertArr[i] = insertArr[i - 1];
	}

	insertArr[insertIndex] = elementToInsert;

	count++;

	return true;
}

bool deleteElement(int size, int& count, int deleteArr[], int deleteIndex)
{
	if (deleteIndex < 0 || deleteIndex >= count)
	{
		return false; // Index out of bounds
	}

	if (count == 0)
	{
		return false; // Nothing to delete
	}

	for (int index = deleteIndex; index < count - 1; index++)
	{
		deleteArr[index] = deleteArr[index + 1];
	}

	count--; // Decrease the count after successful deletion

	return true;
}

int frequencyCount(int size, int arr[], int value)
{
	int numOfFreq = 0;
	for (int index = 0; index < size - 1; index++)
	{
		if (arr[index] == value)
		{
			numOfFreq++;
		}
	}

	return numOfFreq;
}

int countDuplicates(int size, int arr[])
{
	int numOfDups = 0;

	// Iterate through the array to check for duplicates
	for (int i = 0; i < size; i++)
	{
		// Ignore elements that have been marked as duplicates
		if (arr[i] == -1)
		{
			continue;
		}

		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				// Mark both elements as duplicates
				arr[j] = -1;
				numOfDups++;
			}
		}
	}

	return numOfDups;
}

void reverse(int size, int arr[]) 
{
	int start = 0; // Index of the first element
	int end = size - 1; // Index of the last element

	while (start < end) 
	{
		// Swap elements at start and end
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		// Move towards the center of the array
		start++;
		end--;
	} 
}
int rotateLeft(int size, int arr[])
{
	int temp = 0;
	temp = arr[0];

	for (int index = 0; index < size - 1; index++)
	{
		arr[index] = arr[index + 1];
	}

	arr[size - 1] = temp;
	return 1;

}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	int movieLengthOne = 0;
	int movieLengthTwo = 0;
	for (int index = 0; index < size - 1; index++)
	{
		movieLengthOne = movieLengths[index];
		movieLengthTwo = movieLengths[index + 1];
		if (movieLengthOne + movieLengthTwo == flightLength)
		{
			return true;
		}
	}
	return false;
}

int wordCounter(int size, char characters[])
{
	int wordCount = 0;
	int inWord = 0;

	for (int i = 0; i < size; i++) {
		char c = characters[i];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			wordCount += !inWord;
			inWord = 1;
		}
		else {
			inWord = 0;
		}
	}

	return wordCount;
}