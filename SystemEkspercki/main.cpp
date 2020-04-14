#include "main.h"
#include "loadData.h"
#include "tripAdvisor.h"

void printDataBase(vector <Place> dataBase)
{
	system("cls");
	if (dataBase.size() == 0)
	{
		cout << "Database is empty!" << endl;
	}
	else
	{
		bool exit = false;
		int i = 0;
		while (exit == false)
		{
			system("cls");
			cout << "Object nr. " + to_string(i + 1) << endl;
			cout << "Country: " + dataBase[i].getCountry(1) << endl;
			cout << "City: " + dataBase[i].getCity(1) << endl;
			cout << "Type of rest: " + dataBase[i].getTypeOfRest(1) << endl;
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
			if (i != 0)
			{
				if (i == dataBase.size()-1)
				{
					cout << "1. Show previous object" << endl;
					cout << "2. Close database preview" << endl;
					int choice = insertDataInt("Your choice: ", 2);
					switch (choice)
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
					int choice = insertDataInt("Your choice: ", 3);
					switch (choice)
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
				int choice = insertDataInt("Your choice: ", 2);
				switch (choice)
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

int printMenuAndTakeInput()
{
	system("cls");
	cout << "Trip advisor!" << endl;
	cout << "by Michal Aleksandrowicz and Jakub Bauer." << endl;
	cout << "1. Print database" << endl;
	cout << "2. Add an object to the database" << endl;
	cout << "3. Find a place for a trip" << endl;
	cout << "4. Close a program" << endl;
	return insertDataInt("Your choice: ", 4);
}

int main()
{
	vector <Place> dataBase;
	system("cls");
	cout << "Please wait, database is generated..." << endl;
	generateData(dataBase,1000);
	while (1)
	{
		loadData(dataBase);
		int menuInput = printMenuAndTakeInput();
		switch (menuInput)
		{
		case 1:
		{
			printDataBase(dataBase);
			break;
		}
		case 2:
		{
			addData(dataBase);
			break;
		}
		case 3:
		{
			if (dataBase.size() != 0)
			{
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