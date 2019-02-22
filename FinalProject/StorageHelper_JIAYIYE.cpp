using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include "StorageHelper.h"



double  StorageHelper::getStockPrice(string name)//get price for a stock, for option 1 2 3 4,random fun works here,return -1 if fail to get price
{
	ifstream outFile1("Result_1.txt");
	ifstream outFile2("Result_2.txt");

	//random select from file1 and file2

	if (outFile1)
	{
		srand((unsigned)time(NULL));


		string a, b, c;

		int jump = 1 + rand() % 10;
		if (jump >= 5)
		{
			string temp = quickSearch("Result_1.txt", name);
			if (temp == "fail")
			{
				return -1;
			}
			istringstream sin1(temp);

			sin1 >> a >> b >> c;

			return atof(b.c_str());

		}
		else
		{
			string temp =quickSearch("Result_2.txt", name);
			if (temp == "fail")
			{
				return -1;
			}
			istringstream sin1(temp);

			sin1 >> a >> b >> c;

			return atof(b.c_str());
		}


	}
	outFile1.close();
	outFile2.close();
	return -1;
}
string StorageHelper::getLastLine(string filename)
{
	string out;
	ifstream outFile(filename);
	do {
	} while (getline(outFile, out));
	outFile.close();
	return out;
}

string	StorageHelper::getWordInLine(string line, int num)
{

	if (line == "fail")
	{
		return "fail";
	}
	stringstream strline(line);
	string temp;
	int count = 0;
	while ((getline(strline, temp, '\t') && (++count != num)))
	{
		
	}
	return temp;
}

void StorageHelper ::addToLastLine(string filename, string input)
{
	ofstream infile;
	infile.open(filename, ios::app);
	if (infile.fail())
	{
		cout << filename << "openfail"<<endl;
		return;
	}
	infile << input ;
	infile.close();
}

void StorageHelper::clearFile(string filename)
{
	fstream  test(filename, ios::out);
	test.close();
}

string StorageHelper::getTimeandDate()
{
	time_t nowtime;
	nowtime = time(NULL); //获取日历时间   
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
	return string(tmp);
}

void StorageHelper::printfile(string filename)
{
	ifstream outFile1(filename);
	string temp;
	while (getline(outFile1, temp))
	{
		cout << temp<<endl;
	}
	outFile1.close();
}

//寻找关键字，返回那一行
string StorageHelper::quickSearch(string filename, string searchKey)
{
	
	ifstream outFile1(filename);
	string temp;
	string fail ="fail";
	while (getline(outFile1, temp))
	{
		stringstream strline(temp);
		string word;
		int count = 0;
		while (getline(strline, word, '\t'))
		{
			if (word == searchKey)
			{
				return temp;
			}
		}
		
	}
	outFile1.close();
	return fail;
}

int StorageHelper::getFileSize(string filename)
{
	ifstream outFile1(filename);
	string temp;
	int count=0;
	while (getline(outFile1, temp))
	{
		count++;
	}
	outFile1.close();
	return count;
}

string StorageHelper::toString(double num)
{
	stringstream out;
	out << num;
	return out.str();
}
string StorageHelper::toString(double num, int presci)
{
	stringstream out;
	out << fixed << setprecision(presci) << num;
	return out.str();

}

double StorageHelper::stringWith$Todouble(string str)
{
	if (str[0]=='$')
	{
		return stod(str.erase(0, 1));
	}
	else
	{
		return stod(str);
	}
	
}



