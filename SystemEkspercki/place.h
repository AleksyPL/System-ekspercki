#pragma once
#include "libraries.h"

class Place
{
public:
	string country; //nazwa pañstwa
	string city; //nazwa miasta
	int costOfRest; //koszt wypoczynku
	string typeOfRest; //typ wypoczynku
	string purposeOfRest; //powód wypoczynku
	string additionalActivitiesName; //dodatkowe atrakcje
	string transportToThePlaceOfRest; //metoda transportu na miejsce wypoczynku
	Place(); //konstruktor
	string getCountry(bool firstBig = 0); //funkcja do otrzymywania nazwy pañstwa
	void setCountry(string country); //funkcja do zapisania nazwy pañstwa
	string getCity(bool firstBig = 0); //funkcja do otrzymania nazwy miasta
	void setCity(string city); //funkcja do zapisania nazwy miasta
	int getCostOfRest(); //funkcja do otrzymania kosztu wypoczynku
	void setCostOfRest(int cost); //funkcja do zapisania kosztu wypoczynku
	string getTypeOfRest(bool firstBig = 0); //funkcja do otrzymania typu wypoczynku
	void setTypeOfRest(string typeName); //funkcja do zapisania typu wypoczynku
	string getPurposeOfRest(bool firstBig = 0); //funkcja do otrzymania powodu wypoczynku
	void setPurposeOfRest(string purpose); //funkcja do zapisania powodu wypoczynku
	string getAdditionalActivitiesName(bool firstBig = 0); //funkcja do otrzymania nazwy dodatkowej atrakcji
	void setAdditionalActivitiesName(string name); //funkcja do zapisania nazwy dodatkowej atrakcji
	string getTransportToThePlaceOfRest(bool firstBig = 0); //funkcja do otrzymania metody transportu na miejsce wypoczynku
	void setTransportToThePlaceOfRest(string name); //funkcja do zapisania metody transportu na miejsce wypoczynku
};