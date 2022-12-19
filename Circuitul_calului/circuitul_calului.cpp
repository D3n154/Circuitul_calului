#include <iostream>

using namespace std;

int n ;
int a[100][100];
int i_init,j_init;
const int directii = 8;
int v_i[directii] = { -2, -1, 1, 2,  2,  1, -1, -2 };
int v_j[directii] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int i, j;

void Citire()
{
	cout << "Dati marimea tablei de sah:";
	cin >> n;
	cout << "Introduceti pozitia initiala pentru i:";
	cin >> i_init;
	cout << "Introduceti pozitia initiala pentru j:";
	cin >> j_init;
	a[i_init][j_init] = 1;
}

void Afisare()
{
	for (i =0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
	}

}

int Verificare_poz(int i, int j)
{
	if (i >n-1 || i < 0)
		return 0;
	if (j >n-1 || j < 0)
		return 0;
	if (a[i][j] !=0)
		return 0;

	return 1;
}

void Mutare_cal(int i, int j, int pas)
{
	int k;
	int i_vecin;
	int j_vecin;

	if (pas==(n*n)+1)
	{
		Afisare();
		exit(1);
	}
	
		for (k = 0; k < directii; k++)
		{
			i_vecin = i + v_i[k];
			j_vecin = j + v_j[k];

			if (Verificare_poz(i_vecin, j_vecin)!=0)
			{
				a[i_vecin][j_vecin] = pas;
				pas++;
				Mutare_cal(i_vecin, j_vecin,pas);
				a[i_vecin][j_vecin] = 0;
				pas--;
			}
		}
}

int main()
{
	Citire();
	Mutare_cal(i_init, j_init,2);
	return 0;
}