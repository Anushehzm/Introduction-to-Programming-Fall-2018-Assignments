// Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
#include <algorithm> //for shuffle
#include "Student.h"
using namespace std;

double AverageResult(Student a[])
{
	int sum = 0;
	for (int y = 0; y < 100; y++)
	{
		sum += a[y].get_marks();
	}

	double avg = sum / 100.0;
	return avg;
}

void Sorter_roll_no(Student a[])
{
	for (int y = 0; y < 100; y++)
	{
		for (int t = 0; t < 99 - y; t++)
		{
			int o = a[t].get_rollno();
			int e = a[t + 1].get_rollno();
			if (o > e)
			{
				Student u = a[t]; //roll_number swapped
				a[t]= a[t+1];
				a[t+1]= u;

			}
		}
	}
	cout << "Sorted by roll number:" << endl;
	for (int w = 0; w < 100; w++)
	{
		print(a[w]);
	}
	
}
void Sorter_marks(Student a[])
{
	for (int y = 0; y < 100; y++)
	{
		for (int t = 0; t < 99 - y; t++)
		{
			int q = a[t].get_marks();
			int r = a[t + 1].get_marks();
			if (q < r)
			{
				Student u = a[t];//marks swapped
				a[t] = a[t + 1];
				a[t + 1] = u;

			}
		}
	}
	cout << "Sorted by marks:" << endl;
	for (int w = 0; w < 100; w++)
	{
		print(a[w]);
	}
}

void Calculations(Student a[])
{
	double mean = AverageResult(a);
	double var = 0;
	for (int y = 0; y < 100; y++)
	{
		var += pow(((a[y].get_marks()) - mean), 2);
	}
	double variance = var / (99);
	double standard_dev = sqrt(variance);
	Sorter_marks(a);
	double c = a[50].get_marks();
	double b = a[51].get_marks();
	double median = (c + b) / 2;
	//mode:
	int check = a[0].get_marks();
	int mode = a[0].get_marks();
	int count = 0;
	int temp = 0;
	for (int y = 0; y < 100; y++)
	{
		if (check == a[y].get_marks())
		{
			count++;
		}
		else
		{
			if (count > temp)
			{
				temp = count;
				mode = check;
			}
			count = 0;
			check = a[y].get_marks();
		}
	}
	cout << "Statistical information of the student data:" << endl << "Standard Deviation: " << standard_dev << endl << "Variance: " << variance << endl << "Median: " << median << endl << "Mode: " << mode << endl;


}
void Desired_Student(int &t, Student a[])
{
	for (int y = 0; y < 100; y++)
	{
		if (a[y].get_rollno() == t)
		{
			print(a[y]);
		}
	}
}

void HighestScorer(Student a[])
{
	int x = a[0].get_marks();
	for (int r = 0; r < 99; r++)
	{
		if (a[r].get_marks() > x)
		{
			x = a[r].get_marks();
		}
	}
	
	for (int y = 0; y < 100; y++)
	{
		if (a[y].get_marks() == x)
		{
			print(a[y]);
		}
	}
}


string Grade_Calculation(int marks)
{
	
	if (marks<= 100 && marks > 89)
	{
		return "A+";
	}
	else if (marks > 79)
	{
		return "A";
	}
	else if (marks > 69)
	{
		return "B";
	}
	else if (marks > 59)
	{
		return "C";
	}
	else if (marks > 49)
	{
		return "D";
	}
	else if (marks > 0 && marks <= 49)
	{
		return "F";
	}
	else
	{
		return "No Grade";
	}
}
int main()
{
	int rollno[100];
	int marks[100];
	string grades[100];
	Student arr[100];
	int j;
	cout << "Do you want to create a new written file or read the previous one? Press 1 for new and 2 for previous"<< endl;
	cin >> j;
	while (j < 1 && j>2)
	{
		cout << "Invalid input. Try again." << endl;
		cin >> j;
	}
	int f;
	cout << "If you want to exit the program at this point, press 0. Otherwise press any other number." << endl;
	cin>>f;
	if(f==0)
	{
	return 0;
	}

	if (j == 1)
	{
		cout << "Generating a new file and then reading from it." << endl;
		for (int p = 0;p < 100; p++)
			rollno[p] = p + 1; //numbers 1-100 filled into array

		random_shuffle(&rollno[0], &rollno[99]); //randomizing roll numbers

		for (int r = 0; r < 100; r++)
		{

			marks[r] = rand() % (95 + 1 - 20) + 20;
			grades[r] = Grade_Calculation(marks[r]);
		}


		ofstream myfile("Students.txt");

		if (myfile.is_open())
		{
			for (int y = 0; y < 100; y++)
			{
				if (y == 99)
				{
					myfile << rollno[y] << "," << marks[y] << "," << grades[y];
				}
				else
					myfile << rollno[y] << "," << marks[y] << "," << grades[y] << endl;
			}

			myfile.close();

		}
		else
		{
			cout << "File not open" << endl;
		}







		string dataline;
		ifstream read("Students.txt");
		if (read.is_open())
		{
			int r;
			int m;
			string g;
			int y = 0;
			while (!read.eof())
			{
				getline(read, dataline);
				int count = 1;
				int word = 0;
				string w, q;
				for (int a = 0; a < dataline.length(); a++)
				{

					if (dataline[a] == ',' && count == 1) //getting roll number
					{
						w = dataline.substr(word, a);
						word = a + 1;
						count++;
					}
					else if (dataline[a] == ',' && count == 2)// getting marks
					{
						q = dataline.substr(word, (a - 1) - (w.length()));
						word = a + 1;
						count++;
					}
					if (count == 3)//getting grade
					{
						g = dataline.substr(word, (dataline.length() - (w.length() + q.length())));
					}
				}

				r = stoi(w, nullptr); //casting to int
				m = stoi(q, nullptr); //casting to int

				arr[y].setter(r, m);
				arr[y].setter(g);
				//print(arr[y]);
				y++;
			}

			read.close();
		}
		else
		{
			cout << "File not opened" << endl;
		}
	}
	else
	{
		cout << "Reading from an old file." << endl;
		
		string dataline;
		ifstream read("Students.txt");
		if (read.is_open())
		{
			int r;
			int m;
			string g;
			int y = 0;
			while (!read.eof())
			{
				getline(read, dataline);
				int count = 1;
				int word = 0;
				string w, q;
				for (int a = 0; a < dataline.length(); a++)
				{

					if (dataline[a] == ',' && count == 1) //getting roll number
					{
						w = dataline.substr(word, a);
						word = a + 1;
						count++;
					}
					else if (dataline[a] == ',' && count == 2)// getting marks
					{
						q = dataline.substr(word, (a - 1) - (w.length()));
						word = a + 1;
						count++;
					}
					if (count == 3)//getting grade
					{
						g = dataline.substr(word, (dataline.length() - (w.length() + q.length())));
					}
				}

				r = stoi(w, nullptr); //casting to int
				m = stoi(q, nullptr); //casting to int

				arr[y].setter(r, m);
				arr[y].setter(g);
				//print(arr[y]);
				y++;
			}

			read.close();
		}
		else
		{
			cout << "File not opened" << endl;
		}
	}
	
	
	
	cout << "If you want to exit the program at this point, press 0. Otherwise press any other number." << endl;
	cin >> f;
	if (f == 0)
	{
		return 0;
	}

	int e;
	cout << "What details would you like to see? Press 1 to find details of a specific roll number, press 2 to view the highscorer(s), press 3 to view the class average score, press 4 to sort the data or press 5 to find collective statistical details of student data." << endl;
	cin >> e;
	while (e<1 || e>5)
	{
	cout << "Invalid entry. Re-enter a correct choice." << endl;
	cin >> e;
    }

	if (e == 1)
	{
		int desired;
		cout << "Enter roll number of student to preview his/her scores." << endl;
		cin >> desired;
		while (desired < 1 || desired>100)
		{
			cout << "Invalid roll number entered. Enter again." << endl;
			cin >> desired;
		}
		Desired_Student(desired, arr);
	}
	else if (e == 2)
	{
		cout << "Highest scorer(s): " << endl;
		HighestScorer(arr);
	}
	else if (e==3)
	{
		cout << "The average marks of the class is " << AverageResult(arr) << " which means an average grade of " << Grade_Calculation(AverageResult(arr)) << endl;
	}
	else if (e == 4)//bonus
	{
		int y;
		cout << "What measure do you want to sort your function by. Press 1 to sort by roll number and 2 to sort by score." << endl;
		cin >> y;
		while (y > 2 || y < 1)
		{
			cout << "Invalid option entered. Try again." << endl;
			cin >> y;
		}
		if (y == 1)
		{
			Sorter_roll_no(arr);
		}
		else
		{
			Sorter_marks(arr);
			
		}
	}
	else //bonus
	{
		Calculations(arr);
	}
	
	return 0;
}


