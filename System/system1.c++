#include <iostream>
#include <cmath>
using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error03        ║
 * ║                            ║
 * ║   --> Teams Canale 6 <--   ║
 * ╟────────────────────────────╨──────────╗
 * ║ Usage: g++ system1.cpp -O0 -o system1 ║
 * ╟────────────────────────────╥──────────╝
 * ╚════════════════════════════╝
 *
 *
 */

int fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

void norma_inf(int matr[4][4], int norma[4]) {
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			norma[i] += abs(matr[i][j]);
		}
	}
};

void calcola_p(int matr[10][10]){
	int numeratore, denominatore, d1, d2 = 0;
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			numeratore = i+j-2;
			numeratore = fact(numeratore);
			d1 = i-1;
			d1 = fact(d1);
			d2 = j-1;
			d2 = fact(d2);
			denominatore = d1 * d2;
			matr[i][j] = numeratore / denominatore;
		}
	}
}

// ----------
void stampa_matrice(int dim, int matr[dim][dim]){
	for (int i=0; i<dim; i++){
		cout << "{ ";
		for (int j=0; j<dim; j++){
			cout << matr[i][j] << ", ";
		}
		cout << "}\n";
	}
	cout << endl;
}

void stampa_array(int dim, int norma[dim]){
	for (size_t i = 0; i < dim; i++) {
		cout << norma[i] << endl;
	}
	cout << endl;
}

int main() {

	int a1[4][4] = {
		{3, 1, -1, 0} , //->5
		{0, 7, -3, 0} , //->10
		{0, -3, 9, -2} , //->14
		{0, 0, 4, -10} //->14
	};
	int a2[4][4] = {
		{0, 1, 2, 3} ,
		{4, 5, 6, 7} ,
		{8, 9, 10, 11} ,
		{0, 0, 0, 0}
	};
	int n_a1[4] = {0,0,0,0};
	int n_a2[4] = {0,0,0,0};

	int p[10][10];
	int n_p[10];

	int dim_t = 10(d1+1)+d0;
	int t[dim_t][dim_t];

	//----------
	norma_inf(a1, n_a1);
	norma_inf(a2, n_a2);

	cout << "prima matrice:\n";
	stampa_matrice(4, a1);
	cout << "norma:\n";
	stampa_array(4, n_a1);

	cout << "seconda matrice:\n";
	stampa_matrice(4, a2);
	cout << "norma:\n";
	stampa_array(4, n_a2);

	cout << "matrice P_\n";
	stampa_matrice(10, p);
	cout << "norma di P:\n";
	stampa_array(10, p);

	return 0;
}
