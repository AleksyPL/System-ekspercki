#pragma once
#include "libraries.h"
#include "place.h"

void deleteFromDataBase(vector<Place>& database, string question, string answer); //funkcja do usuwania wynik�w z roboczej bazy danych
void printResult(vector<Place>& object); //funkcja do wy�wietlenia wyniku
bool databaseIsEmpty(vector<Place>& database); //funkcja m�wi�ca o braku dopasowania
int advice(vector<Place>& database); //cia�o g��wnej funkcji doradczej
