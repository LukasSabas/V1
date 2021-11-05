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
-----------
100 eilučių:
List nuskaitymas iš failo:      0.010s;
List rūšiavimas į dvi grupes:   0.012s;

Vector nuskaitymas iš failo:    0.006s;
Vector rūšiavimas š dvi grupes: 0.007s;

*****************
1000 eilučių:
List nuskaitymas iš failo:      0.080s;
List rūšiavimas į dvi grupes:   0.054s;

Vector nuskaitymas iš failo:    0.055s;
Vector rūšiavimas š dvi grupes: 0.032s;

*****************
10000 eilučių:
List nuskaitymas iš failo:      0.842s;
List rūšiavimas į dvi grupes:   0.510s;

Vector nuskaitymas iš failo:    0.550s;
Vector rūšiavimas š dvi grupes: 0.226s;

*****************
100000 eilučių:
List nuskaitymas iš failo:      8.443s;
List rūšiavimas į dvi grupes:   5.074s;

Vector nuskaitymas iš failo:    5.617s;
Vector rūšiavimas š dvi grupes: 2.160s;

*****************
1000000 eilučių:
List nuskaitymas iš failo:      65.363s;
List rūšiavimas į dvi grupes:   45.468s;

Vector nuskaitymas iš failo:    44.561s;
Vector rūšiavimas š dvi grupes: 21.573s;

*****************
