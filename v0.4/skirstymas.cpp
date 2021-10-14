#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include "laikmatis.h"
#include "skirstymas.h"
#include "studentas.h"
void skirstymas(std::vector <studentas>& s, int& a, int& b, double& c) {
	int g;
	std::cout << "Iveskite ar norite skirstyti pagal vidurki '0', ar pagal mediana '1':" << std::endl;
	std::cin >> g;
	Timer uu;
	std::string n = "ND";
	std::ofstream mf1("moksliukai.txt");
	std::ofstream mf2("tinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << "Vardas              Pavarde             Egz"<<std::endl;
		mf2 << "Vardas              Pavarde             Egz"<<std::endl;
		for (int i = 0;i < a;i++) {
			if (g == 0) {
				if (s[i].galv < 5) {
					mf2 << std::left << std::setw(20) << s[i].pav << std::left << std::setw(20) << s[i].var << s[i].galv << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << s[i].pav << std::left << std::setw(20) << s[i].var << s[i].galv << std::endl;
				}
			}
			else {
				if (s[i].galm < 5) {
					mf2 << std::left << std::setw(20) << s[i].pav << std::left << std::setw(20) << s[i].var << s[i].galm << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << s[i].pav << std::left << std::setw(20) << s[i].var << s[i].galm << std::endl;
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
