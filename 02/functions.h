#pragma once
#include <iostream>
#include <fstream>

using namespace std;

void horizontalChart()
{
    string line;
    char chart [10];
	int currentBar = 0;
	
	//place example.txt in the same folder in the project as this cpp file is in.
	ifstream myfile("horizontal.txt");
	int size = 0;
	int currentPos = 0;
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);
				if (c == ',')
				{
					continue;
				}
				else
				{
					chart[currentPos] = c - '0';
					currentPos++;
				}
			}
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
    }

	int numBars = chart[0];

	for (int thisBar = 1; thisBar <= numBars; thisBar++)
	{
		currentBar = chart[thisBar];
		for (int i = 0; i < currentBar; i++)
		{
			cout << "0";
		}
		cout << endl;
	}    
}

void verticalChart()
{
	string line;
    char height [10];
	int currentBar = 0;
	
	ifstream myfile("vertical.txt");
	int size = 0;
	int currentPos = 0;
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				char c = line.at(i);
				if (c == ',')
				{
					continue;
				}
				else
				{
					height[currentPos] = c - '0';
					currentPos++;
				}
			}
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
    }

	int numBars = height[0];
	int maxHeight = 0;

	for (int thisHeight = 1; thisHeight < numBars; thisHeight++)
	{
		if (height[thisHeight] > maxHeight)
		{
			maxHeight = height[thisHeight];
		}
	}

	for (int i = maxHeight; i >= 1; i--)
    {
        for (int index = 1; index <= numBars; index++)
        {
            if (height[index] >= i)
            {
                cout << "0"; 
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }


}

void scrambleCipher()
{
	string line;
	
	ifstream myfile("plaintext.txt");
	int currentPos = 0;
	char sentence [1000];
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				char c = line.at(i);
				sentence[currentPos] = c;
				currentPos++;
			}
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
    }

	int enteredShift = 0;
	char currentChar;
	char scrambleChar;

	cout << "How many places would you like to shift?" << endl;
	cin >> enteredShift;

	for (int index = 0; index < line.length(); index++)
	{
		if (sentence[index] == ' ')
		{
			cout << sentence[index];
			continue;
		}

		if (sentence[index] == 'z')
		{
			sentence[index] = (sentence[index] - 26) + enteredShift;
			cout << sentence[index];
		}

		else
		{
			currentChar = sentence[index];
			char base = 97;
			scrambleChar = base + (currentChar - base + enteredShift) % 26;
			sentence[index] = scrambleChar;
			cout << sentence[index];
		}

	}

}