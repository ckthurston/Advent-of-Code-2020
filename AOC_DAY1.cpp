// AOC_DAY1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	vector<int> input; // Holds all input data
	ifstream inputFile; // Input stream
	int v1, v2, v3; // Holds the values that are being tested to equal 2020
	int ans2 = 0, ans3 = 0; // Solution of the values mutlitplied
	bool flag = false; // Status flag
	
	inputFile.open("input.txt");
	if (!inputFile) // Tests for file
	{
		throw runtime_error("Error opening master.txt");
	}

	// Display Progress on Console....
	if (inputFile)
	{
		cout << "Reading data from the file." << endl;
		int data;

		// While Control Loop
		// Reads in data and stores into the vector.  Continues loop until
		// the end of the file (eof).
		while (!inputFile.eof())
		{
			inputFile >> data;
			input.push_back(data);
		}
	}

	inputFile.close(); // Close file stream.
	
	do // Do while loop to locate the 2 numbers that sum to 2020
	{
		for (int i = 0; i < input.size(); i++) // Controls 1st value
		{
			v1 = input[i];
			for (int j = i+1; j < input.size(); j++) // Controls 2nd value
			{
				v2 = input[j];
				if ((v1 + v2) == 2020) // Test to see 2 values sum to 2020
				{
					flag = true; // Set status flag to true
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
	}while (!flag); // Controlled by status flag...

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	ans2 = v1 * v2;
	cout << "Solution: " << ans2 << endl;

	flag = false;

	do // Do while loop to locate the 3 numbers that sum to 2020
	{
		for (int i = 0; i < input.size(); i++) // Controls 1st value
		{
			v1 = input[i];
			for (int j = i + 1; j < input.size(); j++) // Controls 2nd value
			{
				v2 = input[j]; 
				for (int k = j + 1; k < input.size(); k++) // Controls 3rd value
				{
					v3 = input[k];
					if ((v1 + v2 + v3) == 2020) // Test to see 2 values sum to 2020
					{
						flag = true; // Set status flag to true
					}
					if (flag)
						break;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
	} while (!flag); // Controlled by status flag...

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;
	ans3 = v1 * v2 * v3;
	cout << "Solution: " << ans3 << endl;

	system("pause");
	return 0;	
}
