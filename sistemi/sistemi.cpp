#include <iostream>
#include "support.h"
using namespace std;

/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Sistemi        ║
 * ║┌───────────────────────────╨──────────────────┐
 * ║│ Usage: g++ sistemi.cpp -o sistemi; ./sistemi │
 * ║└───────────────────────────╥──────────────────┘
 * ╚════════════════════════════╝
 */

int main(){

	/* Creazione matrici */
	// Matrice a1:
	float tmp1[4][4] = {{3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}};
	const int na1 = 4;
	float** matrice_a1 = new float*[na1];
	for (int i=0; i<na1; i++){
		matrice_a1[i] = new float[na1];
		for (int j=0; j<na1; j++){
			matrice_a1[i][j] = tmp1[i][j];
		}
	}

	// Matrice a2:
	float tmp2[4][4] = {{2, 4, -2, 0}, {1, 3, 0, 1}, {3, -1, 1, 2}, {0, -1, 2, 1}};
	const int na2 = 4;
	float** matrice_a2 = new float*[na2];
	for (int i=0; i<na2; i++){
		matrice_a2[i] = new float[na2];
		for (int j=0; j<na2; j++){
			matrice_a2[i][j] = tmp2[i][j];
		}
	}

	// Matrice p:
	const int np = 10;
	float** matrice_p = new float*[np];
	for (int i=0; i<np; i++){
		matrice_p[i] = new float[np];
		for (int j=0; j<np; j++){
			matrice_p[i][j] = ((fact(i+j))/(fact(i)*fact(j)));
		}
	}

	// Matrice t:
	const int d0 = 6; // ultima cifra matricola
	const int d1 = 8; // penultima cifra matricola
	const int nt = 10 * (d1 + 1) + d0;
	float** matrice_t = new float*[nt];
	for (int i=0; i<nt; i++){
		matrice_t[i] = new float[nt];
		for (int j=0;j<nt;j++){
			if (i==j) matrice_t[i][j]=2;
			else if (fabs(i-j)==1) matrice_t[i][j]=-1;
			else matrice_t[i][j]=0;
		}
	}

	/* es 1 */
	/* Calcolo norma infinito */
	cout << "Norma infinito matrice a1: ......... " << norma_inf(matrice_a1, na1) << endl;
	cout << "Norma infinito matrice a2: ......... " << norma_inf(matrice_a2, na2) << endl;
	cout << "Norma infinito matrice Pascal: ..... " << norma_inf(matrice_p, np) << endl;
	cout << "Norma infinito matrice tridiagonale: " << norma_inf(matrice_t, nt) << endl;

	stampa_matrice(matrice_p, np);

	/* es 2 */
	/* Calcolo termine noto `b` con la formula b=Ax dove x è composto da tutti 1*/
	/* Risoluzione sistema lineare tramite eliminazione di Gauss*/

	/* es 3 */
	/* Risoluzione sistema lineare con termini noti perturbati */

	return 0;
}
