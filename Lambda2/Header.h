#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace nlohmann;
using namespace std;

class Country
{
private:
	json base;
public:
	Country();
	void Add(string country, string city);
	void Load();
	void Show();
	void DeleteCity(string city);
	void DeleteCountry(string country);
	void Count();
	void Search(string city);
	~Country();
};