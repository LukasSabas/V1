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
#include "laikmatis.h"
#include "ivedimas.h"
#include "studentas.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;


void ivedimas(struct studentas& s) {
	int k;
	float suma = 0;
	cout << "Iveskite mokinio varda ir pavarde:" << endl;
	cin >> s.var;
	cin >> s.pav;
	cout << "Iveskite namu darbu uzduociu kieki jei zinote jei nezinote irasykit '-1', jei norite kad viskas butu generuojama atsitiktinai irasykite '-2':" << endl;
	cin >> k;
	if (k == -1) {
		int p = 1;
		k = 0;
		cout << "Kai ivesite 0 tai teiks 'STOP'" << endl;
		cout << "Iveskite pazymius:" << endl;
		while (p > 0) {
			int n;
			cin >> n;
			if (n > 0) {
				s.nd.push_back(n);
				suma = suma + s.nd[p - 1];
				p++;
			}
			else {
				p = 0;
				break;
			}
			k = s.nd.size();
		}
		if (k == 0) {
			s.vid = 0;
			s.med = 0;
			cout << "Iveskite egzamino ivertinima:" << endl;
			cin >> s.egz;
		}
		else {
			s.vid = suma / k;
			int z = 0;
			while (z < k - 1) {
				for (int i = z + 1; i < k; i++) {
					if (s.nd[z] < s.nd[i]) {
						std::swap(s.nd[z], s.nd[i]);
					}
				}
				z++;
			}
			if (k % 2 == 0) {
				s.med = (s.nd[k / 2 - 1] + s.nd[k / 2]) / 2;
			}
			else {
				s.med = s.nd[(k + 1) / 2 - 1];
			}
			cout << "Iveskite egzamino ivertinima:" << endl;
			cin >> s.egz;
		}
	}
	else if (k == -2) {
		cout << "Iveskite kiek pazymiu reikia" << endl;
		cin >> k;
		srand(time(0));
		for (int i = 0; i < k; i++) {
			s.nd.push_back(rand() % 10 + 1);
			suma = suma + s.nd[i];
		}
		s.vid = suma / k;
		int z = 0;
		while (z < k - 1) {
			for (int i = z + 1; i < k; i++) {
				if (s.nd[z] < s.nd[i]) {
					std::swap(s.nd[z], s.nd[i]);
				}
			}
			z++;
		}
		if (k % 2 == 0) {
			s.med = (s.nd[k / 2 - 1] + s.nd[k / 2]) / 2;
		}
		else {
			s.med = s.nd[(k + 1) / 2 - 1];
		}
		srand(time(0));
		s.egz = rand() % 10 + 1;
	}
	else {
		if (k > 0) {
			cout << "Iveskite pazymius:" << endl;
			int p = 0;
			while (p < k) {
				int n;
				cin >> n;
				if (n > 0) {
					s.nd.push_back(n);
					suma = suma + s.nd[p];
					p++;
				}
				else {
					p = k;
					break;
				}
			}
			s.vid = suma / k;
			int z = 0;
			while (z < k - 1) {
				for (int i = z + 1; i < k; i++) {
					if (s.nd[z] < s.nd[i]) {
						std::swap(s.nd[z], s.nd[i]);
					}
				}
				z++;
			}
			if (k % 2 == 0) {
				s.med = (s.nd[k / 2 - 1] + s.nd[k / 2]) / 2;
			}
			else {
				s.med = s.nd[(k + 1) / 2 - 1];
			}
			cout << "Iveskite egzamino ivertinima:" << endl;
			cin >> s.egz;
		}
		if (k == 0) {
			cout << "Ivedete jog mokinys visai neturi pazymiu is namu darbu, jeigu tai tiesa dar krta irasykite '0', jei suklydote irasykite tikraji skaiciu namu darbu" << endl;
			cin >> k;
			if (k > 0) {
				cout << "Iveskite pazymius:" << endl;
				int p = 0;
				while (p < k) {
					int n;
					cin >> n;
					if (n > 0) {
						s.nd.push_back(n);
						suma = suma + s.nd[p];
						p++;
					}
					else {
						p = k;
						break;
					}
				}
				s.vid = suma / k;
				int z = 0;
				while (z < k - 1) {
					for (int i = z + 1; i < k; i++) {
						if (s.nd[z] < s.nd[i]) {
							std::swap(s.nd[z], s.nd[i]);
						}
					}
					z++;
				}
				if (k % 2 == 0) {
					s.med = (s.nd[k / 2 - 1] + s.nd[k / 2]) / 2;
				}
				else {
					s.med = s.nd[(k + 1) / 2 - 1];
				}
				cout << "Iveskite egzamino ivertinima:" << endl;
				cin >> s.egz;
			}
			else {
				s.vid = 0;
				s.med = 0;
				cout << "Iveskite egzamino ivertinima:" << endl;
				cin >> s.egz;
			}
		}
	}
}