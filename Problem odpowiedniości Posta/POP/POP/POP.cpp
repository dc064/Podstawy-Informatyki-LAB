// POP.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
    string A[100], B[100], a, b;
    int n, indeksy[100], indeks = 1;
    int idx=1;
    cout << "Ile elementow zawiera kazda lista? ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "A" << i+1 << ": ";
        getline(cin, A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "B" << i+1 << ": ";
        getline(cin, B[i]);
    }
    cout << "i | Ai | Bi" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " | " << A[i] << " | " << B[i] << endl;
    }

    while (idx)
    {
        cout << "Podaj indeks i"<<indeks<<" (lub 0, by przerwac poszukiwanie): ";
        cin >> idx;
        if (idx < 0 || idx > n)
        {
            cout << "Niepoprawny numer indeksu" << endl;
            indeks--;
        }
        else if (idx == 0)
        {
            indeks--;
            break;
        }
        else
        {
            a += A[idx - 1];
            b += B[idx - 1];
            cout << "Aktualny stan: \nA| " << a << "\nB| " << b << endl;
            if (a == b)
                cout << "Znaleziono prawidlowe rozwiazanie" << endl;
            indeksy[indeks - 1] = idx;
        }
        indeks += 1;
    }
    if (a == b)
        cout << "Znaleziono rozwiazanie\nLista: ";
    else
        cout << "Nie znaleziono rozwiazania\nPrzeszukiwana lista to: ";
    for (int i = 0; i < indeks; i++)
        cout << "i" << i + 1 << " = " << indeksy[i] <<"; ";
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
