#include "main.h"
#include "loadData.h"
#include "tripAdvisor.h"

//funkcja do wyœwietlania bazy danych
void printDataBase(vector <Place> dataBase)
{
	system("cls");
	if (dataBase.size() == 0)
	{
		cout << "Database is empty!" << endl;
		system("PAUSE");
	}
	else
	{
		bool exit = false;
		int i = 0;
		while (exit == false)
		{
			// wypisanie obiektu z bazy danych o indeksie i
			system("cls");
			cout << "Database size: " << to_string((int)dataBase.size()) << endl << endl;
			cout << "Object nr. " + to_string(i + 1)<<endl;
			cout << "Country: " + dataBase[i].getCountry(1) << endl;
			cout << "City: " + dataBase[i].getCity(1) << endl;
			cout << "Rest type: " + dataBase[i].getTypeOfRest(1) << endl;
			if (dataBase[i].getCostOfRest() == 0)
			{
				cout << "Cost of rest: Free" << endl;
			}
			else
			{
				cout << "Cost of rest: " + to_string(dataBase[i].getCostOfRest()) + " PLN" << endl;
			}
			cout << "Purpose of rest: " + dataBase[i].getPurposeOfRest(1) << endl;
			if (dataBase[i].getAdditionalActivitiesName() != "")
			{
				cout << "Additional activities: " + dataBase[i].getAdditionalActivitiesName(1) << endl;
			}
			else
			{
				cout << "Additional activities: None" << endl;
			}
			cout << "Transport to the place of rest: " + dataBase[i].getTransportToThePlaceOfRest(1) << endl << endl;
			//w zale¿noœci od wielkoœci bazy danych oraz aktualnie wybranego obiektu zostan¹ wyœwietlone opcje do wypisywania kolejnych obiektów z bazy danych
			if (i != 0)
			{
				if (i == dataBase.size()-1)
				{
					cout << "1. Show previous object" << endl;
					cout << "2. Close database preview" << endl;
					//wczytanie przez u¿ytkownika liczby na bazie stringa
					switch (insertDataInt("Your choice: ", 2))
					{
					case 1: 
					{
						i--;
						break;
					}
					case 2:
					{
						exit = true;
						break;
					}
					}
				}
				else
				{
					cout << "1. Show previous object" << endl;
					cout << "2. Show next object" << endl;
					cout << "3. Close database preview" << endl;
					//wczytanie przez u¿ytkownika liczby na bazie stringa
					switch (insertDataInt("Your choice: ", 3))
					{
					case 1:
					{
						i--;
						break;
					}
					case 2:
					{
						i++;
						break;
					}
					case 3:
					{
						exit = true;
						break;
					}
					}
				}
			}
			else
			{
				cout << "1. Show next object" << endl;
				cout << "2. Close database preview" << endl;
				//wczytanie przez u¿ytkownika liczby na bazie stringa
				switch (insertDataInt("Your choice: ", 2))
				{
				case 1:
				{
					i++;
					break;
				}
				case 2:
				{
					exit = true;
					break;
				}
				}
			}
		}
	}
}
//funkcja do wyœwietlania g³ównego menu programu
int printMenuAndTakeInput()
{
	system("cls");
	cout << "Trip advisor!" << endl;
	cout << "by Michal Aleksandrowicz and Jakub Bauer." << endl;
	cout << "1. Print database" << endl;
	cout << "2. Add an object to the database" << endl;
	cout << "3. Find a place for a trip" << endl;
	cout << "4. Exit" << endl;
	//wczytanie przez u¿ytkownika liczby na bazie stringa
	return insertDataInt("Your choice: ", 4);
}
//cia³o g³ównej funkcji programu
int main()
{
	vector <Place> dataBase;
	system("cls");
	cout << "Please wait, database is generated..." << endl;
	//wywo³anie funkcji do generowania bazy danych
	generateData(dataBase, 1000);
	while (1)
	{
		//wywo³anie funkcji do wczytywania bazy danych z pliku tekstowego
		loadData(dataBase);
		//wywo³anie funkcji do wyœwietlania g³ównego menu programu oraz odebranie wartoœci wpisanej przez u¿ytkownika
		switch (printMenuAndTakeInput())
		{
		case 1:
		{
			//wywo³anie funkcji do wyœwietlania bazy danych
			printDataBase(dataBase);
			break;
		}
		case 2:
		{
			//wywo³anie funkcji dodawania nowego rekordu w bazie danych
			addData(dataBase);
			break;
		}
		case 3:
		{
			//wywo³anie funkcji doradczej nie jest mo¿liwe w przypadku pustej bazy danych
			if (dataBase.size() != 0)
			{
				//wywo³anie g³ównej funkcji doradczej
				advice(dataBase);
			}
			else
			{
				cout << "Database is empty!" << endl;
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}