#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
	string var, pav;
	float* nd;
	float egz;
	float med;
	double vid;
	double gal;
};

void ivedimas(studentas& s);
void galutinis(studentas& s, float& g);
void isvedimas(studentas& s);

int main()
{
	int m, t;
	float g;
	cout << "Iveskite kiek yra studentu:" << endl;
	cin >> m;
	studentas* st;
	st = new (std::nothrow) studentas[m];
	for (int i = 0;i < m;i++) {
		ivedimas(st[i]);
	}

	cout << "Iveskite ar norite galutinio pazymio su vidurkiu ar mediana. Jei vidurkiu iveskite 0, jei mediana iveskite 1:" << endl;
	cin >> t;
	if (t == 0) {
		for (int i = 0;i < m;i++) {
			g = st[i].vid;
			galutinis(st[i], g);
		}
	}
	else {
		for (int i = 0;i < m;i++) {
			g = st[i].med;
			galutinis(st[i], g);
		}
	}
	int j = 0;
	while (j < m - 1) {
		for (int i = j + 1; i < m;i++) {
			if (st[j].gal < st[i].gal) {
				std::swap(st[j], st[i]);
			}
		}
		j++;
	}
	cout << "Pavarde             Vardas           Galutinis:" << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < m; i++) {
		isvedimas(st[i]);
	}
}

void ivedimas(studentas& s) {
	int k;
	float suma = 0;
	cout << "Iveskite mokinio varda ir pavarde:" << endl;
	cin >> s.var;
	cin >> s.pav;
	cout << "Iveskite namu darbu uzduociu kieki, jei nezinote iveskite '-1', jei norite, kad butu generuojami atsitiktinai iveskite '-2':" << endl;
	cin >> k;
	if (k == -1) {
		s.nd = new float[25];
		cout << "Iveskite pazymius, kai baigsite iveskite '0':" << endl;
		k = 0;
		int p = 1;
		while (p > 0) {
			int n;
			cin >> n;
			if (n > 0) {
				s.nd[p - 1] = n;
				suma = suma + s.nd[p - 1];
				p++;
				k++;
			}
			else {
				p = 0;
				break;
			}
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
		s.nd = new float[k];
		srand(time(0));
		for (int i = 0; i < k; i++) {
			s.nd[i]=rand() % 10 + 1;
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
	else if (k > 0) {
		cout << "Iveskite pazymius:" << endl;
		s.nd = new float[k];
		for (int i = 0; i < k; i++) {
			cin >> s.nd[i];
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
		cout << "Iveskite egzamino ivertinima:" << endl;
		cin >> s.egz;
	}
	else if (k == 0) {
		cout << "Ivedete jog mokinys visai neturi pazymiu is namu darbu, jeigu tai tiesa dar krta irasykite '0', jei suklydote irasykite tikraji skaiciu namu darbu" << endl;
		cin >> k;
		if (k > 0) {
			cout << "Iveskite pazymius:" << endl;
			s.nd = new float[k];
			for (int i = 0; i < k; i++) {
				cin >> s.nd[i];
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
void isvedimas(studentas& s) {
	cout << std::left << std::setw(20) << s.pav;
	cout << std::left << std::setw(17) << s.var;
	cout << std::fixed << std::setprecision(2) << s.gal << endl;
}
void galutinis(studentas& s, float& g) {
	if (g == 0) {
		s.gal = 0.6 * s.egz;
	}
	else {
		s.gal = 0.4 * g + 0.6 * s.egz;
	}
}