#include <iostream>
#include <algorithm>
#include <string> 
#include <windows.h>
#include <fstream>

using namespace std;

class Adress
{
private:
	string* mass_adress;
public:
	Adress(int amount,ifstream &ifile)
	{
		string something;
		mass_adress = new string[amount];
		for (int i = 0; i < 4; i++)
		{
			ifile >> something;
			mass_adress[i] = something;
		}
	}
	string get_city()
	{
		return mass_adress[0];
	}
	void adress_to_file(ofstream &ofile)
	{
		for (int i = 0; i < 4; i++)
		{
			ofile << mass_adress[i];
			if (i != 3)
			{
				ofile << ", ";
			}
		}
		ofile << endl;
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
	string* city = new string[amount];

	Adress adress1(amount,ifile);
	city[0] = adress1.get_city();

	Adress adress2(amount,ifile);
	city[1] = adress2.get_city();

	Adress adress3(amount,ifile);
	city[2] = adress3.get_city();

	Adress adress4(amount,ifile);
	city[3] = adress4.get_city();

	Adress adress5(amount,ifile);
	city[4] = adress5.get_city();

	sort(city, city + amount);

	ofile << amount << endl;
	for (int i = 0; i < amount; i++)
	{
		if (city[i] == adress1.get_city())
		{
			adress1.adress_to_file(ofile);
		}
		if (city[i] == adress2.get_city())
		{
			adress2.adress_to_file(ofile);
		}
		if (city[i] == adress3.get_city())
		{
			adress3.adress_to_file(ofile);
		}
		if (city[i] == adress4.get_city())
		{
			adress4.adress_to_file(ofile);
		}
		if (city[i] == adress5.get_city())
		{
			adress5.adress_to_file(ofile);
		}
	}

}