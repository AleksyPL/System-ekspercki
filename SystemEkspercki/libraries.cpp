#include "libraries.h"

//zmienia dany string na ma�e litery
string stringToLower(string data)
{
	transform(data.begin(), data.end(), data.begin(), tolower);
	return data;
}
//funkcja do pobierania liczby na bazie stringa
int insertDataInt(string comment, int max)
{
	//obs�uga wyj�tk�w
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
		//pobieranie ci�gu znak�w a� do wci�ni�cia klawisza ENTER lub osi�gni�cia limitu
		temp = getchar();
		if (temp == EOF || temp == '\n')
		{
			break;
		}
		result += temp;
	} while (result.length() < 200);
	return result;
}