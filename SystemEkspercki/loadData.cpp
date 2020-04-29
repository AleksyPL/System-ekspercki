#include "loadData.h"

TempPlace::TempPlace()
{
	clearData();
}
void TempPlace::clearData()
{
	this->country = "";
	this->city = "";
	this->costOfRest = 0;
	this->typeOfRest = "";
	this->purposeOfRest = "";
	this->additionalActivitiesName = "";
	this->transportToThePlaceOfRest = "";
}
void TempPlace::copyData(vector<Place>& database)
{
	if (this->valid == true)
	{
		Place goalPlace;
		goalPlace.setCountry(this->getCountry());
		goalPlace.setCity(this->getCity());
		goalPlace.setAdditionalActivitiesName(this->getAdditionalActivitiesName());
		goalPlace.setCostOfRest(this->getCostOfRest());
		goalPlace.setPurposeOfRest(this->getPurposeOfRest());
		goalPlace.setTransportToThePlaceOfRest(this->getTransportToThePlaceOfRest());
		goalPlace.setTypeOfRest(this->getTypeOfRest());
		database.push_back(goalPlace);
	}
	clearData();
}
void TempPlace::isValid(vector<Place>& database)
{
	vector <string> purpose = { "sport","relax","food","art","culture","none" };
	vector <string> additionalActivities = { "concert", "museum", "horse ride", "quad ride", "balloon flight", "none" };
	vector <string> transport = { "car","plane","ship","motorbike","any" };
	if (this->getCountry() != "" && this->getCity() != "" && this->getTypeOfRest() !="active" && this->getTypeOfRest() != "passive"
		&& std::find(additionalActivities.begin(), additionalActivities.end(), this->getAdditionalActivitiesName()) != additionalActivities.end()
		&& std::find(purpose.begin(), purpose.end(), this->getPurposeOfRest()) != purpose.end()
		&& std::find(transport.begin(), transport.end(), this->getTransportToThePlaceOfRest()) != transport.end())
	{
		if (alreadyInDataBase(*this, database) == false)
		{
			this->valid = true;
		}
		else
		{
			this->valid = false;
		}
	}
	else
	{
		this->valid = false;
	}
	copyData(database);
}
bool alreadyInDataBase(TempPlace temp, vector<Place>& database)
{
	for (int i = 0; i < (int)database.size(); i++)
	{
		if (temp.getCountry() == database[i].getCountry())
		{
			if (temp.getCity() == database[i].getCity())
			{
				if (temp.getCostOfRest() == database[i].getCostOfRest())
				{
					if (temp.getTypeOfRest() == database[i].getTypeOfRest())
					{
						if (temp.getPurposeOfRest() == database[i].getPurposeOfRest())
						{
							if (temp.getAdditionalActivitiesName() == database[i].getAdditionalActivitiesName())
							{
								if (temp.getTransportToThePlaceOfRest() == database[i].getTransportToThePlaceOfRest())
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			continue;
		}
	}
	return false;
}
void loadData(vector<Place>& database)
{
	database.clear();
	TempPlace temp;
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./DataBase.txt", ios::in);
	if (plik.fail() != true)
	{
		while (getline(plik, linia))
		{
			if (nr_linii % 8 == 0 && linia != "END")
			{
				temp.setCountry(linia);
			}
			else if (nr_linii % 8 == 1 && linia != "END")
			{
				temp.setCity(linia);
			}
			else if (nr_linii % 8 == 2 && linia != "END")
			{
				temp.setCostOfRest(atoi(linia.c_str()));
			}
			else if (nr_linii % 8 == 3 && linia != "END")
			{
				temp.setTypeOfRest(linia);
			}
			else if (nr_linii % 8 == 4 && linia != "END")
			{
				temp.setPurposeOfRest(linia);
			}
			else if (nr_linii % 8 == 5 && linia != "END")
			{
				temp.setAdditionalActivitiesName(linia);
			}
			else if (nr_linii % 8 == 6 && linia != "END")
			{
				temp.setTransportToThePlaceOfRest(linia);
			}
			else if (linia == "END")
			{
				temp.isValid(database);
				nr_linii = -1;
			}
			nr_linii++;
			linia = "";
		}
	}
	plik.close();
	overrideDataBase(database);
}
void overrideDataBase(vector<Place>& database)
{
	fstream plik;
	remove("./DataBase.txt");
	plik.open("./DataBase.txt", ios::out);
	for (int i = 0; i < (int)database.size(); i++)
	{
		plik << database[i].getCountry() << endl;
		plik << database[i].getCity() << endl;
		plik << database[i].getCostOfRest() << endl;
		plik << database[i].getTypeOfRest() << endl;
		plik << database[i].getPurposeOfRest() << endl;
		plik << database[i].getAdditionalActivitiesName() << endl;
		plik << database[i].getTransportToThePlaceOfRest() << endl;
		if (i == database.size() - 1)
		{
			plik << "END";
		}
		else
		{
			plik << "END" << endl;
		}
	}
	plik.close();
}
void addData(vector<Place> &database)
{
	system("cls");
	TempPlace tempObject;
	cout << "Adding a new object!" << endl;
	cout << "You do not need to enter data with the first uppercase letter." << endl;
	tempObject.setCountry(insertDataString("Insert a country: "));
	tempObject.setCity(insertDataString("Insert a city: "));
	tempObject.setCostOfRest(insertDataInt("Insert a cost of rest in PLN: ", 10000));
	tempObject.setTypeOfRest(stringToLower(insertDataString("Insert a type of rest (active or passive): ")));
	tempObject.setPurposeOfRest(insertDataString("Insert a purpose of rest (sport, relax, food, art, culture, none): "));
	tempObject.setAdditionalActivitiesName(insertDataString("Insert an additional activity name (concert, museum, horse ride, quad ride, balloon flight, none): "));
	tempObject.setTransportToThePlaceOfRest(insertDataString("Insert a transport to rest place method (car, plane, ship, motorbike, any): "));
	tempObject.isValid(database);
	overrideDataBase(database);
	loadData(database);
}
void generateData(vector<Place>& database, int howMany)
{
	srand((unsigned int)time(NULL));
	vector <string> countries;
	string linia;
	fstream plik;
	plik.open("./WorldCountries.txt", ios::in);
	if (plik.fail() != true)
	{
		while (getline(plik, linia))
		{
			countries.push_back(linia);
		}
	}
	else
	{
		countries.push_back("poland");
	}
	plik.close();
	vector <string> cities;
	plik.open("./WorldCities.txt", ios::in);
	if (plik.fail() != true)
	{
		while (getline(plik, linia))
		{
			cities.push_back(linia);
		}
	}
	else
	{
		cities.push_back("warsaw");
	}
	plik.close();
	vector <string> purpose = {"sport","relax","food","art","culture","none"};
	vector <string> additionalActivities = { "concert", "museum", "horse ride", "quad ride", "balloon flight", "none" };
	vector <string> transport = {"car","plane","ship","motorbike","any"};
	TempPlace temp;
	for (int i = 0; i < howMany; i++)
	{
		//generating countries
		int randomNumber = rand() % countries.size();
		temp.setCountry(countries[randomNumber]);
		//generating city
		randomNumber = rand() % cities.size();
		temp.setCity(cities[randomNumber]);
		//generating type of rest
		randomNumber = rand() % 2;
		if (randomNumber == 0)
		{
			temp.setTypeOfRest("active");
		}
		else
		{
			temp.setTypeOfRest("passive");
		}
		//generating cost
		randomNumber = rand() % 100;
		temp.setCostOfRest(100 * randomNumber);
		//genereting purpose
		randomNumber = rand() % purpose.size();
		temp.setPurposeOfRest(purpose[randomNumber]);
		//generating additional activities
		randomNumber = rand() % additionalActivities.size();
		temp.setAdditionalActivitiesName(additionalActivities[randomNumber]);
		//generating transport
		randomNumber = rand() % transport.size();
		temp.setTransportToThePlaceOfRest(transport[randomNumber]);
		temp.isValid(database);
	}
	overrideDataBase(database);
}