#pragma once
#include "Food.h"
#include <iostream>
using namespace std;
class Details : public Food
{
private:
	double calories;
public:
	Details();
	~Details();
	void take();
	void print();
};

