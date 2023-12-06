#include "functions.h"
// Test for Questions 1 to 8
using namespace std;

void printArray(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Leapyear" << endl;
	if (!isLeapYear(1700))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (isLeapYear(1600))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (isLeapYear(2016))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	cout << "NumberReversed" << endl;
	if (Reversed(123) == 321)
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	if (Reversed(1) == 1)
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (Reversed(1234) != 321)
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "Palindrome" << endl;
	if (isAPalindrome(1))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (isAPalindrome(121))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (!isAPalindrome(1213))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	cout << "Prime Number" << endl;
	if (isAPrimeNumber(3))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (isAPrimeNumber(2147483647))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (!isAPrimeNumber(4))
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	cout << "Binary to Decimal" << endl;
	if (convertBinarytoDecimal(110) == 6)
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	if (convertBinarytoDecimal(111) == 7)
	{
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	
	// Test convert chars to int
	cout << "5 chars to int" << endl;
	int convertedInt = input5CharsConvertToInt();
	cout << convertedInt << endl;


	// Test find
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int toFind = 7;
	int size = 9;
	int numFound = find(size, arr, toFind);

	if (numFound == -1)
	{
		cout << "Your number could not be found.\n";
	}
	else
	{
		cout << "Your number was found.\n";
	}

	// Test triangles
	cout << "Triangles" << endl;
	drawRightAngledTriangle();
	drawIsocelesTriangle();
	drawIsocelesTriangle2();

	// Test find2ndLargest
	numFound = find2ndLargest(size, arr);
	if (numFound == -1)
	{
		cout << "Error: Could not find a second largest number.\n";
	}
	else
	{
		cout << "The second largest number is " << numFound << ".\n";
	}

	// Copy array to array test
	int dupArr[5];
	int arr1[] = { 1, 2, 3, 4, 5 };
	int index = 0;
	size = 5;
	copyArraytoArray(5, arr1, dupArr);
	cout << "Copied Array: ";
	for (index = 0; index < size; index++)
	{
		cout << dupArr[index] << ", ";
	}
	cout << "\n";


	// Test insert element
	size = 5;
	int count = 4;
	int elementToInsert = 2;
	int insertIndex = 0;
	int insertArr[5] = {1, 2, 3, 4};

	bool doInsert = insertElement(size, count, insertArr, elementToInsert, insertIndex);

	if (doInsert = false)
	{
		cout << "Insertion failed.\n";
	}
	else
	{
		cout << "Insertion success! New array: ";
		for (index = 0; index < count; index++)
		{
			cout << insertArr[index] << " ";
		}
		cout << "\n";
	}

	// Test delete element
	size = 5; // Size of the array
	count = 5; // Count of elements in the array
	int deleteIndex = 2; // Index to delete
	int deleteArr[] = { 1, 2, 3, 4, 5 }; // Initial array

	// Test the deleteElement function
	bool deletionResult = deleteElement(size, count, deleteArr, deleteIndex);

	if (deletionResult)
	{
		cout << "Deletion successful! New array: ";
		for (int index = 0; index < count; index++)
		{
			cout << deleteArr[index] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "Deletion failed.\n";
	}

	// Test frequency
	cout << "Number appeared " << frequencyCount(size, insertArr, 2) << " times.\n";

	// Test duplicates
	size = 7;
	int dupliArr[7] = { 1, 2, 2, 3, 3, 4 ,5 };
	cout << "Number of duplicates: " << countDuplicates(size, dupliArr) << ".\n";

	// Test reverse
	int reverseArr[] = { 1, 2, 3, 4, 5 };
	size = sizeof(reverseArr) / sizeof(reverseArr[0]);

	cout << endl;
	cout << "Original Array: ";
	printArray(size, reverseArr);

	reverse(size, reverseArr);

	cout << "Reversed Array: ";
	printArray(size, reverseArr);

	// Test rotate left
	int arrRotate[] = { 1, 2, 3, 4, 5 };
	size = sizeof(arrRotate) / sizeof(arrRotate[0]);

	int result1 = rotateLeft(size, arrRotate);

	if (result1 == 1)
	{
		cout << "Rotated Array: ";
		printArray(size, arrRotate);
	}
	else
	{
		cout << "Rotation failed for Array 1." << endl;
	}

	cout << endl;

	// Test for two movies
	int flightLength = 120; // Total flight length in minutes
	int movieLengths[] = { 80, 40 }; // Array of movie lengths in minutes
	size = sizeof(movieLengths) / sizeof(movieLengths[0]); // Calculate array size

	// Test the twoMovies function
	int result = twoMovies(flightLength, movieLengths, size);

	if (result != -1)
	{
		cout << "Movies add up to flight length\n";
	}
	else
	{
		cout << "Movies do not add to flight length\n";
	}

	// Word Counter Test
	char input[] = "Hail to the king.";
	size = sizeof(input);
	count = wordCounter(size, input);
	cout << "Word count: " << count;
	cout << endl;

}