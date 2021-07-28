#include <iostream>
#include <cmath>
using namespace std;
/*
* ╔════════════════════════════╗
* ║ ALAN - Labo Sistemi        ║
* ╟────────────────────────────╨───────────────────────╗
* ║ Usage: g++ sistemi1b.cpp -o sistemi1b; ./sistemi1b ║
* ╟────────────────────────────╥───────────────────────╝
* ╚════════════════════════════╝
*
* 1.b) Definire e calcolare norma inf. della matrice di Pascal
* MATRICE p
*/

float fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

float norma_inf(int matrice[10][10]) {
	float norma, tmp = 0;
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			tmp += fabs(matrice[i][j]);
		}
		if (tmp > norma) norma = tmp;
		tmp=0; //reset
	}
	return norma;
}

void stampa_matrice(int matrice[10][10]){
	for (int i=0; i<10; i++){
		cout << "{ ";
		for (int j=0; j<10; j++){
			cout << matrice[i][j];
			if (j+1!=10) cout<<", "; // inserimento virgola ','
		}
		cout << " }\n";
	}
}

int main() {
	cout << endl;
	int pascal[10][10];

	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			pascal[i][j] = (fact((i+1)+(j+1)-2))/(fact(i)*fact(j)); //i,j:0->9
		}
	}

	cout << "- Matrice di Pascal:" << endl;
	stampa_matrice(pascal);
	cout << "Norma matrice Pascal: " << norma_inf(pascal) << endl << endl;

	return 0;
}
