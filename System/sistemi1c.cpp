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
* 1.c) Definire e calcolare norma inf. della matrice tridiagonale definita in sistemi.pdf
*
*/

// TODO: LA NORMA NON FUNZIONA

unsigned int norma_inf(int *matrice[], int n) {
	unsigned long long int norma, tmp = 0;
	for (unsigned int i=0; i<n; i++){
		for (unsigned int j=0; j<n; j++){
			tmp = tmp+abs(matrice[i][j]);
		}
		if (tmp > norma) norma = tmp;
		tmp=0; //reset
	}
	return norma;
}

void stampa_matrice(int *matrice[], int n){
	for (int i=0; i<n; i++){
		cout << "{";
		for (int j=0; j<n; j++){
			cout << matrice[i][j];
			if (j+1!=n) cout<<","; // inserimento virgola ','
		}
		cout << "}\n";
	}
}

int main() {
	cout << endl;
	// d0 ultima cifra matricola, d1 penultima cifra matricola:
	// Giorgio R. -> xxxxx86
	const int d0 = 6;//6
	const int d1 = 8;//8
	const int n = 10 * (d1 + 1) + d0;

	// reference: https://pencilprogrammer.com/cpp-programs/dynamic-2d-array/
	int** matrice_t;
	matrice_t = new int*[n];
	for (int i=0; i<n; i++){
		matrice_t[i] = new int[n];
	}

	// inserimento dati nella matrice_t
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i==j) matrice_t[i][j]=2;
			else if (abs(i-j)==1) matrice_t[i][j]=-1;
			else matrice_t[i][j]=0;
		}
	}

	cout << "- Matrice t:" << endl;
	stampa_matrice(matrice_t, n);
	cout << "Norma matrice t: " << norma_inf(matrice_t, n) << endl << endl;

	return 0;
}
