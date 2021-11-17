#ifndef studentas_h
#define studentas_h
#include <iostream>
#include <vector>
#include <list>

struct studentas {
	std::string var;
	std:: string pav;
	std::vector<int> nd = {};
	std::list<int> ndl = {};
	double egz;
	float med;
	double vid;
	double galm;
	double galv;
};
#endif