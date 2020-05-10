#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
using std::to_string;

string stringToLower(string data); //zmienia dany string na ma³e litery
int insertDataInt(string comment, int max); //funkcja do pobierania liczby na bazie stringa
string insertDataString(string comment); //funkcja do pobierania stringa