#include <iostream>
#include <cmath>
using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error          ║
 * ║                            ║
 * ║   --> Teams Canale 6 <--   ║
 * ╟────────────────────────────╨──────────╗
 * ║ Usage: g++ system1.cpp -O0 -o system1 ║
 * ╟────────────────────────────╥──────────╝
 * ╚════════════════════════════╝
 *
 * 1) Definire le e calcolare norma inf. delle matrici definite in sistemi.pdf
 * 2)
 * 3) Risolvere il sistema lineare $A\tilde{x} = b+\delta{b}$
 */

// Definizione funzione FATTORIALE
int fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

// ~ Definizione funzione NORMA_INF = max(somma modulo riga) ~
double norma_inf(int M, int N, *int matr[]) {
	int norma, tmp = 0;
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			tmp += abs(matr[i][j]);
		}
		if (tmp > norma) norma = tmp;
		tmp=0; //reset
	}
	return norma;
}

// ~ Definizione funzione che calcola matrice di PASCAL ~
void calcola_p(int n, int *matr[][]){
	int numeratore, denominatore, d1, d2 = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			matr[i][j] = (fact((i+1)+(j+1)-2))/(fact(i)*fact(j));; //i,j:0->9
		}
	}
}

// ~ Definizione funzione che calcola matrice TRIDIAGONALE ~
void calcola_t(int n, int *matr[][]){
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i==j) matr[i][j]=2;
			else if (abs(i-j)==1) matr[i][j]=-1;
			else matr[i][j]=0;
		}
	}
}


// ----------
void stampa_matrice(int m, int n, int *matr[][]){
	for (int i=0; i<m; i++){
		cout << "{ ";
		for (int j=0; j<n; j++){
			cout << matr[i][j];
			if (j+1!=n) cout<<", "; // inserimento virgola ','
		}
		cout << " }\n";
	}
	cout << endl;
}

void stampa_array(int dim, int *norma[]){
	for (size_t i = 0; i < dim; i++) {
		cout << norma[i] << endl;
	}
	cout << endl;
}

int main() {
	cout << endl;
	// d0 ultima cifra matricola, d1 penultima cifra matricola:
	// Giorgio R. -> xxxxx86
	const int d0 = 6;
	const int d1 = 8;

	// n righe n colonne:
	const int n_a1 = 4;
	const int n_a2 = 4;
	const int n_p = 10;
	const int n_t = 10 * (d1 + 1) + d0;

	// Dichiarazioni matrici:
	/* 2D dynamic array reference:
	int *ary = new int[sizeX * sizeY];
	ary[y*sizeX + x]

	int *ary = new int[m * n];
	ary[i*m + j]
	*/

	int a1[4][4] = {{3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}};
	cout << "- Matrice A1:" << endl;
	stampa_matrice(n_a1, n_a1, a1);
	cout << "Norma matrice A1: " << norma_inf(n_a1, n_a1, a1) << endl;

	int a2[4][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {0, 0, 0, 0}};
	cout << "- Matrice A2:" << endl;
	stampa_matrice(n_a2, n_a2, a2);
	cout << "Norma matrice A2: " << norma_inf(n_a2, n_a2, a2) << endl;

	// Matrice di Pascal
	int **p = new int*[n_p];
	for(int i=0; i<n_p; i++) p[n_p]=new int[n_p];
	calcola_p(n_p, p);
	cout << "- Matrice P:" << endl;
	stampa_matrice(n_p, n_p, p);
	cout << "Norma matrice P: " << norma_inf(n_p, n_p, p) << endl;



	//----------


	return 0;
}
