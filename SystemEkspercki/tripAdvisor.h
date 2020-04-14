#pragma once
#include "libraries.h"
#include "place.h"

void deleteFromDataBase(vector<Place>& database, string question, string answer);
void printResult(vector<Place>& object);
bool databaseIsEmpty(vector<Place>& database);
int advice(vector<Place>& database);
