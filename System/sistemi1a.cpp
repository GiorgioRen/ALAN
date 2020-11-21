#include <iostream>
#include <cmath>
using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error          ║
 * ╟────────────────────────────╨──────────╗
 * ║ Usage: g++ sistemi1a.cpp -o sistemi1a ║
 * ╟────────────────────────────╥──────────╝
 * ╚════════════════════════════╝
 *
 * 1.a) Definire e calcolare norma inf. delle matrici a1 e a2 definite in sistemi.pdf
 * MATRICI a1 e a2
 */

unsigned int norma_inf(int matrice[4][4]) {
	int norma, tmp = 0;
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			tmp += abs(matrice[i][j]);
		}
		if (tmp > norma) norma = tmp;
		tmp=0; //reset
	}
	return norma;
}

void stampa_matrice(int matrice[4][4]){
	for (int i=0; i<4; i++){
		cout << "{ ";
		for (int j=0; j<4; j++){
			cout << matrice[i][j];
			if (j+1!=4) cout<<", "; // inserimento virgola ','
		}
		cout << " }\n";
	}
}

int main() {
	cout << endl;
	int a1[4][4] = {{3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}};
	cout << "- Matrice a1:" << endl;
	stampa_matrice(a1);
	cout << "Norma matrice a1: " << norma_inf(a1) << endl << endl;

	int a2[4][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {0, 0, 0, 0}};
	cout << "- Matrice a2:" << endl;
	stampa_matrice(a2);
	cout << "Norma matrice a2: " << norma_inf(a2) << endl << endl;

	return 0;
}
