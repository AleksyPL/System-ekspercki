#include "place.h"

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

void Place::setCountry(string country)
{
	country = stringToLower(country);
	this->country = country;
}

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

void Place::setCity(string city)
{
	city = stringToLower(city);
	this->city = city;
}

int Place::getCostOfRest()
{
	return this->costOfRest;
}

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

void Place::setTypeOfRest(string typeName)
{
	typeName = stringToLower(typeName);
	this->typeOfRest = typeName;
}

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

void Place::setPurposeOfRest(string purpose)
{
	purpose = stringToLower(purpose);
	this->purposeOfRest = purpose;
}

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

void Place::setAdditionalActivitiesName(string name)
{
	name = stringToLower(name);
	this->additionalActivitiesName = name;
}

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

void Place::setTransportToThePlaceOfRest(string name)
{
	name = stringToLower(name);
	this->transportToThePlaceOfRest = name;
}
