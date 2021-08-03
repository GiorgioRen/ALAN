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

	cout << "\e[1m+============================+\n+ ALAN - Laboratorio Sistemi +\n+============================+\e[0m";

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
			//matrice_p[i][j] = (fact(i+j) / (fact(i)*fact(j))); // svariona per np>7 :(
			(i==0 || j==0) ? matrice_p[i][j]=1 : matrice_p[i][j] = (matrice_p[i][j-1] + matrice_p[i-1][j]);
		}
	}
	//stampa_matrice(matrice_p, np, np);

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

	/********** es 1 *********************************************************/
	/* Calcolo norma infinito */
	cout << "\n\n\e[1m*** Es 1 ***\e[0m\n";
	cout << "Norma infinito matrice a1: ......... " << norma_inf(matrice_a1, na1) << endl;
	cout << "Norma infinito matrice a2: ......... " << norma_inf(matrice_a2, na2) << endl;
	cout << "Norma infinito matrice Pascal: ..... " << norma_inf(matrice_p, np) << endl;
	cout << "Norma infinito matrice tridiagonale: " << norma_inf(matrice_t, nt) << endl;


	/********** es 2 *********************************************************/
	cout << "\n\n\e[1m*** Es 2 ***\e[0m\n";

	/* Matrice A1 */
	float *ba1 = trova_b(matrice_a1, na1);
	cout << "Vettore dei termini noti per A1: ";
	stampa_vettore_trasposto(ba1, na1);

	float *xa1 = gauss_plus(matrice_a1, ba1, na1);
	cout << "Vettore soluzioni per A1: ...... ";
	stampa_vettore_trasposto(xa1, na1);
	
	
	/* Matrice A2 */
	float *ba2 = trova_b(matrice_a2, na2);
	cout << "\nVettore dei termini noti per A2: "; 
	stampa_vettore_trasposto(ba2, na2);

	float *xa2 = gauss_plus(matrice_a2, ba2, na2);
	cout << "Vettore soluzioni per A2: ...... ";
	stampa_vettore_trasposto(xa2, na2);

	/* Matrice P */
	float *bp = trova_b(matrice_p, np);
	cout << "\nVettore dei termini noti per matr. di Pascal: "; 
	stampa_vettore_trasposto(bp, np);

	float *xp = gauss_plus(matrice_p, bp, np);
	cout << "Vettore soluzioni per P: .................... ";
	stampa_vettore_trasposto(xp, np);

	/* Matrice T */
	float *bt = trova_b(matrice_t, nt);
	cout << "\nVettore dei termini noti per matr. tridiagonale: "; 
	stampa_vettore_trasposto(bt, nt);

	float *xt = gauss_plus(matrice_t, bt, nt);
	cout << "Vettore soluzioni per T: ....................... ";
	stampa_vettore_trasposto(xt, nt);


	/********** es 3 *********************************************************/
	cout << "\n\n\e[1m*** Es 3 ***\e[0m\n";
	/* Risoluzione sistema lineare con termini noti perturbati */

	/* Matrice A1 */
	float *b_pert_a1 = perturba_b(ba1, na1);
	cout << "Vettore dei termini noti per A1: ";
	stampa_vettore_trasposto(b_pert_a1, na1);

	xa1 = gauss_plus(matrice_a1, b_pert_a1, na1);
	cout << "Vettore soluzioni per A1: ...... ";
	stampa_vettore_trasposto(xa1, na1);
	
	
	/* Matrice A2 */
	float *b_pert_a2 = perturba_b(ba2, na2);
	cout << "\nVettore dei termini noti per A2: "; 
	stampa_vettore_trasposto(b_pert_a2, na2);

	xa2 = gauss_plus(matrice_a2, b_pert_a2, na2);
	cout << "Vettore soluzioni per A2: ...... ";
	stampa_vettore_trasposto(xa2, na2);

	/* Matrice P */
	float *b_pert_p = perturba_b(bp, np);
	cout << "\nVettore dei termini noti per matr. di Pascal: "; 
	stampa_vettore_trasposto(b_pert_p, np);

	xp = gauss_plus(matrice_p, b_pert_p, np);
	cout << "Vettore soluzioni per P: .................... ";
	stampa_vettore_trasposto(xp, np);

	/* Matrice T */
	float *b_pert_t = perturba_b(bt, nt);
	cout << "\nVettore dei termini noti per matr. tridiagonale: "; 
	stampa_vettore_trasposto(b_pert_t, nt);

	xt = gauss_plus(matrice_t, b_pert_t, nt);
	cout << "Vettore soluzioni per T: ....................... ";
	stampa_vettore_trasposto(xt, nt);

	return 0;
}
