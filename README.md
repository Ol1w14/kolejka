📚 Kolejka jednokierunkowa w C++
📋 Opis projektu

Program przedstawia implementację kolejki jednokierunkowej w języku C++.

Dane przechowywane są w dynamicznie tworzonych elementach połączonych za pomocą wskaźników.

Program umożliwia:

📥 Wczytanie liczb z pliku

👀 Wyświetlenie zawartości kolejki

🔢 Posortowanie liczb

💾 Zapisanie danych do pliku

🚪 Zakończenie programu

🧱 Budowa programu
🔹 Struktura Element

Struktura przechowuje pojedynczy element kolejki.

struct Element
{
    int liczba;
    Element* nastepny;
};

🔹 Klasa Kolejka

Klasa odpowiada za obsługę całej kolejki.

Zawiera wskaźnik:

Element* poczatek;


który wskazuje na pierwszy element kolejki.

⚙️ Dostępne funkcje
📥 dodaj()

Dodaje nową liczbę na koniec kolejki.

void dodaj(int liczba)

📂 wczytaj()

Wczytuje liczby z pliku liczby.txt i dodaje je do kolejki.

👀 pokaz()

Wyświetla wszystkie elementy znajdujące się aktualnie w kolejce.

🔢 sortuj()

Sortuje elementy kolejki rosnąco za pomocą sortowania bąbelkowego.

💾 zapisz()

Zapisuje posortowane lub nieposortowane dane do pliku wyjscie.txt.

📋 Menu programu

Po uruchomieniu programu pojawia się menu:

1 - Wczytaj
2 - Pokaz
3 - Sortuj
4 - Zapisz
0 - Wyjscie
Wybor:

1️⃣ Wczytaj

Program odczytuje liczby z pliku liczby.txt.

Przykładowa zawartość:

8 3 15 2 10 1 7

2️⃣ Pokaz

Wyświetla aktualną zawartość kolejki.

Przykład:

8 3 15 2 10 1 7

3️⃣ Sortuj

Sortuje liczby rosnąco.

Przykład:

1 2 3 7 8 10 15

4️⃣ Zapisz

Zapisuje zawartość kolejki do pliku:

wyjscie.txt

0️⃣ Wyjście

Kończy działanie programu.

🧮 Sortowanie

Program wykorzystuje sortowanie bąbelkowe.

Elementy są porównywane parami. Jeżeli znajdują się w złej kolejności, są zamieniane miejscami.

Przykład:

8 3 15 2
↓
3 8 15 2
↓
3 8 2 15
↓
3 2 8 15
↓
2 3 8 15

💾 Obsługa plików
📄 Plik wejściowy

Program odczytuje dane z:

liczby.txt

📄 Plik wyjściowy

Program zapisuje dane do:

wyjscie.txt

🧠 Pamięć dynamiczna

Elementy kolejki są tworzone dynamicznie za pomocą:

new Element;


Po zakończeniu działania programu pamięć jest zwalniana przez destruktor klasy Kolejka.

~Kolejka()


Dzięki temu elementy utworzone za pomocą new są poprawnie usuwane z pamięci.

🛠️ Wymagania
💻 Oprogramowanie

Do uruchomienia programu potrzebny jest kompilator C++, np.:

g++

MinGW

Visual Studio

Code::Blocks

▶️ Uruchomienie
1. Przygotowanie plików

W folderze projektu powinny znajdować się:

projekt/
│
├── main.cpp
├── liczby.txt
└── README.md

2. Kompilacja

Przykładowa komenda dla g++:

g++ main.cpp -o program

3. Uruchomienie

Windows:

program.exe


Linux:

./program

📁 Struktura projektu
📂 Pliki
kolejka/
│
├── main.cpp
├── liczby.txt
├── wyjscie.txt
└── README.md

🎯 Cel projektu

Celem projektu jest nauka:

struktur danych,

kolejek,

list jednokierunkowych,

wskaźników,

pamięci dynamicznej,

sortowania bąbelkowego,

obsługi plików,

programowania obiektowego w C++.

