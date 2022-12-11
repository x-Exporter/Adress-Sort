#include <iostream>
#include <algorithm>
#include <string> 
#include <windows.h>
#include <fstream>

using namespace std;

class Adress
{
private:
	string city = "City";
	string street = "Street";
	int house_num = 0;
	int apartments_num = 0;
public:
	void set_info(ifstream& ifile)
	{
		ifile >> city;
		ifile >> street;
		ifile >> house_num;
		ifile >> apartments_num;
	}
	string get_city()
	{
		return city;
	}

	void put_adress(ofstream &ofile)
	{
		ofile << city << ", " << street << ", " << house_num << ", " << apartments_num << ", " << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);
	ifstream ifile("in.txt");
	ofstream ofile("out.txt");
	int amount;
	string something;
	ifile >> amount;
	Adress *addresses = new Adress[amount];
	string* city = new string[amount];
	
	for (int i = 0; i < amount; i++)
	{
		addresses[i].set_info(ifile);
	}
	for (int i = 0; i < amount; i++)
	{
		city[i] = addresses[i].get_city();
	}
	sort(city, city + amount);
	ofile << amount << endl;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if (city[i] == addresses[j].get_city())
			{
				addresses[j].put_adress(ofile);
			}
		}
	}
	delete[] addresses;
	delete[] city;
}