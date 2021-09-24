#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
	string var, pav;
	std::vector<int> nd = {};
	float egz;
	float med;
	double vid;
	double galm;
	double galv;
};

void ivedimas(studentas& s);
void galutinis(studentas& s);
void isvedimas(studentas& s);

int main()
{
	int m, t, q;
	float g;
	std::vector<studentas> stud;
	cout << "Jeigu norite ivesti duomenis dabar spauskite '1', jeigu norite, kad duomenys butu sakitomi is failo spauskite '0':" << endl;
	cin >> q;
	if (q == 0) {
		ifstream f;
		f.open("kursiokai.txt");
		if (f.is_open()) {
			m = 0;
			string o, s;
			getline(f, s);
			int k = 0, g = 0;
			while (g < s.length()) {
				if (s[g] == ' ' && s[g + 1] != ' ') {
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
			f.open("kursiokai.txt");
			if (getline(f, s))
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
	int j = 0;
	while (j < m - 1) {
		for (int i = j + 1; i < m;i++) {
			if (stud[j].pav > stud[i].pav or stud[j].pav == stud[i].pav && stud[j].var > stud[i].var) {
				std::swap(stud[j], stud[i]);
			}
		}
		j++;
	}
	cout << "Pavarde             Vardas           Galutinis(Vid.) Galutinis(Med.)" << endl;
	cout << "------------------------------------------------------------------  " << endl;
	for (int i = 0; i < m; i++) {
		isvedimas(stud[i]);
	}
}

void ivedimas(studentas& s) {
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
void isvedimas(studentas& s) {
	cout << std::left << std::setw(20) << s.pav;
	cout << std::left << std::setw(17) << s.var;
	cout << std::fixed << std::setprecision(2) << s.galv <<"            "<<std::fixed<<std::setprecision(2)<<s.galm<<endl;
}
void galutinis(studentas& s) {
	s.galv = s.vid * 0.4 + s.egz * 0.6;
	s.galm = s.med * 0.4 + s.egz * 0.6;
}