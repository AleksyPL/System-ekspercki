#pragma once
#include "libraries.h"
#include "place.h"

void deleteFromDataBase(vector<Place>& database, string question, string answer); //funkcja do usuwania wyników z roboczej bazy danych
void printResult(vector<Place>& object); //funkcja do wyœwietlenia wyniku
bool databaseIsEmpty(vector<Place>& database); //funkcja mówi¹ca o braku dopasowania
int advice(vector<Place>& database); //cia³o g³ównej funkcji doradczej
