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
#include "studentas.h"
#include "galutinis.h"
#include "isvedimas.h"
#include "ivedimas.h"
#include "teigiamas.h"
#include "generatorius.h"
#include "skirstymas.h"
#include "laikmatis.h"

using namespace std;

int main()
{
	int m, t = 0, q, l, d;
	float g;
	double laikas1,laikas2,laikas3;
	cout << "Iveskite kiek norite sugeneruoti duomenu ir kiek turi buti namu darbu" << endl;
	cin >> l;
	cin >> d;
	generatorius(l, d,laikas1);
	std::vector<studentas> stud;
	cout << "Jeigu norite ivesti duomenis dabar spauskite '1', jeigu norite, kad duomenys butu sakitomi is failo spauskite '0':" << endl;
	cin >> q;
	if (q == 0) {
		ifstream f;
		f.open("duomenys.txt");
		if (f.is_open()) {
			m = 0;
			string o, b;
			getline(f, b);
			int k = 0, g = 0;
			while (g < b.length()) {
				if (b[g] == ' ' && b[g + 1] != ' ') {
					k = k + 1;
				}
				g = g + 1;
			}
			k = k - 2;
			while (getline(f, o))
			{
				m = m + 1;
			}
			f.close();
			Timer kk;
			f.open("duomenys.txt");
			if (getline(f, b))
				stud.reserve(m);
			studentas st;
			for (int i = 0;i < m;i++) {
				int suma = 0;
				f >> st.pav >> st.var;
				for (int j = 0;j < k; j++) {
					int a;
					f >> a;
					st.nd.push_back(a);
					suma = suma + st.nd[j];
				}
				f >> st.egz;
				st.vid = suma / k;
				int z = 0;
				int ilgis;
				ilgis = st.nd.size();
				while (z < ilgis-1) {
					for (int i = z + 1; i < ilgis; i++) {
						if (st.nd[z] < st.nd[i]) {
							std::swap(st.nd[z], st.nd[i]);
						}
					}
					z++;
				}
				if (ilgis % 2 == 0) {
					st.med = (st.nd[ilgis / 2 - 1] + st.nd[ilgis / 2]) / 2;
				}
				else {
					st.med = st.nd[(ilgis + 1) / 2 - 1];
				}
				stud.push_back(st);
				st.nd.clear();
			}
			f.close();
			laikas2 = kk.elapsed();
		}
	}
	else {
		cout << "Iveskite kiek yra studentu:" << endl;
		cin >> m;
		try {
			cout << teigiamas(m) << endl;
		}
		catch (std::invalid_argument& e) {
			cerr << e.what() << endl;
		}
		stud.reserve(m);
		studentas st;
		for (int i = 0;i < m;i++) {
			ivedimas(st);
			stud.push_back(st);
			st.nd.clear();
			cin.ignore(10000, '\n');
		}
	}
	for (int i = 0; i < m;i++) {
		galutinis(stud[i]);
	}
	std::sort(stud.begin(), stud.end(), [](const studentas& a, const studentas& b) {
		return a.pav < b.pav;
		});
	cout << "Jei norite duomenu ekrane spauskite '0', jei norite duomenis suskirstytus isvesti i faila spauskite '1':" << endl;
	int y;
	cin >> y;
	if (y == 1) {
		skirstymas(stud, l, d, laikas3);
	}
	else {
		cout << "Pavarde             Vardas           Galutinis(Vid.) Galutinis(Med.)" << endl;
		cout << "------------------------------------------------------------------  " << endl;
		for (int i = 0; i < m; i++) {
			isvedimas(stud[i]);
		}
		laikas3 = 0;
	}
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << l << " Eiluciu sukurimas uztruko:  " << laikas1<<endl;
	cout << l << " Eiluciu nuskaitymas uztruko: " << laikas2<<endl;
	if (laikas3 != 0) {
		cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus uztruko: " << laikas3 << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------" << endl;
}
