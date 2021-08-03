#include <iostream>
#include <cmath>
using namespace std;

/* Funzione fattoriale */
float fact(float n) { return (n<=1) ? 1 : n * fact(n-1); }

/* Serie di Taylor */
double taylor(double x, double n){
	double t = 0;
	for(int i=0;i<=n;i++)
		t += pow(x,i)/fact(i);
	return t;
}

/* Funzioni calcolo errore assoluto e ralativo */
void abs_error(double m_result, double t_result){
	cout << "      Errore assoluto: " << (double)abs(t_result-m_result) << endl;
}
void rel_error(double m_result, double t_result){
	cout << "      Errore relativo: " << (double)abs(t_result-m_result)/m_result << endl;
}

