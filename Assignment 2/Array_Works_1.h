#pragma once
#include <iostream>
#include <string>
using namespace std;
class Array_Works_1
{
private:
	char *Array; 
	int size_1;
	int count_add;
public:
	Array_Works_1(int size);
	~Array_Works_1();
	char Add_element(char c);
	char delete_element();
	void peek();
	int size();
	bool is_empty();
	bool is_full();
};
