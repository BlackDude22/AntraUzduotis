# AntraUzduotis

## Vertinimas


- cmake
- releasai

## Programos tikslas
Programa skirta saugoti ir apdoroti studento duomenis bei išbandyti įvairius duomenų konteinerius.

Programa galima:
  1. Įvesti studento duomenis ranka.
  2. Įvesti studento duomenis iš failo*.
  3. Sugeneruoti studentų failą.
  4. Išvesti duomenų lentelę.
  5. Išbandyti `vector`, `list` ir `deque` duomenų konteinerius.

*Failo formatas Pavardė Vardas Pazymys1 ... PazymysN Egzaminas, kur N sveikasis skaicius nuo 1 iki 10.

## Programos naudojimas

Paleidę šią programą pamatysite meniu:

![alt text](https://github.com/BlackDude22/AntraUzduotis/blob/master/images/menu.png "Meniu")

Veiksmai 0-4 turėtų savaime suprantami. Veiksmas 5 prašo įvesti sveikąjį skaičių, kuris nurodo, kiek failų bus sugeneruota. Kiekvieną failą sudaro 10^n eilučių su studentų įrašais. Po to pasirenkate norimą konteinerio tipą ir programa jį išbandys su visais sugeneruotais failais dviem strategijomis:
  1. Studentai nuskaitomi į vieną konteinerį `students` paskui vieni įrašomi į `losers` kiti į `winners`.
  2. Studentai nuskaitomi į vieną konteinerį `students`, įrašai surikiuojami, paskui vieni įrašomi į `losers` ir ištrinami iš `students`.
Programa nurodo laiką bandant abi strategijas.

![alt text](https://github.com/BlackDude22/AntraUzduotis/blob/master/images/vector.png "Vector")
![alt text](https://github.com/BlackDude22/AntraUzduotis/blob/master/images/list.png "List")
![alt text](https://github.com/BlackDude22/AntraUzduotis/blob/master/images/deque.png "Deque")

## Programos įdiegimas

  1. Atsisiųskite [**naujausią programos versiją.**](https://github.com/BlackDude22/AntraUzduotis/releases)<br>
  2. Extract'inkite failus į pasirinktą vietą.
  3. Atsidarę norimą terminalą (pvz. Windows PowerShell) įveskite:
  
    cd <pasirinktas adresas>
    g++ -std=c++11 *.cpp  
    ./a
    
## Versijų istorija

### [**v1.0**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v1.0)<br>(naujausia versija)

#### Pridėta
  1. UI
  2. SafeInput
  3. SafeIntInput
  
### [**v0.5**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v0.5)<br>

### [**v0.4**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v0.4)<br>

### [**v0.3**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v0.3)<br>

### [**v0.2**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v0.2)<br>

### [**v0.1**](https://github.com/BlackDude22/AntraUzduotis/releases/tag/v0.1)<br>
