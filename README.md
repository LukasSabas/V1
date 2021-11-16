# V1
--------------
v0.1 Atlikti veiksmai:

1. Sukurta struktrūra "studentas";
2. Sukurta void funkcija "ivedimas";
3. Paskaičiuotas galutinis atsakymas pagal namų darbų pažymių vidurkį;
4. Sukurta void funkcija "isvedimas";
5. Pridėta galimybė galutinį įvertinimą skaičiuoti pagal namų darbų medianą;
6. Mokiniai išrikiuoti pagal galutinį įvertinimą mažėjimo tvarka;
7. Papildyta atveju, ka daryti kai namų darbų nėra.
----------------------------------
v0.1(Vektorius) Atlikti veiksmai:

1. Visi duomenys daugomi vektoriuje;
2. Namų darbai taip pat saugomi vektoriuje, kuris yra struktūros vektoriuje;
3. Pridėta galimybės namų darbų pažymius įvedinėti, net ir nežinant kiek jų yra;
4. Pridėta galimybės pažymius generuoti atsitiktinai;
------------------
v0.1(Dinaminis_Masyvas) Altikti veiksmai:

1. Visi duomenys saugomi tradiciniame dinaminiame masyve;
2. Namų darbai taip pat saugomi dinaminiame masyve, kuris yra stuktūros dinaminiame masyve;
3. Pridėta galimybę pažymius įvedinėti, net ir nežinant kiek jų yra.
4. Pridėta galimybė pažymius į dinaminį masyvą generuoti atsitiktinai;
------------------------
v0.2 Atlikti darbai:

1. Papildyta su galimybe duomenis nuskaityti iš failo;
2. Rikiavimas pakeistas, kad rikiuotu pavardes pagal abecele(A-Z), o jei pavardės lygios tai pagal vardus;
3. Papildyta, kad išvedime būtų galutinis įvertinimas pagal namų darbų vidurkį ir pagal medianą.
-------------------------
v0.3 Atlikti darbai:
1. Visos funkcijos ir strukturos buvo perkelta į .h ir .cpp failus;
2. Reikiamoje vietoje buvo panaudotas išimčių valdymas;
3. Patobulintas rūšiavimo metodas.
-----------------------
v0.4 Atlikti darbas:
1. Galimybė generuoti i failą norimą kieki mokinių su jų namų darbai;
2. Mokiniai yra rūšiuojami i gerus ir blogus mokinius pagal ju galutinį įvertinimą;
3. Surūšiuoti studentai yra surašomi į failą;
4. Testuojamas programos veikimo laikas(failų kūrimas, duomenų nuskaitymas, studentų rūšiavimas ir surašymas į failus).
------------------------
v0.5 Atlikti darbai:
1. Galimybė dirbti su std::list vietoje std::vector;
2. Skaičiuojamas programos darbo laikas su std::list.

Sistemos parametrai:
RAM- 8GB;
CPU- Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz   2.71 GHz;
SSD- 237GB.

PALYGINIMAI
100 eilučių:
List nuskaitymas iš failo:      0.001s;
List rūšiavimas į dvi grupes:   0.002s;
Visas veikimas užtruko:         0.009s;

Vector nuskaitymas iš failo:    0.001s;
Vector rūšiavimas š dvi grupes: 0.002s;
Visas veikimas užtruko:         0.009s;

*****************
1000 eilučių:
List nuskaitymas iš failo:      0.012s;
List rūšiavimas į dvi grupes:   0.019s;
Visas veikimas užtruko:         0.049s;

Vector nuskaitymas iš failo:    0.010s;
Vector rūšiavimas š dvi grupes: 0.013s;
Visas veikimas užtruko:         0.041s;
*****************
10000 eilučių:
List nuskaitymas iš failo:      0.135s;
List rūšiavimas į dvi grupes:   0.104s;
Visas veikimas užtruko:         0.410s;

Vector nuskaitymas iš failo:    0.110s;
Vector rūšiavimas š dvi grupes: 0.099s;
Visas veikimas užtruko:         0.381s;
*****************
100000 eilučių:
List nuskaitymas iš failo:      1.193s;
List rūšiavimas į dvi grupes:   0.935s;
Visas veikimas užtruko:         3.571s;

Vector nuskaitymas iš failo:    0.919s;
Vector rūšiavimas š dvi grupes: 0.854s;
Visas veikimas užtruko:         3.217s;
*****************
1000000 eilučių:
List nuskaitymas iš failo:      10.261s;
List rūšiavimas į dvi grupes:   7.611s;
Visas veikimas užtruko:         26.987s;

Vector nuskaitymas iš failo:    5.808s;
Vector rūšiavimas š dvi grupes: 7.959s;
Visas veikimas užtruko:         25.165s;
*****************
