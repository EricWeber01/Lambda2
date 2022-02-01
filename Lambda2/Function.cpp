#include "Header.h"
Country::Country()
{
	Load();
}
void Country::Add(string country, string city)
{
	base[country].push_back(city);
}
void Country::Load()
{
	ifstream fout("base.json");
	if (fout.is_open() && fout.peek() != EOF)
	{
		string str, temp;
		while (getline(fout, str))
			temp += str;
		if (!temp.empty())
			base = json::parse(temp);
	}
	fout.close();
}
void Country::Show()
{
	for (const auto& n : base.items())
	{
		cout << "\n\n" << (string)n.key() << "\n------------\n";
		for (int i = 0; i < base[n.key()].size(); i++)
			cout << (string)base[n.key()][i] << endl;
	}
}
void Country::DeleteCity(string city)
{
	for (const auto& n : base.items())
	{
		for (int i = 0; i < base[n.key()].size(); i++)
			if ((string)base[n.key()][i] == city)
				base[n.key()].erase(base[n.key()].begin() + i);
	}
}
void Country::DeleteCountry(string country)
{

	if (base.contains(country))
		base.erase(country);

}
void Country::Count()
{
	int cnt = 0;
	for (const auto& n : base.items())
	{
		for (int i = 0; i < base[n.key()].size(); i++)
			cnt++;
	}
	cout << "Всего городов: " << cnt;
}
void Country::Search(string city)
{
	for (const auto& n : base.items())
	{
		for (int i = 0; i < base[n.key()].size(); i++)
			if ((string)base[n.key()][i] == city)
				cout << endl << n.key() << " - " << base[n.key()][i] << endl;
	}
}
Country::~Country()
{
	ofstream fout("base.json");
	fout << base.dump(2);
	fout.close();
};