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

PLYGINIMAI:

Nuskaitymas iš failo:
|Tipas| 1000 laikas| 10000 laikas| 100000 laikas| 1000000 laikas| 10000000 laikas|
|--- | --- | --- | --- | --- | --- |
|List| 0.012s | 0.135s | 1.193s | 10.261s | 89.886s |
|Vector| 0.010s | 0.110s | 0.919s | 5.808s | 54.313s |
*********************
Rūšiavimas į dvi dalis:
|Tipas| 1000 laikas| 10000 laikas| 100000 laikas| 1000000 laikas| 10000000 laikas|
|--- | --- | --- | --- | --- | --- |
|List| 0.019s | 0.104s | 0.935s | 7.611s | 108.215s |
|Vector| 0.013s | 0.099s | 0.854s | 7.959s | 77.982s | 
********************
Visas veikimas užtruko:
|Tipas| 1000 laikas| 10000 laikas| 100000 laikas| 1000000 laikas| 10000000 laikas|
|--- | --- | --- | --- | --- | --- |
|List| 0.049s | 0.410s | 3.571s | 26.987s | 306.140s |
|Vector|0.041s | 0.381s | 3.217s | 25.165s | 238.419s |

----------------
v1.0 Atlikti darbai:

1. Ištirti du nauji skirstymo būdai: skirstymas į du naujus listus/vektorius ir vienų duomenų perkėlimas į naują listą/vektorių.

Visų trijų skirstymų playginimas:

LIST:
|Duomenų kiekis|Laikas iš karto rašant| Laikas skirstant| Laikas perkeliant ir trinant|
| --- | --- | --- | --- |
|1000| 0.019s| 0.001s| 0.0009s|
|10000| 0.104s| 0.012s| 0.009s|
|100000| 0.935s| 0.120s| 0.079s|
|1000000| 7.611s| 1.254s| 2.261s|
|10000000| 108.215s| 22.409s| 129.890s|
******************
VECTOR:
|Duomenų kiekis|Laikas iš karto rašant| Laikas skirstant| Laikas perkeliant ir trinant|
| --- | --- | --- | --- |
|1000| 0.013s| 0.0003s| 0.0004s|
|10000| 0.099s| 0.003s| 0.002s|
|100000| 0.854s| 0.028s| 0.027s|
|1000000| 7.959s| 0.298s| 0.360s|
|10000000| 77.982s| 153.689s| 13.022s|

******************************

Naudojimosi instrukcija:
1. Programoje galima skaityti mokinius ir jų pažymius iš .txt failo, generuoti atistiktinai arba surašyi paleidus programą.
2. Galima galutinį pažymį skaičiuoti pagal namų darbų vidurkį arba medianą.
3. Duomenis galima išvesti į ekraną arba į .txt failą.
4. Duomenis išvedant į ekraną galima pasirinkti norimą mokinių rūšiavimo būdą: iškarto rašyti į failą, skirstyti į atskirus masyvus ir išvesti, kopijuoti duomenis iš pradinio masyvo į kitą ir juos panaikinti iš pirmojo.
5. Viską galimą atlikti naudojant list arba vector.
6. Norimus veiksmus galėsti pasirinkti paleidus programą.
7. Prieš pradedant naudotis programa reikia turėti .txt failus su 1000, 10000, 100000, 1000000, 10000000 eilučių duomenų, kai namų darbų yra 10. Arba pasinaudoti generatoriumi ir susikurti.
