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
//#include "lstudentas.h"
void skirstymasl(std::list <studentas>& s, int& a, int& b, double& c) { /*std::vector <studentas>& s*/ /*std::list <lstudentas>& ss, double& d*/
	int g;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	std::cout << "Iveskite ar norite list skirstyti pagal vidurki '0', ar pagal mediana '1':" << std::endl;
	std::cin >> g;
	Timer uu;
	std::string n = "ND";
	std::ofstream mf1("listmoksliukai.txt");
	std::ofstream mf2("listtinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		mf2 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		for (auto& i : s) {
			if (g == 0) {
				if (i.galv < 5) {
					mf2 << std::left << std::setw(20) << i.pav << std::left << std::setw(20) << i.var << i.galv << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << i.pav << std::left << std::setw(20) << i.var << i.galv << std::endl;
				}
			}
			else {
				if (i.galm < 5) {
					mf2 << std::left << std::setw(20) << i.pav << std::left << std::setw(20) << i.var << i.galm << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << i.pav << std::left << std::setw(20) << i.var << i.galm << std::endl;
				}
			}
		}
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	mf1.close();
	mf2.close();
	c = uu.elapsed();
}