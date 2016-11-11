#pragma once
#ifndef CITIZEN_H
#define CITIZEN_H
#include <string>
#include <iostream>
using namespace std;

class Citizen
{
public:
	Citizen(int id, string firstName, string lastName, string color);
	Citizen(Citizen* citizen);
	string getFirstName();
	string getLastName();
	int getId();
	string getFavoriteColor();
	void setFavoriteColor(string color);
private:
	int id;
	string firstName;
	string lastName;
	string color;
};

#endif