// GramatykaBezkontekstowa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    bool czyrozne;
    int n, liczba, j, i=0;
    string s, tmp, g[1000];
    int licznik = 0;
    cout << "Jezyk opisany za pomoca gramatyki bezkontekstowej: S->A1B A->1A|E B->0B|1B|E" << endl;
    cout << "Prosze podac, ile slow ma wypisac program: ";
    cin >> n;
    while( i < n )
    {
        czyrozne = 1;
        s = "";
        liczba = rand() % 2;
        while (liczba != 1)
        {
            s += "1";
            liczba = rand() % 2;
        }
        s += "1";
        liczba = rand() % 3;
        while (liczba != 2)
        {
            if (liczba == 0)
                s += "0";
            else if (liczba == 1)
                s += "1";
            liczba = rand() % 3;
        }
        for (int z = 0; z < i; z++)
            if (s == g[z])
                czyrozne = 0;
        if (czyrozne) {
            g[i] = s;
            i++;
        }
    }

    for (int i = 1; i < n; i++) {
        tmp = g[i];
        for (j = i - 1; g[j].size() >= tmp.size() && j >= 0; j--)
            g[j + 1] = g[j];
        g[j + 1] = tmp;
    }
    for (int i = 0; i < n; i++)
        cout << g[i] << endl;
    return 0;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
