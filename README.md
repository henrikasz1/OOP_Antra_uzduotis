# OOP_Antra_uzduotis
# Antroji objektinio programavimo uzduotis
# v1.0 versija:
-----------------------------------------------------------
 Programa apdoroja naudotojo ivestus duomenis (vardas, pavarde, pazymiai, egzamino rezultatas) ir apskaiciuoja kiekvieno mokinio galutini rezultata pagal mediana arba vidurki.
-----------------------------------------------------------


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

-Programa patariama pasijungti per CodeBlocks IDE ir atsidaryti cbp faila arba isskleisti folderi, jame atsidaryti BASH arba CMD ir suvesti g++ main.cpp funkcijos.cpp | ./a.exe

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
