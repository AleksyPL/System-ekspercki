#include "place.h"

//konstruktor
Place::Place()
{
	this->country = "";
	this->city = "";
	this->costOfRest = 0;
	this->typeOfRest = "";
	this->purposeOfRest = "";
	this->additionalActivitiesName = "";
	this->transportToThePlaceOfRest = "";
}
//funkcja do otrzymywania nazwy pañstwa
string Place::getCountry(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->country;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->country;
	}
}
//funkcja do zapisania nazwy pañstwa
void Place::setCountry(string country)
{
	country = stringToLower(country);
	this->country = country;
}
//funkcja do otrzymania nazwy miasta
string Place::getCity(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->city;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->city;
	}
}
//funkcja do zapisania nazwy miasta
void Place::setCity(string city)
{
	city = stringToLower(city);
	this->city = city;
}
//funkcja do otrzymania kosztu wypoczynku
int Place::getCostOfRest()
{
	return this->costOfRest;
}
//funkcja do zapisania kosztu wypoczynku
void Place::setCostOfRest(int cost)
{
	try
	{
		this->costOfRest = cost;
	}
	catch (std::exception)
	{
		;
	}
}
//funkcja do otrzymania typu wypoczynku
string Place::getTypeOfRest(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->typeOfRest;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->typeOfRest;
	}
}
//funkcja do zapisania typu wypoczynku
void Place::setTypeOfRest(string typeName)
{
	typeName = stringToLower(typeName);
	this->typeOfRest = typeName;
}
//funkcja do otrzymania powodu wypoczynku
string Place::getPurposeOfRest(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->purposeOfRest;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->purposeOfRest;
	}
}
//funkcja do zapisania powodu wypoczynku
void Place::setPurposeOfRest(string purpose)
{
	purpose = stringToLower(purpose);
	this->purposeOfRest = purpose;
}
//funkcja do otrzymania nazwy dodatkowej atrakcji
string Place::getAdditionalActivitiesName(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->additionalActivitiesName;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->additionalActivitiesName;
	}
}
//funkcja do zapisania nazwy dodatkowej atrakcji
void Place::setAdditionalActivitiesName(string name)
{
	name = stringToLower(name);
	this->additionalActivitiesName = name;
}
//funkcja do otrzymania metody transportu na miejsce wypoczynku
string Place::getTransportToThePlaceOfRest(bool firstBig)
{
	if (firstBig == true)
	{
		string temp = this->transportToThePlaceOfRest;
		temp[0] = toupper(temp[0]);
		return temp;
	}
	else
	{
		return this->transportToThePlaceOfRest;
	}
}
//funkcja do zapisania metody transportu na miejsce wypoczynku
void Place::setTransportToThePlaceOfRest(string name)
{
	name = stringToLower(name);
	this->transportToThePlaceOfRest = name;
}
