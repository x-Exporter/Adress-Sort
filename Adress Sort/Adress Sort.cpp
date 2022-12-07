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
	string* mass_city;
public:
	Adress(int amount)
	{
		mass_adress = new string[amount * 4];
		mass_city = new string[amount];
	}

	void set_adress(string something, int i)
	{
		mass_adress[i] = something;
	}

	void set_mass_city(int amount)
	{
		int i = 0;
		for (int j = 0; j < amount * 4; j += 4)
		{
			mass_city[i] = mass_adress[j];
			i++;
		}
	}

	void sort_mass_city(int amount)
	{
		sort(mass_city, mass_city + amount);
	}
	void final_result(int amount,ofstream &ofile)
	{
		ofile << amount << endl;
		for (int i = 0; i < amount; i++)
		{
			int j = 0;
			while (mass_city[i] != mass_adress[j])
			{
				j++;
			}		
			ofile << mass_adress[j] << ", " << mass_adress[j + 1] << ", " << mass_adress[j + 2] << ", " << mass_adress[j + 3] << endl;
		}
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
	Adress adress(amount);
	for (int i = 0; i < amount * 4; i++)
	{
		ifile >> something;
		adress.set_adress(something, i);
	}
	adress.set_mass_city(amount);
	adress.sort_mass_city(amount);
	adress.final_result(amount,ofile);
}