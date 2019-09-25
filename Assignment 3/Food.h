#pragma once
#include <string>
#include <iostream>
using namespace std;

class Food
{
protected:
	string F[5] = { "apple_25","guava_55","banana_10","mango_60", "peach_15" };
	string V[5] = { "broccoli_44","onion_14","peas_47","potato_88", "capsicum_20" };
	string N[5] = {"almonds_80","cacao_85","coconut_62","hazelnut_77","cashew_90"};
	string Fruit[5];
	string Nut[5];
	string Vegetable[5];
	int Fruit_cal[5];
	int Nut_cal[5];
	int Vegetable_cal[5];
public:
	Food();
	~Food();
	void Fruits();
	void Vegetables();
	void Nuts();
};