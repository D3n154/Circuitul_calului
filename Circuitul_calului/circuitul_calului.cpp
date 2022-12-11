#include <iostream>

using namespace std;

const int n = 5;
int a[n][n];
int i_init,j_init;//pozitii initiale i si j
const int directii = 8;
int v_i[directii] = { -1,-2,-2,-1,1,2,2,1 };
int v_j[directii] = { -2,-1,1,2,2,1,-1,-2 };

void Citire()
{
	cout << "Introduceti pozitia initiala pentru i:";
	cin >> i_init;
	cout << "Introduceti pozitia initiala pentru j:";
	cin >> j_init;
	a[i_init][j_init] = 1;
}

void Afisare()
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		cout << endl;
		for (j = 1; j < n; j++)
			cout << a[i][j] << " ";
	}
	cout << endl;
}

int Verificare_poz(int i, int j)
{
	if (i >=n || i <= 0)
		return 0;
	if (j >=n || j <= 0)
		return 0;

	if (a[i][j] == 0)
		return 1;

	if (a[i][j] != 0)
		return 0;
}

int Mutare_cal(int i, int j, int pas)
{
	int k;
	int i_vecin;
	int j_vecin;

	if (pas == n*n+1)
		return 0;
	else
	{
		for (k = 0; k < directii; k++)
		{
			i_vecin = i + v_i[k];
			j_vecin = j + v_j[k];
			if (Verificare_poz(i_vecin, j_vecin) != 0)
			{
				a[i_vecin][j_vecin] = pas;
				pas++;
				cout << pas;
				Afisare();
				Mutare_cal(i_vecin, j_vecin, pas);
				a[i_vecin][j_vecin] = 0;
				pas--;
			}
		}
	}
}

int main()
{
	Citire();
	Afisare();
	Mutare_cal(i_init, j_init, 2);
	return 0;
}