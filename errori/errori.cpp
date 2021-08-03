#include <iostream>
#include <cmath>
#include "support_errori.h"
using namespace std;

/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Errori         ║
 * ║┌───────────────────────────╨───────────────┐
 * ║│ Usage: g++ errori.cpp -o errori; ./errori │
 * ║└───────────────────────────╥───────────────┘
 * ╚════════════════════════════╝
 */

int main(){

	cout << "\e[1m+===========================+\n+ ALAN - Laboratorio Errori +\n+===========================+\e[0m";
	
	/********** es 1 *********************************************************/
	cout << "\n\n\e[1m*** Es 1 ***\e[0m\n";
	/**
	 * Considerare il numero di matricola in ordine alfabetico.
	 * d0 -> ultima cifra
	 * d1 -> penultima cifra
	 *
	 * a = (d0 +1)·10^i con i = 0,1,...,6
	 * b = (d1 +1)·1020
	 * c = −b
	 *
	 * calcolare (a+b)+c e a+(b+c)
	 */
	// matricola: xxxxx86
	int d0=6, d1=8;
	double a, b=(d1+1)*pow(10,20), c=-b;

	for (int i = 0; i < 7; i++){
		//calcolo a
		a = (d0 +1)*pow(10,i);
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		cout << "- Per i=" << i << ", (a+b)+c vale: " << (a+b)+c << endl;
		cout << "- Per i=" << i << ", a+(b+c) vale: " << a+(b+c) << endl << endl;
	}
	
	/********** es 2 *********************************************************/
	cout << "\n\e[1m*** Es 2 ***\e[0m\n";
	/*
	 * Calcolo di exp(x) con math.h e serie di Taylor:
	 * - x assume valori: { 0.5, 30, -0,5, -30 }
	 * - Espansione di Taylor con approssimazioni 0->n di { 3, 10, 50, 100 e 150 }
	 */
	const double x[4] = {0.5, 30, -0.5, -30}; // valori di x da calcolare
	const double N[5] = {3, 10, 50, 100, 150}; // numero di passi di taylor
	double math_result, taylor_result, one_over_taylor_result= 0;

	cout << "Valori piccoli di errore => miglior approssimazione";

	for (int i=0; i < (sizeof(x)/sizeof(*x)); i++){
		math_result = exp(x[i]);
		cout << "\nValore calcolato con math.h exp(" << x[i] << "): " << math_result << endl;
		for (int j = 0; j < (sizeof(N)/sizeof(*N)); j++){
			taylor_result = taylor(x[i],N[j]);
			cout << "  - Valore di exp(" << x[i] << ") con Taylor da n=0 a " << N[j] << ": " << taylor_result << endl;
			abs_error(math_result, taylor_result);
			rel_error(math_result, taylor_result);
			if(x[i]<0){
				one_over_taylor_result = 1/taylor(-x[i],N[j]); //-x[i] perchè voglio x positiva
				cout << "  - Valore di exp(" << x[i] << ") con Taylor da n=0 a " << N[j] << " come 1/exp(x): " << one_over_taylor_result << endl;
				abs_error(math_result, one_over_taylor_result);
				rel_error(math_result, one_over_taylor_result);
			}
		}
	}
	
	/********** es 3 *********************************************************/
	cout << "\n\n\e[1m*** Es 3 ***\e[0m\n";
	/*
	 * Calcolo della precisione di macchina 'eps'
	 * eps = 2^{-d} con d più grande intero positivo t.c. 1+2^{-d} > 1
	 * calcolo eps in singola precisione e doppia precisione
	 */
	float epss = 0; // eps in singola precisione
	double epsd = 0; // eps in doppia precisione

	int ds; // d in singola precisione
	int dd; // d in doppia precisione

	for(ds = 0; (1+powf(2, -ds))>1; ) ds++;
	for(dd = 0; (1+pow(2, -dd))>1; dd++)

	epss = powf(2, -ds);
	epsd = pow(2, -dd);

	cout << "Valore massimo di ds=" << ds << endl;
	cout << "Valore massimo di dd=" << dd << endl;
	cout << "Singola precisione di eps=" << epss << endl;
	cout << "Doppia precisione di eps=" << epsd << endl;
	cout << endl;
	return 0;
}