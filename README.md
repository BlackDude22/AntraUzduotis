# AntraUzduotis

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
  Link here
Veiksmai 0-4 turėtų savaime suprantami. Veiksmas 5 prašo įvesti sveikąjį skaičių, kuris nurodo, kiek failų bus sugeneruota. Kiekvieną failą sudaro 10^n eilučių su studentų įrašais. Po to pasirenkate norimą konteinerio tipą ir programa jį išbandys su visais sugeneruotais failais dviem strategijomis:
  1. Studentai nuskaitomi į vieną konteinerį `students` paskui vieni įrašomi į `losers` kiti į `winners`.
  2. Studentai nuskaitomi į vieną konteinerį `students`, įrašai surikiuojami, paskui vieni įrašomi į `losers` ir ištrinami iš `students`.
Programa nurodo laiką bandant abi strategijas.
vector link
list link
deque link

