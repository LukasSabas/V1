#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <exception>
#include <stdexcept>
#include "studentas.h"
#include "galutinis.h"
#include "isvedimas.h"
#include "ivedimas.h"
#include "teigiamas.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int m,t = 0, q,l,d;
	float g;
	std::vector<studentas> stud;
	cout << "Jeigu norite ivesti duomenis dabar spauskite '1', jeigu norite, kad duomenys butu sakitomi is failo spauskite '0':" << endl;
	cin >> q;
	if (q == 0) {
		ifstream f;
		f.open("Studentai10000.txt");
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
			f.open("Studentai10000.txt");
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
				while (z < 4) {
					for (int i = z + 1; i < 5; i++) {
						if (st.nd[z] < st.nd[i]) {
							std::swap(st.nd[z], st.nd[i]);
						}
					}
					z++;
				}
				st.med = st.nd[3];
				stud.push_back(st);
				st.nd.clear();
			}
			f.close();
		}
	}
	else {
		cout << "Iveskite kiek yra studentu:" << endl;
		cin >> m;
		try {
			cout << teigiamas(m)<<endl;
		}
		catch (std::invalid_argument& e) {
			cerr <<e.what()<< endl;
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
	cout << "Pavarde             Vardas           Galutinis(Vid.) Galutinis(Med.)" << endl;
	cout << "------------------------------------------------------------------  " << endl;
	for (int i = 0; i < m; i++) {
		isvedimas(stud[i]);
	}
}
