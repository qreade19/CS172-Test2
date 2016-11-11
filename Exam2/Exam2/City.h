#pragma once
#ifndef CITY_H
#define CITY_H
#include <string>
#include <vector>
#include <iostream>
#include "Citizen.h"
using namespace std;

class City
{
public:
	City(string cityName);
	~City();
	string getCityName();
	int populationSize();
	Citizen* getCitizenAtIndex(int index);
	void addCitizen(Citizen* citizen);
	Citizen* getCitizenWithId(int id);
	vector<Citizen*> getCitizensForFavoriteColor(string color);
private:
// This one was obvious, as it had a get function and was referenced in the constructor.
	string cityName;

// At first, I wasn't sure WHAT I was going to do with this. I tried using arrays, but the workarounds necessary to use them gave me a headache.
// So then I started using arrays, which worked much better, but I was struggling to figure out how to extract each particular variable.
// Eventually I decided to just give each variable its own vector, making for a much easier 1 to 1 transfer between headers and far simpler coding.
	vector<string> firstNames;
	vector<string> lastNames;
	vector<string> colors;
	vector<int> ids;
};

#endif