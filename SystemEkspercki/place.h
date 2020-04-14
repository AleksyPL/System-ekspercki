#pragma once
#include "libraries.h"

class Place
{
public:
	string country;
	string city;
	int costOfRest;
	string typeOfRest;
	string purposeOfRest;
	string additionalActivitiesName;
	string transportToThePlaceOfRest;
	Place();
	string getCountry(bool firstBig = 0);
	void setCountry(string country);
	string getCity(bool firstBig = 0);
	void setCity(string city);
	int getCostOfRest();
	void setCostOfRest(int cost);
	string getTypeOfRest(bool firstBig = 0);
	void setTypeOfRest(string typeName);
	string getPurposeOfRest(bool firstBig = 0);
	void setPurposeOfRest(string purpose);
	string getAdditionalActivitiesName(bool firstBig = 0);
	void setAdditionalActivitiesName(string name);
	string getTransportToThePlaceOfRest(bool firstBig = 0);
	void setTransportToThePlaceOfRest(string name);
};