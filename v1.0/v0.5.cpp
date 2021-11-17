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
	double laikas1, laikas2, laikas3,skaitlaikas, suraslaikas;
	cout << "Iveskite kiek norite sugeneruoti duomenu ir kiek turi buti namu darbu" << endl;
	cin >> l;
	cin >> d;
	generatorius(l, d, laikas1);
	std::vector<studentas> stud;
	std::list<studentas> studl;
	struct lstudentas* ptr;
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
			/*
			for (auto &i: stud) {
				int suma = 0;
				f >> i.pav >> i.var;
				for (int j = 0;j < k;j++) {
					int a;
					f >> a;
					i.nd.push_back(a);
					suma = suma + i.nd[j];
				}
				f >> i.egz;
				i.vid = suma / k;
				int z = 0;
				int ilgis;
				ilgis = i.nd.size();
				while (z < ilgis - 1) {
					for (int j = z + 1; j < ilgis; j++) {
						if (i.nd[z] < i.nd[j]) {
							std::swap(i.nd[z], i.nd[j]);
						}
					}
					z++;
				}
				if (ilgis % 2 == 0) {
					i.med = (i.nd[ilgis / 2 - 1] + i.nd[ilgis / 2]) / 2;
				}
				else {
					i.med = i.nd[(ilgis + 1) / 2 - 1];
				}
				cout << "-*-*-*-*-*-*-*-*-*-"  << endl;
			}
			*/
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
				while (z < ilgis - 1) {
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
			//darbas su list
			Timer tt;
			f.open("duomenys.txt");
			if (getline(f, b)) {}
			studentas tarp;
			for (int i = 0;i < m;i++) {
				int suma;
				f >> tarp.var >> tarp.pav;
				for (int j = 0;j < k;j++) {
					int w;
					f >> w;
					tarp.ndl.push_back(w);
				}
				suma = 0;
				for (std::list<int>::iterator it = tarp.ndl.begin(); it != tarp.ndl.end(); ++it) {
					suma += *it;
				}
				f >> tarp.egz;
				tarp.vid = suma / k;
				int ilgis;
				tarp.ndl.sort();
				ilgis = tarp.ndl.size();
				if (ilgis % 2 == 0) {
					auto it1 = std::next(tarp.ndl.begin(), ilgis / 2 - 1);
					auto it2 = std::next(tarp.ndl.begin(), ilgis / 2 - 2);
					tarp.med = (*it1 + *it2) / 2;
				}
				else {
					auto it3 = std::next(tarp.ndl.begin(), (ilgis - 1) / 2);
					tarp.med = *it3;
				}
				tarp.galm = tarp.med * 0.4 + tarp.egz * 0.6;
				tarp.galv = tarp.vid * 0.4 + tarp.egz * 0.6;
				studl.push_back(tarp);
				tarp.ndl.clear();
			}
			f.close();
			skaitlaikas = tt.elapsed();
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
		int rasymas;
		cout << "Jei norite is karto rasyti i faila spauskite '0', jei norite dalinti i du failus spauskite '1', jei norite tik tinginius perkelti i kita faila spauskite '2':" << endl;
		cin >> rasymas;
		if (rasymas == 0) {
			skirstymas(stud, l, d, laikas3);
			skirstymasl(studl, l, d, suraslaikas);
		}
		if (rasymas == 1) {
			vectordalinimas(stud, l, d, laikas3);
			listdalinimas(studl, l, d, suraslaikas);
		}
		if (rasymas == 2) {
			vectorperkelti(stud, l, d, laikas3);
			listperkelti(studl, l, d, suraslaikas);
		}
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
	cout << l << " Eiluciu sukurimas uztruko:  " << laikas1 << endl;
	cout << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << l << " Eiluciu nuskaitymas i vector uztruko: " << laikas2 << endl;
	if (laikas3 != 0) {
		cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus is vector uztruko: " << laikas3 << endl;
	}
	cout << "---------------------------------------------PALYGINIMAS----------------------------------------------" << endl;
	cout << l << " Eiluciu nuskaitymas i list ustruko: " << skaitlaikas << endl;
	if (laikas3 != 0) {
		cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus is list uztruko: " << suraslaikas << endl;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;
	cout << l << " Eiluciu visa programa su vector veike: " << laikas1 + laikas2 + laikas3 << endl;
	cout << l << " Eiluciu visa programa su list veike: " << laikas1 + skaitlaikas + suraslaikas << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
}
