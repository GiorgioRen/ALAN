#include <iostream>
#include <cmath> // pow function

using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error03        ║
 * ║                            ║
 * ║   --> Teams Canale 6 <--   ║
 * ╟────────────────────────────╨──────────────────╗
 * ║ Usage: g++ error3.cpp -O0 -o error3; ./error3 ║
 * ╟────────────────────────────╥──────────────────╝
 * ╚════════════════════════════╝
 *
 * Calcolo della precisione di macchina 'eps'
 * eps = 2^{-d} con d più grande intero positivo t.c. 1+2^{-d} > 1
 * calcolare eps in singola precisione e doppia precisione
 */
int main(){

    float epss = 0; // eps in singola precisione
    double epsd = 0; // eps in doppia precisione

    int ds; // d in singola precisione
    int dd; // d in doppia precisione

    for(ds = 0; (1+powf(2, -ds))>1; ) ds++;
    for(dd = 0; (1+pow(2, -dd))>1; dd++)

    epss = powf(2, -ds);
    epsd = pow(2, -dd);

    cout << endl;
    cout << "Valore massimo di ds=" << ds << endl;
    cout << "Valore massimo di dd=" << dd << endl;
    cout << "Singola precisione di eps=" << epss << endl;
    cout << "Doppia precisione di eps=" << epsd << endl;
    cout << endl;

    return 0;
}
