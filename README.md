Hash funkcijos paaiškinimas:
1. Prieš pradedant hashuoti inputa, inicializuojam int vertę pavadinimu "rnum" kuri nusako kiek kartų papildomai maišysim inputa, taip pat kitą int vertę "seedas" kuri naudojama kaip pradžia mūsų hashavimo algoritmui, ir int vertę "temp" - naudojamą laikinai savyje laikyti skaičius.
2. For cikle, kuris yra kartojamas tiek kartų kokio ilgio yra inputas, sulyginam "temp" vertę su kiekvieno simbolio esančio inputo stringe ASCII verte padauginta iš pozicijos stringe. Int vertę "seedas" maišom naudojant "mix" funkciją ir kaip parametrus naudojam "seedas" ir "temp" vertes. "mix" funkcijos pagalba yra sujungiamos sumaišytos "seedas" ir "temp" vertės.
3. Kitame for cikle mūsų "seedas" vertė yra toliau maišoma "rnum" kartų pasitelkiant "seedas" ir "temp" kaip funkcijos parametrus.
4. Sukuriamas naujas string tipo kintamasis "hstring" kuris bus naudojamas outputui išvesti.
5. For cikle, "seedas" vertė yra maišoma naudojant "seedas" ir "temp" kaip parametrus. Po kiekvieno maišymo prie "hstring" vertės yra pridedama šešioliktainė "seedas" vertė. Ciklas tęsiasi 8 kartus tam, kad išviso gautume 64 elementus kaip outputa
6. "hstring" yra sutumprinama iki 64 simbolių.

Ekspermentinis tyrimas ir rezultatų analizė:
Du skirtingi simboliai buvo įrašyti į 2 skirtingus failus - file1.txt ir file2.txt
![image](https://github.com/user-attachments/assets/de465af2-7664-4333-829e-db25512ec3e1)

![image](https://github.com/user-attachments/assets/6fe38dd4-0694-4378-b595-4ff3a8f45f9c)

file1.txt užkoduota vertė:

![image](https://github.com/user-attachments/assets/e7c423ce-fb36-4f12-a9e6-c6f43e3694b7)

file1.txt užkoduota vertė antrą  kartą paleidžiant kodą:

![image](https://github.com/user-attachments/assets/98d24283-0ac2-425f-ab24-a5cc1e84d6bc)

file2.txt užkoduota vertė:

![image](https://github.com/user-attachments/assets/5b2b6ec9-067d-48a0-ac06-5b0590928eb2)

file2.txt užkoduota vertė antrą  kartą paleidžiant kodą:

![image](https://github.com/user-attachments/assets/8cf18f7b-5609-4b1c-80a1-88c8cc42d19b)

Tiriamas funkcijos efektyvumas (4-as reikalavimas):

1 eilutės laikas:

<img width="576" alt="1 eil" src="https://github.com/user-attachments/assets/fdfd225d-3e83-444e-b67a-f1583d2151dc">

2 eilučių laikas:

<img width="576" alt="2 eil" src="https://github.com/user-attachments/assets/d143f628-50bd-456f-932b-f5ae4fd95e5f">

32 eilučių laikas:

<img width="576" alt="32 eil" src="https://github.com/user-attachments/assets/40c16e4f-252d-47e3-984e-0aea194a7ac6">

100 eilučių laikas:

<img width="576" alt="100 eil" src="https://github.com/user-attachments/assets/b1821dc5-742e-4079-9215-ed95f28a41d9">

300 eilučių laikas:

<img width="576" alt="300 2 eil" src="https://github.com/user-attachments/assets/c3a8d61d-1097-45fe-a6ee-864e0f3c6f7b">

600 eilučių laikas:

<img width="576" alt="600 4 eil" src="https://github.com/user-attachments/assets/8ff81cfb-216d-4904-96b0-38f582421645">

789 eilučių laikas:

<img width="576" alt="789 eil" src="https://github.com/user-attachments/assets/38899bc7-8f77-4278-9a85-19cf27c0a7fd">

Laikas didėjant eilučių skaičiui iš lėto didėjo.

Tikriname atsparumą koalizijai:

![image](https://github.com/user-attachments/assets/c7d85ab8-9d7b-4c6b-98bf-1dbcfe7b981a)

Jeigu iš nuskaitę failą būtume radę vienodas poras, programa būtų apie tai pranešus, bet kadangi nepranešė, vadinasi jų nėra.








