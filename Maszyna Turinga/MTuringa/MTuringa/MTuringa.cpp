#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;

void deskarozdzielcza()
{
	cout << "Maszyna Turinga obliczajaca roznice wlasciwa dla m i n:\n";
	cout << " m - n dla m > n \n 0 dla m <= n\n\n";
	cout << "M = ({q0, q1, q2, q3, q4, q5, q6}, {0, 1}, {0, 1, B}, d, q0, 0)\n";
	cout << "d |     0    |     1    |     B    |\n";
	cout << "____________________________________\n";
	cout << "q0|(q1, B, P)|(q5, B, P)|     -    |\n";
	cout << "q1|(q1, 0, P)|(q2, 1, P)|     -    |\n";
	cout << "q2|(q3, 1, L)|(q2, 1, P)|(q4, B, L)|\n";
	cout << "q3|(q3, 0, L)|(q3, 1, L)|(q0, B, P)|\n";
	cout << "q4|(q4, 0, L)|(q4, B, L)|(q6, 0, P)|\n";
	cout << "q5|(q5, B, P)|(q5, B, P)|(q6, B, P)|\n";
	cout << "q6|     -    |     -    |     -    |\n";
}
string przejscie(string c, int *stan, int *polozenie, int *czydalej)
{
	string s = c;
	//cout << "Czytany przeze mnie symbol:  " << s[*polozenie] << endl;
		if (*stan == 0)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 1;
				s[*polozenie] = 'B';
				(*polozenie)++;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 5;
				s[*polozenie] = 'B';
				(*polozenie)++;
			}
			else if (s[*polozenie] == 'B')
			{
				*czydalej = 0;
			}
		}
		else if (*stan == 1)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 1;
				s[*polozenie] = '0';
				(*polozenie)++;
				return s;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 2;
				s[*polozenie] = '1';
				(*polozenie)++;
				return s;
			}
			else if (s[*polozenie] == 'B')
			{
				*czydalej = 0;
			}
		}
		else if (*stan == 2)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 3;
				s[*polozenie] = '1';
				(*polozenie)--;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 2;
				s[*polozenie] = '1';
				(*polozenie)++;
			}
			else if (s[*polozenie] == 'B')
			{
				*stan = 4;
				s[*polozenie] = 'B';
				(*polozenie)--;
			}
		}
		else if (*stan == 3)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 3;
				s[*polozenie]  = '0';
				(*polozenie)--;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 3;
				s[*polozenie] = '1';
				(*polozenie)--;
			}
			else if (s[*polozenie] == 'B')
			{
				*stan = 0;
				s[*polozenie] = 'B';
				(*polozenie)++;
			}
		}
		else if (*stan == 4)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 4;
				s[*polozenie] = '0';
				(*polozenie)--;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 4;
				s[*polozenie] = 'B';
				(*polozenie)--;
			}
			else if (s[*polozenie] == 'B')
			{
				*stan = 6;
				s[*polozenie] = '0';
				(*polozenie)++;
			}
		}
		else if (*stan == 5)
		{
			if (s[*polozenie] == '0')
			{
				*stan = 5;
				s[*polozenie] = 'B';
				(*polozenie)++;
			}
			else if (s[*polozenie] == '1')
			{
				*stan = 5;
				s[*polozenie] = 'B';
				//s += "B";
				(*polozenie)++;
			}
			else if (s[*polozenie] == 'B')
			{
				*stan = 6;
				s[*polozenie] = 'B';
				(*polozenie)++;
			}
		}
		else if (*stan == 6)
		{
		*czydalej = 0;
		}
	return s;
}
/*void drukujstan(string s, int stan, int polozenie)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (i == polozenie)
			cout << " q" << stan << " ";
		cout << s[i];
	}
	//cout << "Stan: " << stan << endl;
	//cout << "Polozenie: " << polozenie << endl;
	cout << "|- ";
} */

void drukujstan(string s, int stan, int polozenie)
{
	int iledrukowac = s.size();
	while (s[iledrukowac-1] != '0' && s[iledrukowac-1] != '1' && iledrukowac > polozenie)
	{
		iledrukowac -= 1;
	}
	for (int i = 0; i < iledrukowac; i++)
	{
		if (i == polozenie)
			cout << " q" << stan << " ";
		cout << s[i];
	}
	if (polozenie == iledrukowac)
		cout << " q" << stan << " ";
	cout << " |- ";
}

int main()
{
	string s = "";
	int m, n, polozenie = 0, stan = 0, dl, czydalej = 1;

	deskarozdzielcza();
	cout << "Prosze podac m i n\n";
	cout << "m: ";
	cin >> m;
	cout << "n: ";
	cin >> n;
	if (m < 0 || n < 0)
	{
		cout << "Wprowadzono jedna lub wiecej ujemnych wartosci\n";
		return 0;
	}
	for (int i = 0; i < m; i++)
		s += "0";
	s += "1";
	for (int i = 0; i < n; i++)
		s += "0";
	s += "B";

	while ( czydalej != 0 )
	{
		drukujstan(s, stan, polozenie);
		s = przejscie(s, &stan, &polozenie, &czydalej);
		//drukujstan(s, stan, polozenie);
		//if (s[polozenie] != '0' && s[polozenie] != '1' && s[polozenie] != 'B')
		//	czydalej = 0;
	}
	cout << endl;
	if (m > n)
		cout << "\nRoznica wlasciwa: " << m - n;
	else
		cout << "Roznica wlasciwa: 0";

	return 0;
}