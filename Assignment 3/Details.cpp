#include "pch.h"
#include "Details.h"
#include "Food.h"
#include <iostream>
using namespace std;

Details::Details()
{
	Fruits();
	Vegetables();
	Nuts();

}


Details::~Details()
{
}

void Details::take()
{
	cout << "What amount of calories do you intend to consume?" << endl;
	cin >> calories;
}

void Details::print()
{
	int count = 1;
	double total;
	for (int y = 0; y < 5; y++) //fruits
	{
		for (int q = 0; q < 5; q++)//veg
		{
			for (int w = 0; w < 5; w++)//nut1
			{
				for (int r = w; r < 5; r++)//nut2
				{
					total = Fruit_cal[y] + Vegetable_cal[q] + Nut_cal[w] + Nut_cal[r];
					if (total<=calories && w != r)
					{
						cout << "Combination number " << count << " : " << Fruit[y]<<"("<<Fruit_cal[y] << "), " << Vegetable[q] <<"("<<Vegetable_cal[q]<< "), " << Nut[w] <<"(" <<Nut_cal[w]<<") and " << Nut[r] <<"("<< Nut_cal[r]<<")"<<endl;
						cout << "Total calories in the given combination: " << total << endl;
						count++;
					}
				}
			}
		}
	}
	cout << "Total number of possible combinations with the calorie limit entered: " << count-1<<endl;
}
