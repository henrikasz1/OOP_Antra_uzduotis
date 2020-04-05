# OOP_Antra_uzduotis
# Antroji objektinio programavimo uzduotis
# v0.1 versija:
-----------------------------------------------------------
 Programa apdoroja naudotojo ivestus duomenis (vardas, pavarde, pazymiai, egzamino rezultatas) ir apskaiciuoja kiekvieno mokinio galutini rezultata pagal mediana arba vidurki.


# V0.1 versija ir programos funkcionalumas:
 1) Programa reikalauja ivesti mokinio varda (naudojant netinkamus vardui elementus, prasoma ivesti varda is naujo)
 
 2) Programa reikalauja ivesti mokinio pavarde (naudojant netinkamus vardui elementus, prasoma ivesti pavarde is naujo)
 
 3) Leidziama pasirinkti, ar namu darbu rezultatus nori ivesti pats naudotojas, jei ne, juos atsitiktiniu budu sugeneruoja programa
 
 4) Programa reikalauja ivesti mokinio egzamino rezultata (ivedus non_integer tipo kintamaji/per dideli arba maza skaiciu, programa reikalauja pakartotinai ivesti rezultata is naujo)
 
 5) Programa klausia, ar mokinio vidurki skaiciuoti paprastai, ar medianos budu
 
 6) Programa klausia, ar naudotojas nori ivesti dar vieno mokinio duomenis
 
# v0.2 versija:

1) Pakeistas random skaiciu generavimas, dabar kiekviena karta skaiciai bus skirtinti(pagal laika)
2) Pakeistas vardo ir pavardes ivedimo tikrinimas (ankstesnese versijose kartais crash'indavo)
3) Sulygiuota duomenu lentele, todel dabar ja daug lengviau skaityti
4) Nuo siol galima pasirinkti, ar duomenis naudotojas nori nuskaityti is failo, ar juos ivesti
5) Programa isveda surikiuotus duomenis pagal varda (arba jeigu vardas toks pats, pagal pavarde)
6) Isimtas pasirinkimas, ar apskaiciuoti galutini rezultata mediana, ar vidurkiu (pagal uzduoties salyga)

# v0.3 versija:

1) Ideta try/catch, kuris patikrina, ar failas, kuri nori nuskaityti, egzistuoja
2) Programa padalinta i header ir cpp failus

-Programa patariama pasijungti per CodeBlocks IDE ir atsidaryti cbp faila arba isskleisti folderi, jame atsidaryti BASH arba CMD ir suvesti g++ main.cpp functions.cpp | ./a.exe

# v0.4 versija:

Sukurta nauja programos funkcija, kuri gali sugeneruoti 5 random failus(dydziai: 1000, 10000, 100000, 1000000, 10000000)
Si nauja funkcija sugeneruoja faila, ji is naujo nuskaito ir galiausiai padalina i du failus (protingi/neprotingi). Taip pat si funkcija isveda kiekvieno etapo ivykdymo laika.

Pvz:
Kai random failo dydis - 1000 ir namu darbu kiekis - 10, programa isveda:<br/>
<br/>
 Failo dydis: 1000 <br/>
 Faila sugeneravo per: 15.607 ms<br/>
 Faila nuskaite per: 31.248 ms<br/>
 Studentus surusiavo ir isvede i naujus failus per: 15.642ms<br/>
 Bendras laikas: 78.1ms<br/>
 
 # v0.5 versija:
----------------
# Kompiuteris

CPU: Intel Core i5-4210U<br/>
GPU: Intel HD 4400 (Mobile 1.0/1.1 GHz)<br/>
SSD: Kingston SUV300S37A240G 240GB<br/>
RAM: Samsung M471B1G73DB0-YK0 1x8GB<br/>
MBD: Toshiba SATELLITE L50-B<br/>
<br/>

 # Vector
 
 Namu darbu pasirinktas kiekis: 5 <br/>
 <br/>
Failo dydis: 1000<br/>
Faila sugeneravo per: 21.953 ms<br/>
Faila nuskaite per: 11.994 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 16.988ms<br/>
Bendras laikas: 69.965ms<br/>
<br/>
Failo dydis: 10000<br/>
Faila sugeneravo per: 80.972 ms<br/>
Faila nuskaite per: 110.937 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 145.926ms<br/>
Bendras laikas: 362.789ms<br/>
<br/>
Failo dydis: 100000<br/>
Faila sugeneravo per: 925.467 ms<br/>
Faila nuskaite per: 1295.26 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 1595.09ms<br/>
Bendras laikas: 3832.82ms<br/>
<br/>
Failo dydis: 1000000<br/>
Faila sugeneravo per: 8100.71 ms<br/>
Faila nuskaite per: 12212.9 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 15482.4ms<br/>
Bendras laikas: 35811.9ms<br/>

# Deque

Failo dydis: 1000<br/>
Faila sugeneravo per: 18.97 ms<br/>
Faila nuskaite per: 12.993 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 16.974ms<br/>
Bendras laikas: 72.916ms<br/>
<br/>
Failo dydis: 10000<br/>
Faila sugeneravo per: 89.948 ms<br/>
Faila nuskaite per: 134.92 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 150.927ms<br/>
Bendras laikas: 404.792ms<br/>
<br/>
Failo dydis: 100000<br/>
Faila sugeneravo per: 825.526 ms<br/>
Faila nuskaite per: 1556.11 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 1960.88ms<br/>
Bendras laikas: 4372.49ms<br/>
<br/>
Failo dydis: 1000000<br/>
Faila sugeneravo per: 9281.68 ms<br/>
Faila nuskaite per: 14590.6 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 19093.2ms<br/>
Bendras laikas: 42985.4ms<br/>

# List

Failo dydis: 1000<br/>
Faila sugeneravo per: 15.585 ms<br/>
Faila nuskaite per: 15.623 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 15.645ms<br/>
Bendras laikas: 78.061ms<br/>
<br/>
Failo dydis: 10000<br/>
Faila sugeneravo per: 78.14 ms<br/>
Faila nuskaite per: 109.349 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 171.86ms<br/>
Bendras laikas: 374.977ms<br/>
<br/>
Failo dydis: 100000<br/>
Faila sugeneravo per: 859.325 ms<br/>
Faila nuskaite per: 1046.81 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 1499.9ms<br/>
Bendras laikas: 3421.63ms<br/>
<br/>
Failo dydis: 1000000<br/>
Faila sugeneravo per: 7968.19 ms<br/>
Faila nuskaite per: 10686.8 ms<br/>
Studentus surusiavo ir isvede i naujus failus per: 18436.2ms<br/>
Bendras laikas: 37122.4ms<br/>


# v1.0 versija
--------------
* Programa pakeista, naudojant skirtingas strategijas kiekvienam konteineriui
* Prideta cmake

  Tam, kad ja panaudoti, atidarykite konsole ir iveskite
  
  $     cmake .
  

# strategija_1
 
  Isskirti bendra konteineri i du atskirus konteinerius:
  
  
  | Size |  Vector |   Deque |  List  |
  |------|---------|---------|--------|
  |1000  |  2.996ms|  1.997ms| 1.554ms|
  |10000 | 17.918ms| 15.899ms| 8.995ms|
  |100000| 181.77ms|156.495ms| 84.51ms|
  
  * Isvada - Vector < Deque < List (siai strategijai efektyviausia naudoti List konteineri)
  
# strategija_2

 Naudoti bendra konteineri, is kurio bus istrinti netinkami duomenys ir sukelti i naujai sukurta konteineri
       
       
  | Size |    Vector   |     Deque   |  List  |
  |------|-------------|-------------|--------|
  |1000  |    108.934ms|      46.87ms|     1ms|
  |10000 |    10749.3ms|    4312.19ms| 5.994ms|
  |100000| Nesulaukiau | Nesulaukiau |67.962ms|
  
 * Isvada - sis budas yra labai "skausmingas" vector ir deque konteiniariams, taciau stipriai pagreitina list konteinerio veikima
       
# strategija su algoritmu

 * Naudojamas konteineris - vektorius
 * Naudojamas algoritmas - std::stable_partition

  | Size |  Strategy_1 |  Strategy_2_algorithm |
  |------|-------------|-----------------------|
  |1000  |  2.996ms    |        1.976ms        |
  |10000 | 17.918ms    |       15.496ms        |
  |100000| 181.77ms    |      149.398ms        |
  
  * Isvada - naudojamas algoritmas zenkliai paspartina programa
  
  
  * Bendra isvada -  tokiu atveju yra geriau naudotis 2 strategija del atminties ir vykydymo laiko mazinimo. Geriausiai darba rusiuojant atlieka list konteineris (arba galima panaudoti ir kitus konteinerius, naudojant algoritmus).
