#include "tripAdvisor.h"

void deleteFromDataBase(vector<Place>& database, string question, string answer)
{
	if (question == "country")
	{
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getCountry() != answer)
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
	else if (question == "type")
	{
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getTypeOfRest() != answer)
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
	else if (question == "cost")
	{
		int cost = stoi(answer);
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getCostOfRest() >= cost)
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
	else if (question == "purpose")
	{
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getPurposeOfRest() != answer)
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
	else if (question == "transport")
	{
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getTransportToThePlaceOfRest() != answer && database[i].getTransportToThePlaceOfRest() != "any")
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
	else if (question == "additional")
	{
		for (int i = 0; i < database.size(); i++)
		{
			if (database[i].getAdditionalActivitiesName() != answer)
			{
				database.erase(database.begin() + i);
				i--;
			}
		}
	}
}
bool databaseIsEmpty(vector<Place>& database)
{
	if ((int)database.size() == 0)
	{
		cout << "None of the solutions in the database overlap with your answers." << endl;
		system("PAUSE");
		return true;
	}
	else
	{
		return false;
	}
}
void printResult(vector<Place>& object)
{
	int randomNumber;
	if(object.size()==1)
	{
		randomNumber = 0;
	}
	else
	{
		randomNumber = rand() % object.size();
	}
	system("cls");
	cout << "Your result is:" << endl;
	cout << "Country: " + object[randomNumber].getCountry(1) << endl;
	cout << "City: " + object[randomNumber].getCity(1) << endl;
	cout << "Type of rest: " + object[randomNumber].getTypeOfRest(1) << endl;
	if (object[randomNumber].getCostOfRest() == 0)
	{
		cout << "Cost of rest: Free" << endl;
	}
	else
	{
		cout << "Cost of rest: " + to_string(object[randomNumber].getCostOfRest()) + " PLN" << endl;
	}
	cout << "Purpose of rest: " + object[randomNumber].getPurposeOfRest(1) << endl;
	if (object[randomNumber].getAdditionalActivitiesName() != "")
	{
		cout << "Additional activities: " + object[randomNumber].getAdditionalActivitiesName(1) << endl;
	}
	else
	{
		cout << "Additional activities: None" << endl;
	}
	cout << "Transport to the place of rest: " + object[randomNumber].getTransportToThePlaceOfRest(1) << endl << endl;
	system("PAUSE");
}
int advice(vector<Place>& database)
{
	system("cls");
	{
		cout << "What type of vacation do you prefer?" << endl;
		cout << "1. Active" << endl;
		cout << "2. Passive" << endl;
		int questionTypeOfRest = insertDataInt("Your choice: ", 2);
		if (questionTypeOfRest == 1)
		{
			deleteFromDataBase(database, "type", "active");
		}
		else if (questionTypeOfRest == 2)
		{
			deleteFromDataBase(database, "type", "passive");
		}
		if (databaseIsEmpty(database) == true)
		{
			return 0;
		}
	}
	{
		cout << endl << "What is your travel budget?" << endl;
		int questionCost = insertDataInt("Your budget in PLN: ", 10000);
		deleteFromDataBase(database, "cost", to_string(questionCost));
		if (databaseIsEmpty(database) == true)
		{
			return 0;
		}
	}
	{
		cout << endl << "What is your purpose in travel?" << endl;
		cout << "1. Sport" << endl;
		cout << "2. Relax" << endl;
		cout << "3. Food" << endl;
		cout << "4. Art" << endl;
		cout << "5. Culture" << endl;
		cout << "6. None" << endl;
		int questionPurpose = insertDataInt("Your choice: ", 6);
		if (questionPurpose == 1)
		{
			deleteFromDataBase(database, "purpose", "sport");
		}
		else if (questionPurpose == 2)
		{
			deleteFromDataBase(database, "purpose", "relax");
		}
		else if (questionPurpose == 3)
		{
			deleteFromDataBase(database, "purpose", "food");
		}
		else if (questionPurpose == 4)
		{
			deleteFromDataBase(database, "purpose", "art");
		}
		else if (questionPurpose == 5)
		{
			deleteFromDataBase(database, "purpose", "culture");
		}
		else if (questionPurpose == 6)
		{
			deleteFromDataBase(database, "purpose", "none");
		}
		if (databaseIsEmpty(database) == true)
		{
			return 0;
		}
	}
	{
		cout << endl << "Which of the additional activity you would like to do during your vacation?" << endl;
		cout << "1. Go to a concert" << endl;
		cout << "2. Visit the museum" << endl;
		cout << "3. Horse riding" << endl;
		cout << "4. Quad riding" << endl;
		cout << "5. Balloon flight" << endl;
		cout << "6. Other" << endl;
		cout << "7. Any" << endl;

		int questionAdditional = insertDataInt("Your choice: ", 6);
		if (questionAdditional == 1)
		{
			deleteFromDataBase(database, "additional", "concert");
		}
		else if (questionAdditional == 2)
		{
			deleteFromDataBase(database, "additional", "museum");
		}
		else if (questionAdditional == 3)
		{
			deleteFromDataBase(database, "additional", "horse ride");
		}
		else if (questionAdditional == 4)
		{
			deleteFromDataBase(database, "additional", "quad ride");
		}
		else if (questionAdditional == 5)
		{
			deleteFromDataBase(database, "additional", "balloon fight");
		}
		else if (questionAdditional == 6)
		{
			deleteFromDataBase(database, "additional", "none");
		}
		if (databaseIsEmpty(database) == true)
		{
			return 0;
		}
	}
	{
		cout << endl << "How do you want to get to your vacation destination?" << endl;
		cout << "1. Car" << endl;
		cout << "2. Plane" << endl;
		cout << "3. Ship" << endl;
		cout << "4. Motorbike" << endl;
		cout << "5. Any method" << endl;
		int questionTransport = insertDataInt("Your choice: ",5);
		if (questionTransport == 1)
		{
			deleteFromDataBase(database, "transport", "car");
		}
		else if (questionTransport == 2)
		{
			deleteFromDataBase(database, "transport", "plane");
		}
		else if (questionTransport == 3)
		{
			deleteFromDataBase(database, "transport", "ship");
		}
		else if (questionTransport == 4)
		{
			deleteFromDataBase(database, "transport", "motorbike");
		}
		if (databaseIsEmpty(database) == true)
		{
			return 0;
		}
	}

	printResult(database);
	return 0;
}