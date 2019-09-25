#include "pch.h"
#include "Food.h"
#include <iostream>
using namespace std;
Food::Food()
{

}


Food::~Food()
{
}

void Food::Fruits()
{
	int length;
	string temp1 = "";
	string temp2 = "";
	int temp3;
	for (int y = 0; y < 5; y++)
	{
		length = F[y].length();
		for (int i = 0; i < length; i++)
		{
			if (F[y][i] == '_')
			{
				for (int u = 0; u < i; u++)
				{
					temp1 += F[y][u];
				}
				Fruit[y] = temp1;
				for (int p = i+1 ; p < length; p++)
				{
					temp2 += F[y][p];
			
				}
				
				temp3 = stoi(temp2);
				Fruit_cal[y] = temp3;
				temp1 = "";
				temp2 = "";
			}
		}
	}
	cout << "Fruits: " << endl;

	for (int w = 0; w < 5; w++)
	{
		cout << "Fruit: "<<Fruit[w] << "    Calories: " << Fruit_cal[w] << endl;
	}
	cout << endl;
};



void Food::Vegetables()
{
	int length;
	string temp1 = "";
	string temp2 = "";
	int temp3;
	for (int y = 0; y < 5; y++)
	{
		length = V[y].length();
		for (int i = 0; i < length; i++)
		{
			if (V[y][i] == '_')
			{
				for (int u = 0; u < i; u++)
				{
					temp1 += V[y][u];
				}
				Vegetable[y] = temp1;
				for (int p = i + 1; p < length; p++)
				{
					temp2 += V[y][p];

				}

				temp3 = stoi(temp2);
				Vegetable_cal[y] = temp3;
				temp1 = "";
				temp2 = "";
			}
		}
	}
	cout << "Vegetables: " << endl;
	for (int w = 0; w < 5; w++)
	{
		cout << "Vegetable: "<<Vegetable[w] << "    Calories: " << Vegetable_cal[w] << endl;
	}
	cout << endl;
}

void Food::Nuts()
{

	int length;
	string temp1 = "";
	string temp2 = "";
	int temp3;
	for (int y = 0; y < 5; y++)
	{
		length = N[y].length();
		for (int i = 0; i < length; i++)
		{
			if (N[y][i] == '_')
			{
				for (int u = 0; u < i; u++)
				{
					temp1 += N[y][u];
				}
				Nut[y] = temp1;
				for (int p = i + 1; p < length; p++)
				{
					temp2 += N[y][p];

				}

				temp3 = stoi(temp2);
				Nut_cal[y] = temp3;
				temp1 = "";
				temp2 = "";
			}
		}
	}
	cout << "Nuts: " << endl;
	for (int w = 0; w < 5; w++)
	{
		cout << "Nut: " << Nut[w] << "    Calories: " << Nut_cal[w] << endl;
	}
	cout << endl;
}