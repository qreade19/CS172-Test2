#include <string>
#include <iostream>
#include "Citizen.h"
using namespace std;

// I affirm that all code given below was written solely by me, Quinlan Reade, and that any help I recieved
// adhered to the rules stated for this exam.

Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	// Simple this-> commands to differentiate between data field and incoming variable.
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->color = color;
}

Citizen::Citizen(Citizen* citizen)
{
	// Used pointers to set the name from what's given.
	Citizen *ptr = citizen;
	id = (*ptr).id;
	firstName = (*ptr).firstName;
	lastName = (*ptr).lastName;
	color = (*ptr).color;
}

// The rest of this is very simple: A bunch of getters and setters.
string Citizen::getFirstName()
{
	return firstName;
}

string Citizen::getLastName()
{
	return lastName;
}

int Citizen::getId()
{
	return id;
}

string Citizen::getFavoriteColor()
{
	return color;
}

void Citizen::setFavoriteColor(string color)
{
	this->color = color;
}