#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
class StorageHelper
{
public:
	

	string getLastLine(string filename);//get the last line of a certain file
	string getWordInLine(string line, int num);//get the num th word at one line
	void addToLastLine(string filename, string input);//add string to last of file
	void clearFile(string filename);//make the file empty

	string getTimeandDate();//return the time and date as string format

	void printfile(string filename);//print the whole file

	string quickSearch(string filename, string searchKey);//find a certain string in the file and return the line

	int getFileSize(string filename);

	string toString(double num);
	string toString(double num, int presci);
	double getStockPrice(string name);

	double stringWith$Todouble(string);
private:
}; 

