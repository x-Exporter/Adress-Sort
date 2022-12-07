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
			cout << mass_city[i] << endl;
			i++;
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


}

//string massiv[]{ "груша", "яблоко", "апельсин", "авокадо", "ананас" };
//sort(massiv, massiv + 5);
//for (int i = 0; i < sizeof(massiv) / sizeof(massiv[0]); i++)
//{
//    cout << massiv[i] << endl;
//}