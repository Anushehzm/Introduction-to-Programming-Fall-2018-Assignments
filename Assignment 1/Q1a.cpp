// Q1.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
void FindFrequencyDistribution(int valuesArray[], int FrequencyArray[], int inputArraySize, int
	FrequencyArraySize)
{
	int *values= new int[FrequencyArraySize];
	//Fills an array with only unique values of elements
	int j = 0;
	values[0] = valuesArray[0];
	//cout << values[0] << endl;
	int w = 1;
	for (int r = 0; r < inputArraySize; r++)
	{
		if (valuesArray[r]!=valuesArray[j])
		{
			j = r;
			values[w] = valuesArray[r];
			w++;
		}
	}
	//Printing unique values array
	cout << "Values Array: {";
	for (int y=0; y< FrequencyArraySize; y++)
	{
		if (y != FrequencyArraySize - 1)
		{
			cout << values[y] << ",";
		}
		else
			cout << values[y];
	}
	cout <<"}"<< endl;
	int x = 0;
	//Producing frequency array
	for (int j = 0; j < FrequencyArraySize; j++)
	{
		int counter = 0;
		for (int q = x; q < inputArraySize; q++)
		{
			if (valuesArray[q] == values[j])
			{
				counter++;
				x++;
				if (q == inputArraySize - 1 && j == FrequencyArraySize - 1)
				{
					FrequencyArray[j] = counter;
				}
			}
			else
			{
				FrequencyArray[j] = counter;
			}
		}
		
	}
	
	//Printing Freq array
	cout << "Frequency Array: {";
	for (int d=0; d<FrequencyArraySize; d++)
	{
		if (d != FrequencyArraySize - 1)
		{
			cout << FrequencyArray[d]<<",";
		}
		else
		{
			cout << FrequencyArray[d];
		}
	}
	cout <<"}" <<endl;
}
int main()
{
	int input_size;
	cout << "Enter the size of an integer array whose frequency distribution you want to find within the range of 25-100." << endl;
	cin >> input_size;
	//checking correct input size
	while (input_size < 25 || input_size>100)
	{
		cout << "You entered a size outside the correct range. Try again" << endl;
		cin >> input_size;
	}
	int *input_array = new int[input_size];
	
	//inputing array elements
	for (int i = 0; i < input_size; i++)
	{
		cout << "Enter integer "<<i+1 << endl;
		int u;
		cin >> u;
		//range checking
		if (u >= 0 && u < 10)
		{
			input_array[i] = u;
		}
		else
		{
			cout << "Your integer should be from 0-9. Enter again" << endl;
			i--;
		}
	}
	//checking input
	cout << "Your entered array is:    ";
	for (int y = 0; y < input_size; y++)
	{
		cout << input_array[y];
	}
	cout << endl;
	//sort array in ascending order
	for (int p = 0 ; p<input_size-1; p++)
	{
		for (int x = 0; x < input_size - p - 1; x++)
		{
			if (input_array[x] > input_array[x + 1])
			{
				int a = input_array[x];
				input_array[x] = input_array[x + 1];
				input_array[x + 1] = a;

			}
		}
	}
	cout << "Array in ascending order: ";
	for (int y = 0; y < input_size; y++)
	{
		cout << input_array[y];
	}
	//finding number of unique elements in input_array to find size of freq array
	int check = input_array[0];
	int count = 1;
	for (int e = 0; e < input_size; e++)
	{
		if (input_array[e]!=check)
		{
			check = input_array[e];
			count++;
		}
	}
	cout << endl<< "Number of unique elements in your array: "<<count<<endl;
	int *freq= new int[count];
	FindFrequencyDistribution(input_array, freq, input_size, count);
	return 0;
}
/*Input array size cannot be less than 25 and cannot be greater than 100. The input must be taken from the user at runtime. 
The input can only be a single letter digit. (So focus on what can be the size of value and frequency array).*/
