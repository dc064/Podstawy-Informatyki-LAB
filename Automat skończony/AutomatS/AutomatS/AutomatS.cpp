// AutomatS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void wydruk(char v[24][15])
{
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 24; i++)
            if (v[i][j] == '*')
                cout << " ";
            else
                cout << v[i][j];
        cout << "\n";
    }
} 

char przejscie(char v [24][15], char symbol, char aktualny_stan)
{
    char nastepny_stan= '2';
    switch (symbol)
    {
    case '0':
    {

        if (aktualny_stan == '0')
        {
            for (int i = 5; i <= 8; i++)
                v[2][i] = 'V';
            v[2][12] = 'Q';

            wydruk(v);

            for (int i = 5; i <= 8; i++)
                v[2][i] = '|';
            v[2][12] = 'q';

            nastepny_stan = '2';
        }
        else if (aktualny_stan == '1')
        {
            for (int i = 5; i <= 8; i++)
                v[21][i] = 'V';
            v[19][12] = 'Q';

            wydruk(v);

            for (int i = 5; i <= 8; i++)
                v[21][i] = '|';
            v[19][12] = 'q';

            nastepny_stan = '3';
        }
        else if (aktualny_stan == '2')
        {
            for (int i = 6; i <= 9; i++)
                v[4][i] = '^';
            v[2][2] = 'Q';

            wydruk(v);

            for (int i = 6; i <= 9; i++)
                v[4][i] = '|';
            v[2][2] = 'q';

            nastepny_stan = '0';
        }
        else if (aktualny_stan == '3')
        {
            for (int i = 6; i <= 9; i++)
                v[19][i] = '^';
            v[19][2] = 'Q';

            wydruk(v);

            for (int i = 6; i <= 9; i++)
                v[19][i] = '|';
            v[19][2] = 'q';

            nastepny_stan = '1';
        }
        break;
    }
    case '1':
    {
        if (aktualny_stan == '0')
        {
            for (int i = 7; i <= 14; i++)
                v[i][2] = '>';
            v[19][2] = 'Q';

            wydruk(v);

            for (int i = 7; i <= 14; i++)
                v[i][2] = '-';
            v[19][2] = 'q';

            nastepny_stan = '1';

        }
        else if (aktualny_stan == '1')
        {
            for (int i = 8; i <= 14; i++)
                v[i][3] = '<';
            v[2][2] = 'Q';

            wydruk(v);

            for (int i = 8; i <= 14; i++)
                v[i][3] = '-';
            v[2][2] = 'q';

            nastepny_stan = '0';
        }
        else if (aktualny_stan == '2')
        {
            for (int i = 8; i <= 14; i++)
                v[i][12] = '>';
            v[19][12] = 'Q';

            wydruk(v);

            for (int i = 8; i <= 14; i++)
                v[i][12] = '-';
            v[19][12] = 'q';

            nastepny_stan = '3';
        }
        else if (aktualny_stan == '3')
        {
            for (int i = 8; i <= 14; i++)
                v[i][13] = '<';
            v[2][12] = 'Q';

            wydruk(v);

            for (int i = 8; i <= 14; i++)
                v[i][13] = '-';
            v[2][12] = 'q';

            nastepny_stan = '2';
        }
        break;
    }
    default:
    {
        cout << "Zly symbol!!!\n";
        break;
    }
    }

    cout << "Kolejny symbol z ciagu: " << symbol << "\n";

    cout << "q" << aktualny_stan << " -- " << symbol << " --> q" << nastepny_stan << "\n";


    Sleep(3000);
    system("cls");

    return nastepny_stan;
}

int main()
{
    char g[24][15];
    char stan = '2';
    int j = 0, c = 8;
    int dlugoscciagu;
    string wczyt, ciag;

    ifstream graf;

    //wczytanie rysunku grafu do tablicy dwuwymiarowej
    graf.open("graf.txt");
    while (!graf.eof())
    {
        graf >> wczyt;
        for (int i = 0; i < 24; i++)
        {
            g[i][j] = wczyt[i];
        }
        j++;
    }
    graf.close();

    wydruk(g);

    g[2][12] = 'q';

    cout << "Stan poczatkowy: q" << stan << ".\n";

    cout << "Prosze podac ciag skladajacy sie z symboli wejsciowych: ";

    cin >> ciag;

    
    dlugoscciagu = ciag.size();

    for (int i=0; i<dlugoscciagu; i++)
        if (ciag[i] != '0' && ciag[i] != '1')
        {
            cout << "Zly symbol w podanym ciagu! Automat nie wlaczy sie.\n";
            return 0;
        }

    {
        cout << "Wczytano ciag o dlugosci: " << dlugoscciagu << endl;

        Sleep(2000);
        system("cls");

        for (int licz = 0; licz < dlugoscciagu; licz++)
            stan = przejscie(g, ciag[licz], stan);

        if (stan == '2')
        {
            cout << "Stan koncowy prawidlowy. Ciag zostal zaakceptowany.\n";
        }
        else
            cout << "Stan koncowy: q" << stan << ", dopuszczalny stan koncowy: q2. Wobec tego ciag nie zostal zaakceptowany.";
    }
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


