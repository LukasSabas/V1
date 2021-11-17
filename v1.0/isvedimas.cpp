#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "isvedimas.h"
#include "studentas.h"
using std::cout;
using std::endl;

void isvedimas(struct studentas& s) {
	cout << std::left << std::setw(20) << s.pav;
	cout << std::left << std::setw(17) << s.var;
	cout << std::fixed << std::setprecision(2) << s.galv << "            " << std::fixed << std::setprecision(2) << s.galm << endl;
}