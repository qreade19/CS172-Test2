#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "City.h"
#include "Citizen.h"
using namespace std;

// I affirm that all code given below was written solely by me, Quinlan Reade, and that any help I recieved
// adhered to the rules stated for this exam.

City::City(string cityName)
{
	// Lol. Got so preoccupied with the text file that I almost forgot the other reason this constructor is here.
	this->cityName = cityName; // <- Namely this.

	string fileName = cityName + ".txt";
	fstream citizenList(fileName, ios::in || ios::out);

	if (citizenList.fail())
	{
		// Nothing really needs to be her for this part.
	}
	else
	{
		// Using vectors made particular sense here, where the use of the text file required a focus on the end-of-file rather than the arrays.
		int id;
		string fName;
		string lName;
		string color;
		while (!citizenList.eof())
		{
			citizenList >> id;
			citizenList >> fName;
			citizenList >> lName;
			citizenList >> color;
			ids.push_back(id);
			firstNames.push_back(fName);
			lastNames.push_back(lName);
			colors.push_back(color);
		}
		citizenList.close();
	}
	//citizenList.close();
}

City::~City()
{
	fstream citizenList;
	citizenList.open(cityName + ".txt", ios::out);

	if (citizenList.fail())
		cout << "File will not open or doesn't exist" << endl;

	for (int i = 0; i < firstNames.size(); i++)
	{
		citizenList << ids.at(i) << " " << firstNames.at(i) << " " << lastNames.at(i) << " " << colors.at(i) << endl;
	}

	citizenList.close();

	ids.clear();
	firstNames.clear();
	lastNames.clear();
	colors.clear();
}

string City::getCityName()
{
	return cityName;
}

int City::populationSize()
{
	// Since all of the data field vectors have the same size, any of them could be put here.
	return firstNames.size();
}

Citizen* City::getCitizenAtIndex(int index)
{
// And it was parts like this where the use of four different vectors can be incredibly helpful, whether it be fulfilling certain requirements...
	Citizen *ptr = new Citizen(ids[index], firstNames[index], lastNames[index], colors[index]);
	delete ptr;
	return ptr;
}

void City::addCitizen(Citizen* citizen)
{
	Citizen *ptr = new Citizen(citizen);
	ids.push_back((*ptr).getId());
	firstNames.push_back((*ptr).getFirstName());
	lastNames.push_back((*ptr).getLastName());
	colors.push_back((*ptr).getFavoriteColor());
	delete ptr;
}

// ...or using one variable to find others.
Citizen* City::getCitizenWithId(int id)
{
// Create temporary variables to use from the for loop.
	int tempId;
	string tempFName;
	string tempLName;
	string tempcolor;

// Use a for loop to search through the entire vector (again, any of the vectors could have been used for the size function, but it seemed more appropriate, in this case, to use ids).
	for (int i = 0; i < ids.size(); i++)
	{
		if (ids[i] == id) // if the id matches, then the spot is used for the other vectors, which are all aligned in terms of content.
		{
			tempId = ids.at(i);
			tempFName = firstNames.at(i);
			tempLName = lastNames.at(i);
			tempcolor = colors.at(i);
		}
	}
// Finally, create the pointer to be used for the return type.
	Citizen *ptr = new Citizen(tempId, tempFName, tempLName, tempcolor);
	delete ptr;
	return ptr;
}

// Similar setup to the previous one, except this is going into a vector instead of a pointer.
vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	vector<Citizen*> colorCitizen;

	for (int i = 0; i < colors.size(); i++)
	{
		if (colors[i] == color)
		{
			Citizen *ptr = new Citizen(ids.at(i), firstNames.at(i), lastNames.at(i), colors.at(i));
			colorCitizen.push_back(ptr);
			delete ptr;
		}
	}
	
	return colorCitizen;
}