#include <iostream>
#include <fstream>
using namespace std;

// Jeden element kolejki
struct Element
{
    int liczba;             // przechowuje liczbê
    Element* nastepny;      // wskazuje na nastêpny element
};

// Klasa obs³uguj¹ca kolejkê
class Kolejka
{
private:
    Element* poczatek;      // pocz¹tek kolejki

public:

    // Konstruktor - na pocz¹tku kolejka jest pusta
    Kolejka()
    {
        poczatek = NULL;
    }

    // Destruktor - usuwa wszystkie elementy z pamiêci
    ~Kolejka()
    {
        while (poczatek != NULL)
        {
            Element* temp = poczatek;
            poczatek = poczatek->nastepny;
            delete temp;
        }
    }

    // Dodaje now¹ liczbê na koniec kolejki
    void dodaj(int liczba)
    {
        // Tworzymy nowy element
        Element* nowy = new Element;

        // Wpisujemy do niego liczbê
        nowy->liczba = liczba;

        // Nowy element jest ostatni
        nowy->nastepny = NULL;

        // Je¿eli kolejka jest pusta,
        // nowy element staje siê pocz¹tkiem
        if (poczatek == NULL)
        {
            poczatek = nowy;
            return;
        }

        // Szukamy ostatniego elementu
        Element* temp = poczatek;

        while (temp->nastepny != NULL)
            temp = temp->nastepny;

        // Dodajemy nowy element na koñcu
        temp->nastepny = nowy;
    }

    // Wczytuje liczby z pliku
    void wczytaj()
    {
        ifstream plik("liczby.txt");
        int liczba;

        // Sprawdzamy, czy plik zosta³ otwarty
        if (!plik)
        {
            cout << "Blad otwarcia pliku!\n";
            return;
        }

        // Wczytujemy liczby a¿ do koñca pliku
        while (plik >> liczba)
            dodaj(liczba);

        plik.close();

        cout << "Wczytano dane.\n";
    }

    // Wyœwietla wszystkie liczby
    void pokaz()
    {
        Element* temp = poczatek;

        // Przechodzimy przez ca³¹ kolejkê
        while (temp != NULL)
        {
            cout << temp->liczba << " ";
            temp = temp->nastepny;
        }

        cout << endl;
    }

    // Sortowanie b¹belkowe
    void sortuj()
    {
        // Je¿eli kolejka jest pusta, nic nie robimy
        if (poczatek == NULL)
            return;

        bool zmiana;

        // Powtarzamy sortowanie, dopóki s¹ zamiany
        do
        {
            zmiana = false;

            // WskaŸnik na pocz¹tek kolejki
            Element** wsk = &poczatek;

            // Przechodzimy po elementach
            while ((*wsk) != NULL && (*wsk)->nastepny != NULL)
            {
                Element* a = *wsk;
                Element* b = a->nastepny;

                // Je¿eli liczby s¹ w z³ej kolejnoœci
                if (a->liczba > b->liczba)
                {
                    // Zamieniamy elementy miejscami
                    a->nastepny = b->nastepny;
                    b->nastepny = a;
                    *wsk = b;

                    zmiana = true;
                }

                // Przechodzimy do nastêpnego elementu
                wsk = &((*wsk)->nastepny);
            }

        } while (zmiana);

        cout << "Posortowano.\n";
    }

    // Zapisuje kolejkê do pliku
    void zapisz()
    {
        ofstream plik("wyjscie.txt");
        Element* temp = poczatek;

        // Sprawdzamy, czy plik zosta³ utworzony
        if (!plik)
        {
            cout << "Blad utworzenia pliku!\n";
            return;
        }

        // Zapisujemy wszystkie liczby
        while (temp != NULL)
        {
            plik << temp->liczba << " ";
            temp = temp->nastepny;
        }

        plik.close();

        cout << "Zapisano do pliku.\n";
    }
};

// G³ówna funkcja programu
int main()
{
    // Tworzymy kolejkê
    Kolejka k;

    int wybor;

    // Menu programu
    do
    {
        cout << "\n";
        cout << "1 - Wczytaj\n";
        cout << "2 - Pokaz\n";
        cout << "3 - Sortuj\n";
        cout << "4 - Zapisz\n";
        cout << "0 - Wyjscie\n";
        cout << "Wybor: ";

        cin >> wybor;

        // Wybór operacji
        switch (wybor)
        {
            // Wczytanie liczb z pliku
            case 1:
                k.wczytaj();
                break;

            // Wyœwietlenie kolejki
            case 2:
                k.pokaz();
                break;

            // Posortowanie kolejki
            case 3:
                k.sortuj();
                break;

            // Zapisanie kolejki do pliku
            case 4:
                k.zapisz();
                break;

            // Zakoñczenie programu
            case 0:
                cout << "Koniec.\n";
                break;

            // B³êdna opcja
            default:
                cout << "Zly wybor!\n";
        }

    } while (wybor != 0);

    return 0;
}
