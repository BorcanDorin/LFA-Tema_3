// Tema 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  '*' e cuvantul vid
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#define DIM 100

using namespace std;

int nrNeterminale;
char neterminale[DIM];
vector <string> vect[DIM];
vector <string> words[DIM];

int getLoc(char ch)
{
	for (auto i = 0; i < nrNeterminale; i++)
		if (neterminale[i] == ch)
			return i;
	return -1;
}

void generateGRM(const int n, const int length, const int poz_neterminal, string word)   // lungime maxima, lungime la nivel recursiv, pozitie neterminal
{
	if (length > n)
		return;
	for (auto& i : vect[poz_neterminal])
	{
		if (i.length() == 2)
		{
			auto cp = word + i[0];
			generateGRM(n, length + 1, getLoc(i[1]), cp);
		}
		else
		{
			if (i[0] == '*') 
				words[length].push_back(word);
			else
			{
				auto cp = word + i[0];
				words[length + 1].push_back(cp);
			}
		}
	}
}

void read()
{
	const string msg = "Introduceti nr neterminalelor: ";
	const string msg1="Introduceti neterminalele:\n";
	const string msg2 = "Introduceti nr productiilor: ";
	const string msg3 = "Introduceti lungimea cuvintelor generate de gramatica: ";
	string str;
	
	int nProd, n;
	char ch;

	cout << msg;
	cin >> nrNeterminale;
	cout << msg1;
	for (auto i = 0; i < nrNeterminale; i++)
		cin >> neterminale[i];

	cout << msg2;
	cin >> nProd;
	for (auto i = 0; i < nProd; i++)
	{
		cout << "Productia " << i + 1 << ":\n";
		cin >> ch;
		cin >> str;
		vect[getLoc(ch)].push_back(str);
	}

	cout << msg3;
	cin >> n;
	generateGRM(n, 0, 0, "");
	cout << endl;
	for (auto i = 1; i <= n; i++)
	{
		cout << "n = " << i << ": ";
		for (const auto& j : words[i])
			cout << j << " ";
		cout << endl;
	}
}

int main()
{
	read();
	return 0;
}