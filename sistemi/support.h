#include <iostream>
#include <cmath>
using namespace std;

/* Funzione fattoriale */
float fact(float n) { return (n==0) || (n==1) ? 1 : n * fact(n-1); }

/* Funzione calcolo norma infinita */
float norma_inf(float *matrice[], int n) {
	float norma = 0;
	float tmp = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			tmp += fabs(matrice[i][j]);
		}
		if (tmp > norma){ norma = tmp;}
		tmp=0; //reset
	}
	return norma;
}

/* PrettyPrint matrice */
void stampa_matrice(float *matrice[], int n){
	for (int i=0; i<n; i++){
		cout << "{ ";
		for (int j=0; j<n; j++){
			if (matrice[i][j]<0) { cout << matrice[i][j]; }
			else { cout << " " << matrice[i][j]; }
			if (j+1!=n) { cout << ", "; }// inserimento virgola ','
		}
		cout << " }\n";
	}
}
