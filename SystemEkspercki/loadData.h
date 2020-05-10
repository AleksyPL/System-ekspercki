#pragma once
#include "libraries.h"
#include "place.h"

class TempPlace : public Place
{
public:
	bool valid;
	TempPlace(); //konstruktor
	void clearData(); //funkcja do czyszczenia danych w obiekcie
	void isValid(vector<Place>& database); //sprawdzenie poprawnoœci wpisanych danych
	void copyData(vector<Place>& database); //funkcja do przekopiowania danych do bazy danych
};
void overrideDataBase(vector<Place>& database); //funkcja do nadpisania bazy danych
bool alreadyInDataBase(TempPlace temp, vector<Place>& database); //funkcja do sprawdzania czy dany obiekt jest ju¿ w bazie danych
void loadData(vector <Place> &database); //funkcja do wczytywania bazy danych z pliku tekstowego
void addData(vector <Place> &database); //funkcja do dodawania nowego rekordu w bazie danych
void generateData(vector<Place>& database, int howMany); //funkcja do generowania bazy danych