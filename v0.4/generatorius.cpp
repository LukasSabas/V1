#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <exception>
#include <chrono>
#include "laikmatis.h"
#include "generatorius.h"
int generatorius(int& a, int& b, double& c) {
	Timer uu;
	std::ofstream myfile("duomenys.txt");
	std::string v = "Vardas";
	std::string p = "Pavarde";
	std::string n = "ND";
	if (myfile.is_open()) {
		myfile << "Vardas              Pavarde             ";
		for (int i = 0;i < b;i++) {
			auto s = std::to_string(i + 1);
			myfile << std::left << std::setw(5) << n+s;
		}
		myfile << "Egz" << std::endl;
		srand(time(0));
		for (int i = 0;i < a;i++) {
			auto s = std::to_string(i+1);
			myfile << std::left <<std::setw(20)<< v+s << std::left << std::setw(20) << p+s;
			for (int j = 0;j < b + 1;j++) {
				myfile << std::left << std::setw(5) << rand() % 10 + 1;
			}
			myfile << std::endl;
		}
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	myfile.close();
	c = uu.elapsed();
	return 0;
}