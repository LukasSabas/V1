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
#include "lstudentas.h"
void skirstymas(std::vector <studentas>& s, int& a, int& b, double& c, std::list <lstudentas>& ss, double& d) {
	//lstudentas* ptr = ss;
	int g;
	std::cout << "Iveskite ar norite skirstyti pagal vidurki '0', ar pagal mediana '1':" << std::endl;
	std::cin >> g;
	Timer uu;
	std::string n = "ND";
	std::ofstream mf1("moksliukai.txt");
	std::ofstream mf2("tinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << "Vardas              Pavarde             Galutinis"<<std::endl;
		mf2 << "Vardas              Pavarde             Galutinis"<<std::endl;
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
	Timer ll;
	std::ofstream li1("listmoksliukai.txt");
	std::ofstream li2("listtinginiai.txt");
	if (li1.is_open() && li2.is_open()) {
		li1 << "Vardas              Pavarde             Galutinis" << std::endl;
		li2 << "Vardas              Pavarde             Galutinis" << std::endl;
		for (int i = 0;i < a;i++) {
			auto it1 = std::next(ss.begin(), 0);
			lstudentas ptr = *it1;
			if (g == 0) {
				if (ptr.galv < 5) {
					li2 << std::left << std::setw(20) << ptr.pav << std::left << std::setw(20) << ptr.var << ptr.galv << std::endl;
				}
				else {
					li1 << std::left << std::setw(20) << ptr.pav << std::left << std::setw(20) << ptr.var << ptr.galv << std::endl;
				}
			}
			else {
				if (ptr.galm < 5) {
					li2 << std::left << std::setw(20) << ptr.pav << std::left << std::setw(20) << ptr.var << ptr.galm << std::endl;
				}
				else {
					li1 << std::left << std::setw(20) << ptr.pav << std::left << std::setw(20) << ptr.var << ptr.galm << std::endl;
				}
			}
			ss.pop_front();
		}
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	li1.close();
	li2.close();
	d = ll.elapsed();
}
//0.085