#pragma once
#include "libraries.h"
#include "place.h"

class TempPlace : public Place
{
public:
	bool valid;
	TempPlace();
	void clearData();
	void isValid(vector<Place>& database);
	void copyData(vector<Place>& database);
};
void overrideDataBase(vector<Place>& database);
bool alreadyInDataBase(TempPlace temp, vector<Place>& database);
void loadData(vector <Place> &database);
void addData(vector <Place> &database);
void generateData(vector<Place>& database, int howMany);