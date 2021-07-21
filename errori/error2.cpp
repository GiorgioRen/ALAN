#include <iostream> // I/O
#include <cmath> // exp(x) & pow()
#include <iomanip> // used for formatting in table
using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error02        ║
 * ║                            ║
 * ║   --> Teams Canale 6 <--   ║
 * ╟────────────────────────────╨──────────────────╗
 * ║ Usage: g++ error2.cpp -O0 -o error2; ./error2 ║
 * ╟────────────────────────────╥──────────────────╝
 * ╚════════════════════════════╝
 *
 *)────────────────────────────────────────────────────────────────────────────┐
 * Calcolo di exp(x) con math.h e serie di Taylor:
 * - x assume valori: { 0.5, 30, -0,5, -30 }
 * - Espansione di Taylor con approssimazioni 0->n di { 3, 10, 50, 100 e 150 }
 *)────────────────────────────────────────────────────────────────────────────┘
 */

//────────( Funzioni di supporto )────────//
//Funzione fattoriale ricorsiva n!
double fact(double n){
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}

// Serie di Taylor
double taylor(double x, double n){
    double t = 0;
    for(int i=0;i<=n;i++)
        t += pow(x,i)/fact(i);
    return t;
}
//────────────────────────//

void abs_error(double m_result, double t_result){
    cout << "\t\tErrore assoluto: " << (double)abs(t_result-m_result) << endl;
}
void rel_error(double m_result, double t_result){
    cout << "\t\tErrore relativo: " << (double)abs(t_result-m_result)/m_result << endl << endl;
}


//────────( Main )────────//
int main(){

    const double x[4] = {0.5, 30, -0.5, -30}; // valori di x da calcolare
    const double N[5] = {3, 10, 50, 100, 150}; // numero di passi di taylor
    double math_result, taylor_result, one_over_taylor_result= 0;

    cout << "\n\n───( Valori piccoli di errore => miglior approssimazione )───\n\n";

    for (int i=0; i < (sizeof(x)/sizeof(*x)); i++){
        math_result = exp(x[i]);
        cout << "\nValore calcolato con math.h exp(" << x[i] << "): " << math_result << endl;
        for (int j = 0; j < (sizeof(N)/sizeof(*N)); j++){
            taylor_result = taylor(x[i],N[j]);
            cout << "\t- Valore di exp(" << x[i] << ") con Taylor da n=0 a " << N[j] << ": " << taylor_result << endl;
            abs_error(math_result, taylor_result);
            rel_error(math_result, taylor_result);
            if(x[i]<0){
                one_over_taylor_result = 1/taylor(x[i],N[j]);
                cout << "\t- Valore di exp(" << x[i] << ") con Taylor da n=0 a " << N[j] << " come 1/exp(x): " << one_over_taylor_result << endl;
                abs_error(math_result, one_over_taylor_result);
                rel_error(math_result, one_over_taylor_result);
            }
        }
    }
    return 0;
}
//────────────────────────//
