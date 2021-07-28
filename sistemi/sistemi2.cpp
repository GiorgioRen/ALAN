#include <iostream>
#include <cmath>
using namespace std;
/*
* ╔════════════════════════════╗
* ║ ALAN - Labo Sistemi        ║
* ╟────────────────────────────╨────────────────────╗
* ║ Usage: g++ sistemi2.cpp -o sistemi2; ./sistemi2 ║
* ╟────────────────────────────╥────────────────────╝
* ╚════════════════════════════╝
*
*/

/*
- matrice A1
	- calcolare b = A * {1,1,1,1}t
- matrice A2
- matrice P
- matrice T
*/

float fact(int n) { return (n==0) || (n==1) ? 1 : n*fact(n-1); }

float* calcola_b(float *matrice[], int n) {
	// b = matrice * {1}t
	float* b = new float[n];
	for (int i=0; i<n; i++){ //righe
		for (int j=0; j<n; j++){ //colonne
			b[i] += matrice[i][j];
		}
	}
	return b;
}

void stampa_matrice(float *matrice[], int n){
	for (int i=0; i<n; i++){
		cout << "{";
		for (int j=0; j<n; j++){
			cout << matrice[i][j];
			if (j+1!=n) cout<<", "; // inserimento virgola ','
		}
		cout << "}\n";
	}
}

void stampa_vettore(float vettore[], int n){
	cout << endl;
	for (int i=0; i<n; i++){
		cout << "{ " << vettore[i] << " }\n";
	}
	cout << endl;
}

void stampa_sistema_completo(float *matrice[], float variabili[], float termini_noti[], int righe, int colonne){
	cout << endl;
	for (int i=0; i<righe; i++){
		cout << "{";
		for (int j=0; j<colonne; j++) {
			cout << " " << matrice[i][j];
		}
		cout << " | " << variabili[i] << " } = " << termini_noti[i] << endl;
	}
	cout << endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main() {
	// Creazione matrici:
	// Matrice a1:
	float tmp1[4][4] = {{3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}};
	const int na1 = 4;
	float** a1 = new float*[na1];
	for (int i=0; i<na1; i++){
		a1[i] = new float[na1];
		for (int j=0; j<na1; j++){
			a1[i][j] = tmp1[i][j];
		}
	}

	// Matrice a2:
	float tmp2[4][4] = {{2, 4, -2, 0}, {1, 3, 0, 1}, {3, -1, 1, 2}, {0, -1, 2, 1}};
	const int na2 = 4;
	float** a2 = new float*[na2];
	for (int i=0; i<na2; i++){
		a2[i] = new float[na2];
		for (int j=0; j<na2; j++){
			a2[i][j] = tmp2[i][j];
		}
	}

	// Matrice p:
	const int np = 10;
	float** pascal = new float*[np];
	for (int i=0; i<np; i++){
		pascal[i] = new float[np];
		for (int j=0; j<np; j++){
			pascal[i][j] = (fact((i+1)+(j+1)-2))/(fact(i)*fact(j)); //i,j:0->9
		}
	}

	// Matrice t:
	const int d0 = 6; // ultima cifra matricola
	const int d1 = 8; // penultima cifra matricola
	const int nt = 10 * (d1 + 1) + d0;
	int** matrice_t = new int*[nt];
	for (int i=0; i<nt; i++){
		matrice_t[i] = new int[nt];
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	float* ba1 = new float[na1];
	ba1 = calcola_b(a1, na1);
	stampa_matrice(a1, na1);
	stampa_vettore(ba1, na1);

	float x[] = {1,1,1,1};
	stampa_sistema_completo(a1, x, ba1, na1, na1);

	return 0;
}
