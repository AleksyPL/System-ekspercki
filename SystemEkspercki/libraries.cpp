#include "libraries.h"

string stringToLower(string data)
{
	transform(data.begin(), data.end(), data.begin(), tolower);
	return data;
}
int insertDataInt(string comment, int max)
{
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
string insertDataString(string comment)
{
	cout << comment;
	string result;
	char temp;
	do
	{
		temp = getchar();
		if (temp == EOF || temp == '\n')
		{
			break;
		}
		result += temp;
	} while (result.length() < 200);
	return result;
}
