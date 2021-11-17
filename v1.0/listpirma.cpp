#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <iterator>
#include <list>
#include "laikmatis.h"
#include "skirstymas.h"
#include "studentas.h"
void listdalinimas(std::list <studentas>& s, int& a, int& b, double& c) {
	int g;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	std::list<studentas> ting;
	std::list<studentas> moks;
	std::cout << "Iveskite ar norite list skirstyti pagal vidurki '0', ar pagal mediana '1':" << std::endl;
	std::cin >> g;
	Timer uu;
	if (g == 0) {
		std::copy_if(s.begin(), s.end(), back_inserter(ting), [](studentas &i) {return i.galv < 5;});
		std::copy_if(s.begin(), s.end(), back_inserter(moks), [](studentas &i) {return i.galv >= 5;});
	}
	else {
		std::copy_if(s.begin(), s.end(), back_inserter(ting), [](studentas &i) {return i.galm < 5;});
		std::copy_if(s.begin(), s.end(), back_inserter(moks), [](studentas &i) {return i.galm >= 5;});
	}
	c = uu.elapsed();
	std::ofstream mf1("listmoksliukai.txt");
	std::ofstream mf2("listtinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		mf2 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		if (g == 0) {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.pav << std::left << std::setw(20) << t.var << t.galv << std::endl;
			}
			for (auto& m : moks) {
				mf1 << std::left << std::setw(20) << m.pav << std::left << std::setw(20) << m.var << m.galv << std::endl;
			}
		}
		else {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.pav << std::left << std::setw(20) << t.var << t.galm << std::endl;
			}
			for (auto& m : moks) {
				mf1 << std::left << std::setw(20) << m.pav << std::left << std::setw(20) << m.var << m.galm << std::endl;
			}
		}
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	mf1.close();
	mf2.close();
}