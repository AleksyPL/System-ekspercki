#include "libraries.h"

//zmienia dany string na ma³e litery
string stringToLower(string data)
{
	transform(data.begin(), data.end(), data.begin(), tolower);
	return data;
}
//funkcja do pobierania liczby na bazie stringa
int insertDataInt(string comment, int max)
{
	//obs³uga wyj¹tków
	try
	{
		int temp = stoi(insertDataString(comment));
		while (temp < 0 && temp > max)
		{
			temp = stoi(insertDataString(comment));
		}
		return temp;
	}
	catch (std::exception)
	{
		return 0;
	}
	return 0;
}
//funkcja do pobierania stringa
string insertDataString(string comment)
{
	cout << comment;
	string result;
	char temp;
	do
	{
		//pobieranie ci¹gu znaków a¿ do wciœniêcia klawisza ENTER lub osi¹gniêcia limitu
		temp = getchar();
		if (temp == EOF || temp == '\n')
		{
			break;
		}
		result += temp;
	} while (result.length() < 200);
	return result;
}