#include "game_of_life.h"


using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	return (rand()%4+1)/4;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
    return _generacija[i][j];
}





void game_of_life::iscrtaj()
{
	system("cls");
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i, j)) {
				cout << (char)219 << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void game_of_life::sljedeca_generacija()
{
	int brojac;
	int vijednosti[REDAKA][STUPACA];
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			brojac = 0;
			for (int m = -1; m < 2; m++) {
				for (int n = -1; n < 2; n++) {
					if (i + m < 0 || i + m>REDAKA-1) {
						continue;
					}
					if (j + n < 0 || j + n>STUPACA-1) {
						continue;
					}
					if (m == 0 && n == 0) {
						continue;
					}
					if (celija_zauzeta(i + m, j + n)) {
						//cout << i << " | " << j <<"("<<m<<", " << n<< ") - " << brojac << endl;
						brojac++;
					}
				}
			}
			
			//cout << i << " | " << j << " - " << brojac << endl;
			vijednosti[i][j] = brojac;
			/*if (brojac < 2 || brojac > 3) 
			{
				_sljedeca_generacija[i][j] == false;
			}
			else if (brojac == 3)
			{
				_sljedeca_generacija[i][j] == true;
			}
			else
			{
				_sljedeca_generacija[i][j] == _generacija[i][j];
			}*/
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (vijednosti[i][j] < 2 || vijednosti[i][j] > 3)
			{
				_sljedeca_generacija[i][j] = false;
			}
			else if (vijednosti[i][j] == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
			{
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}


			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}







game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA+1; i++)
	{
		for (int j = 0; j < STUPACA+1; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}