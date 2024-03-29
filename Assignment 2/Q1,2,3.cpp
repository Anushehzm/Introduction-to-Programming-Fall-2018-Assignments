// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array_Works_1.h"
#include "Array_Works_2.h"
#include <string>
#include <ctype.h> //for isdigit()

using namespace std; //put checks for input of wrong data type
int main()
{
	//Question 2 
	const int size_1 = 7;
	int s_count = 0;
	char stack[size_1];
	char stack2[size_1];
	char a[size_1] = {'3','+','4','/','5','+','6'};
	Array_Works_1 obj1(size_1);
	Array_Works_2 obj2(size_1);
	char p;
	cout << "If you want to convert infix to postfix using ArrayWorks1, press 1 and if with ArrayWorks2, press 2"<< endl;	
	cin >> p;
	while (p != '1' && p != '2')
	{
		cout << "Incorrect option. Try again" << endl;
		cin >> p;
	}
	if (p == '1')
	{
		//Saving result in Array_Work_1
		cout << "Array_Works_1:" << endl;
		for (int u = 0; u < size_1; u++)
		{
			if (isdigit(a[u]) > 0)//digit-put in Array  
			{
				obj1.Add_element(a[u]);
			}
			else //not an integer-operator to be kept in stack list
			{
				stack[s_count] = a[u];
				s_count++;
				while ((stack[s_count - 1] == stack[s_count - 2]) || (stack[s_count - 1] == '+' && stack[s_count - 2] == '-') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '+') || (stack[s_count - 1] == '*' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '/' && stack[s_count - 2] == '*') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '+' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '+' && stack[s_count - 2] == '*') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '*'))//precedence check-If same togeth er, or higher precedence before lower precedence, push first of the two into the Array
				{
					obj1.Add_element(stack[s_count - 2]);//popping from stack to Array_Works_1
					stack[s_count - 2] = stack[s_count - 1];
					s_count--;
				}

			}

		}
		//Adding final element
		obj1.Add_element(stack[0]);

		//store in temp array to use it for solving
		s_count = 0;
		
		for (int y = 0; y < size_1; y++)//make temporary array
		{
			stack[(size_1 -1)-y] = obj1.delete_element();
		}

		/*check temp array
		cout << "Check:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			cout<<(stack[y])<<",";
		}*/

		cout << endl;
		for (int y = 0; y < size_1; y++)
		{
			obj1.Add_element(stack[y]);
		}
		cout << endl;

		//Solving
		int t_count = 0;
		char temp[7];
		cout << "Solving Postfix expression stored in Array:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			if (isdigit(stack[y]) > 0)//digit
			{
				temp[t_count] = stack[y];
				t_count++;
			}
			else //operator-loss if precision due to int
			{
				//converting characters to integers
				int first = temp[t_count - 2] - '0';
				int second = temp[t_count - 1] - '0';
				//check
				//cout << "Check: " << first << " and  " << second << endl;
				char res;
				int result;
				if (stack[y] == '+')
				{
					result = first + second;
					//convert back
					res = result + '0';
					//check
					//cout << "Check casting: " << res << endl;
				}
				else if (stack[y] == '-')
				{
					result = first - second;
					//convert back
					res = result + '0';
				}
				else if (stack[y] == '*')
				{
					result = first * second;
					//convert back
					res = result + '0';
				}
				else // division
				{
					if (second == 0)
					{
						cout << "Division gives undefined result. Re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = first / second;
						//convert back
						res = result + '0';

					}
				}
				temp[t_count - 2] = res;
				t_count--;
			}
		}
		cout << "Result using integer operations: " << temp[0] << endl;

	}
	if (p == '2')
	{
		//Saving result in Array_Works_2
		cout << endl << "Array_Works_2:" << endl;
		s_count = 0;
		for (int u = 0; u < size_1; u++)
		{
			if (isdigit(a[u]) > 0)//digit-put in Array  
			{
				obj2.Add_element(a[u]);
			}
			else //not an integer-operator to be kept in stack list
			{
				stack2[s_count] = a[u];
				s_count++;
				while ((stack2[s_count - 1] == stack2[s_count - 2]) || (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '-') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '+') || (stack2[s_count - 1] == '*' && stack2[s_count - 2] == '/') || (stack2[s_count - 1] == '/' && stack2[s_count - 2] == '*') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '/') || (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '/') || (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '*') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '*'))//precedence check-If same togeth er, or higher precedence before lower precedence, push first of the two into the Array
				{
					obj2.Add_element(stack2[s_count - 2]);//popping from stack to Array_Works_1
					stack2[s_count - 2] = stack2[s_count - 1];
					s_count--;
				}

			}

		}
		//Adding final element
		obj2.Add_element(stack2[0]);

		//correcting order in ArrayWorks2 Array
		for (int y = 0; y < size_1; y++)//make temporary array
		{
			stack2[((size_1)-1) - y] = obj2.delete_element();
		}

		/*check temp array
		cout << "Check:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			cout<<(stack2[y])<<",";
		}*/

		cout << endl;
		for (int y = 0; y < size_1; y++)
		{
			obj2.Add_element(stack2[(size_1 - 1) - y]);
		}

		//Solving
		int t_count = 0;
		char temp[7];
		cout << "Solving Postfix expression stored in Array:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			if (isdigit(stack2[y]) > 0)//digit
			{
				temp[t_count] = stack2[y];
				t_count++;
			}
			else //operator-loss if precision due to int
			{
				//converting characters to integers
				int first = temp[t_count - 2] - '0';
				int second = temp[t_count - 1] - '0';
				//check
				//cout << "Check: " << first << " and  " << second << endl;
				char res;
				int result;
				if (stack2[y] == '+')
				{
					result = first + second;
					//convert back
					res = result + '0';
					//check
					//cout << "Check casting: " << res << endl;
				}
				else if (stack2[y] == '-')
				{
					result = first - second;
					//convert back
					res = result + '0';
				}
				else if (stack2[y] == '*')
				{
					result = first * second;
					//convert back
					res = result + '0';
				}
				else // division
				{
					if (second == 0)
					{
						cout << "Division gives undefined result. Re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = first / second; 
						//convert back
						res = result + '0';
						
					}
				}
				temp[t_count - 2] = res;
				t_count--;
			}
		}
		cout << "Result using integer operations: " << temp[0]<<endl;
		
		
	}

	//Question 3

	//const int size_1 = 7;
	s_count = 0;
	//stack[size_1];
	//stack2[size_1];
	char b[size_1] = { '3','-','8','*','5','%','2' };
	char b_reverse[size_1]= { '2','%','5','*','8','-','3' };
	Array_Works_1 obj3(size_1);
	Array_Works_2 obj4(size_1);
	cout << "If you want to convert infix to prefix using ArrayWorks1, press 1 and if with ArrayWorks2, press 2" << endl;
	cin >> p;
	while (p != '1' && p != '2')
	{
		cout << "Incorrect option. Try again" << endl;
		cin >> p;
	}
	if (p == '1') //postfixing
	{
		//Saving result in Array_Work_1
		cout << "Array_Works_1:" << endl;

		for (int u = 0; u < size_1; u++)
		{
			if (isdigit(b_reverse[u]) > 0)//digit-put in Array  
			{
				obj3.Add_element(b_reverse[u]);
			}
			else //not an integer-operator to be kept in stack list
			{
				stack[s_count] = b_reverse[u];
				s_count++;
				while (/*(stack[s_count - 1] == stack[s_count - 2]) || (stack[s_count - 1] == '+' && stack[s_count - 2] == '-') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '+') || (stack[s_count - 1] == '*' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '/' && stack[s_count - 2] == '*') ||*/ (stack[s_count - 1] == '+' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '%') || (stack[s_count - 1] == '+' && stack[s_count - 2] == '%') || (stack[s_count - 1] == '+' && stack[s_count - 2] == '*') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '*'))//precedence check-If higher precedence before lower precedence, push first of the two into the Array
				{
					obj3.Add_element(stack[s_count - 2]);//popping from stack to Array_Works_1
					stack[s_count - 2] = stack[s_count - 1];
					s_count--;
				}

			}

		}
		//Adding final element
		obj3.Add_element(stack[0]);

		//Correct till here

		
		//correcting order of Array
		char temp2[size_1];
		for (int y = 0; y < size_1; y++)//make temporary array
		{
			temp2[(size_1-1)-y] = obj3.delete_element();
		}

		//check temp array-reversed
		//cout << "Check:" << endl;
		//for (int y = 0; y < size_1; y++)
		//{
			//cout<<(temp2[y])<<",";
		//}

		cout << endl;
		for (int y = 0; y < size_1; y++)
		{
			obj3.Add_element(temp2[(size_1-1)-y]);
		}
		//Solving
		int t_count = 0;
		char temp3[7];
		cout << "Solving Prefix expression stored in Array:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			if (isdigit(temp2[y]) > 0)//digit
			{
				temp3[t_count] = temp2[y];
				t_count++;
				//cout << "CHECK" << temp3[t_count - 1];
			}
			else //operator-loss if precision due to int
			{
				//converting characters to integers
				int first = temp3[t_count - 2] - '0';
				int second = temp3[t_count - 1] - '0';
				//check
				//cout << "Check: " << first << " and  " << second << endl;
				char res;
				int result;
				if (temp2[y] == '+')
				{
					result = first + second;
					//convert back
					res = result + '0';
					//check
					//cout << "Check casting: " << res << endl;
				}
				else if (temp2[y] == '-')
				{
					result = second - first;
					//convert back
					res = result + '0';
				}
				else if (temp2[y] == '*')
				{
					result = first * second;
					//convert back
					res = result + '0';
				}
				else if (temp2[y] == '%')
				{
					if (first == 0)
					{
						cout << "Division gives undefined result. Re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = second % first;
						//convert back
						res = result + '0';

					}
				}
				else // division
				{
					if (first == 0)
					{
						cout << "Division gives undefined result. Re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = second / first;
						//convert back
						res = result + '0';

					}
				}
				temp3[t_count - 2] = res;
				t_count--;
			}
		}
		cout << "Result using integer operations: " << temp3[0] << endl;	

	}


	if (p == '2')
	{
		//saving result in array_works_2
		//reverse array first then postfix then reverse
		cout << endl << "ArrayWorks2:" << endl;
		s_count = 0;
		for (int u = 0; u < size_1; u++)
		{
			if (isdigit(b_reverse[u]) > 0)//digit-put in array  
			{
				obj4.Add_element(b_reverse[u]);
			}
			else //not an integer-operator to be kept in stack list
			{
				stack2[s_count] = b_reverse[u];
				s_count++;
				while (/*(stack[s_count - 1] == stack[s_count - 2]) || (stack[s_count - 1] == '+' && stack[s_count - 2] == '-') || (stack[s_count - 1] == '-' && stack[s_count - 2] == '+') || (stack[s_count - 1] == '*' && stack[s_count - 2] == '/') || (stack[s_count - 1] == '/' && stack[s_count - 2] == '*') ||*/ (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '/') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '/') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '%') || (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '%') || (stack2[s_count - 1] == '+' && stack2[s_count - 2] == '*') || (stack2[s_count - 1] == '-' && stack2[s_count - 2] == '*'))//If higher precedence before lower precedence, push first of the two into the Array
				{
					obj4.Add_element(stack2[s_count - 2]);//popping from stack to array_works_1
					stack2[s_count - 2] = stack2[s_count - 1];
					s_count--;
				}

			}

		}
		//adding final element
		obj4.Add_element(stack2[0]);

		//correcting order in arrayworks2 array
		for (int y = 0; y < size_1; y++)//make temporary array
		{
			stack2[((size_1)-1) - y] = obj4.delete_element();
		}

		//check temp array
		/*cout << "check:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			cout<<(stack2[y])<<",";
		}*/

		cout << endl;
		for (int y = 0; y < size_1; y++)
		{
			obj4.Add_element(stack2[y]);
		}

		//Solving
		int t_count = 0;
		char temp[7];
		cout << "Solving prefix expression stored in array:" << endl;
		for (int y = 0; y < size_1; y++)
		{
			if (isdigit(stack2[y]) > 0)//digit
			{
				temp[t_count] = stack2[y];
				t_count++;
			}
			else //operator-loss if precision due to int
			{
				//converting characters to integers
				int first = temp[t_count - 2] - '0';
				int second = temp[t_count - 1] - '0';
				//check
				//cout << "check: " << first << " and  " << second << endl;
				char res;
				int result;
				if (stack2[y] == '+')
				{
					result = first + second;
					//convert back
					res = result + '0';
					//check
					//cout << "check casting: " << res << endl;
				}
				else if (stack2[y] == '-')
				{
					result = second - first;
					//convert back
					res = result + '0';
				}
				else if (stack2[y] == '*')
				{
					result = first * second;
					//convert back
					res = result + '0';
				}
				else if (stack2[y]=='%')// mod
				{
					if (first == 0)
					{
						cout << "Division gives undefined result. re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = second % first;
						//convert back
						res = result + '0';

					}
				}

				else // division
				{
					if (first == 0)
					{
						cout << "Division gives undefined result. re-evaluate your expression." << endl;
						break;
					}
					else
					{
						result = second / first;
						//convert back
						res = result + '0';

					}
				}
				temp[t_count - 2] = res;
				t_count--;
			}
		}
		cout << "result using integer operations: " << temp[0] << endl;
	}
		return 0;
}

	/*char answer='-';
	char add;
	string g;
	int size;
	cout << "Enter size of array" << endl;
	cin >> g;
	int x = 0;
	int y;
	for (int u = 0; u < g.length() ; u++) //making sure a number is entered 
	{
		if (isdigit(g[u]) != 0)
		{
			y = 1;
		}
		else
		{
			y = 0;
		}
		x += y;
	}
	while (x != (g.length()))
	{
		x = 0;
		cout << "Incorrect input. Make sure your entered array size is an integer. Try again." << endl;
		cin >> g; 
		for (int u = 0; u < g.length(); u++)
		{
			if (isdigit(g[u]) != 0)
			{
				y = 1;
			}
			else
			{
				y = 0;
			}
			x += y;
		}
	}
		size = stoi(g); //converting to int
		Array_Works_1 obj1(size);
		Array_Works_2 obj2(size);

		char choice;
		cout << "If you want to deal with first element of array, press 1. If you want to deal with last element of array, press 2." << endl;
		cin >> choice;
		while (choice != '1' && choice != '2')
		{
			cout << "Incorrect input. Try again. Press either 1 or 2." << endl;
			cin >> choice;
		}
		while (answer != 'e')
		{
			if (choice == '2') 
			{
				cout << "If you want to add a character to your array press 'a'.\nIf you want to remove a character, press 'r'.\nIf you want to check the top element of the array, press 'p'.\nIf you want to check size of the array, press 's'.\nIf you want to check if array is empty or full, press 'b'. \nIf you want to exit program, press 'e'." << endl;
				cin >> answer;
				while (answer != 'a' && answer != 'r' && answer != 's' && answer != 'p' && answer != 'b' && answer != 'e')
				{
					cout << "Incorrect input. Please press either a,r,s,p,b or e." << endl;
					cin >> answer;
				}
				if (answer == 'a')
				{
					cout << "Enter character to be added." << endl;
					cin >> add;
					obj1.Add_element(add);
				}
				if (answer == 'r')
				{
					obj1.delete_element();

				}
				if (answer == 'p')
				{
					obj1.peek();

				}
				if (answer == 's')
				{
					cout << "Size of array is " << obj1.size() << endl;

				}
				if (answer == 'b')
				{
					bool f = obj1.is_full();
					bool e = obj1.is_empty();
					if (f == true)
					{
						cout << "The array is full." << endl;
					}
					else if (e == true)
					{
						cout << "The array is empty." << endl;
					}
					else
					{
						cout << "The array is neither full nor empty." << endl;

					}
				}
				if (answer == 'e')
				{
					cout << "Ending program" << endl;
					return 0;
				}
			}
			if (choice == '1')
			{
				cout << "If you want to add a character to your array press 'a'.\nIf you want to remove a character, press 'r'.\nIf you want to check the first element of the array, press 'p'.\nIf you want to check size of the array, press 's'.\nIf you want to check if array is empty or full, press 'b'. \nIf you want to exit program, press 'e'." << endl;
				cin >> answer;
				while (answer != 'a' && answer != 'r' && answer != 's' && answer != 'p' && answer != 'b' && answer != 'e')
				{
					cout << "Incorrect input. Please press either a,r,s,p,b or e." << endl;
					cin >> answer;
				}
				if (answer == 'a')
				{
					cout << "Enter character to be added." << endl;
					cin >> add;
					obj2.Add_element(add);
				}
				if (answer == 'r')
				{
					obj2.delete_element();

				}
				if (answer == 'p')
				{
					obj2.peek();

				}
				if (answer == 's')
				{
					cout << "Size of array is " << obj2.size() << endl;

				}
				if (answer == 'b')
				{
					bool f = obj2.is_full();
					bool e = obj2.is_empty();
					if (f == true)
					{
						cout << "The array is full." << endl;
					}
					else if (e == true)
					{
						cout << "The array is empty." << endl;
					}
					else
					{
						cout << "The array is neither full nor empty." << endl;

					}
				}
				if (answer == 'e')
				{
					cout << "Ending program" << endl;
					return 0;
				}
			}

				cout << "If you want to exit the program, press 'e'. Otherwise, press anything else." << endl;
				cin >> answer;
		}

		cout << "Ending program" << endl;*/
	


