// FCFS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

struct proces
{
	int id;
	int czas_trw;
	
};


void sre_czas_ocze(ofstream &zapis,proces proc[], int n)
{

	int *ocz = new int[n];
	ocz[0] = 0;
	float sr_czas1=0,sr_czas;
	
	for (int i = 1; i < n; i++)
		ocz[i] = proc[i - 1].czas_trw + ocz[i - 1];

	for (int i = 0; i < n; i++)
		sr_czas1 += ocz[i];
		
	zapis << "Czas oczekiwania: " << endl;
	for (int i = 0; i < n; i++)
		zapis << ocz[i] << " ";
	zapis<<endl;
	sr_czas = sr_czas1 / 3;
	
	zapis << "Sredni czas oczekiwania: \n" << sr_czas << endl;
}


void kolejnosc_wyk(ofstream &zapis, proces proc[], int n)
{
	zapis << "Kolejnosc wykonywania procesow: " << endl;
	for (int i = 0; i < n; i++)
	{
		zapis << proc[i].id << " ";
	}
	zapis << endl;
	sre_czas_ocze(zapis,proc, n);
}
void sr_czas_wyk(ofstream &zapis,proces proc[], int n)
{
	float a = 0,b;
	for (int i = 0; i < n; i++)
		a += proc[i].czas_trw;
	b = a / 3;
	zapis << "Sredni czas wykonania: \n" << b;
}


int main()
{
	ifstream czytanie("plik.txt");
	ofstream zapis("wyjscie.txt");


	int a,b;
	int il_li = 0; //ilosc linii

	//1//sprawdzenie ile jest odwolan w pliku wejsc.
	if (czytanie.is_open()) {

		while (czytanie >> a >> b)
		{
			il_li++;
		}
	}
	else
	{
		cout << "Problem z odczytem pliku wejsciowego :/";
	}
	czytanie.close();
	//EndOf_1//
	
	proces proc[5];

	int x = 0; //zmienna pomocnicza
	ifstream czytanie2("plik.txt");

	if (czytanie2.is_open()) {

		while (czytanie2 >> a >> b)
		{
			proc[x] = { a,b };
			x++;
		}
	}
	else
	{
		cout << "Problem z odczytem pliku wejsciowego :/";
	}
	czytanie2.close();
	//EndOf_2//

	int n = il_li;
	kolejnosc_wyk(zapis,proc, n);
	sr_czas_wyk(zapis,proc, n);
	cout << "Sukces! Prosze sprawdzic plik wyjsciowy :)";
	zapis.close();
	

}


