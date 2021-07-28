#include <iostream>
#include <cmath>
using namespace std;
/*
 * ╔════════════════════════════╗
 * ║ ALAN - Labo Error01        ║
 * ║                            ║
 * ║   --> Teams Canale 6 <--   ║
 * ╟────────────────────────────╨──────────────────╗
 * ║ Usage: g++ error1.cpp -O0 -o error1; ./error1 ║
 * ╟────────────────────────────╥──────────────────╝
 * ╚════════════════════════════╝
 *
 * Considerare il numero di matricola in ordine alfabetico.
 * d0 -> ultima cifra
 * d1 -> penultima cifra
 *
 * a = (d0 +1)·10^1 con i = 0,1,...,6
 * b = (d1 +1)·1020
 * c = −b
 *
 * calcolare (a+b)+c e a+(b+c)
 *
 * xxxxx86
 * d0 = 6
 * d1 = 8
 */
int main(){
    // matricola: xxxxx86
    int d0=6, d1=8;
    double a, b=(d1+1)*pow(10,20), c=-b;

    cout << endl;
    for (int i = 0; i < 7; i++){
        //calcolo a
        a = (d0 +1)*pow(10,i);
        cout << "- Per i=" << i << ", (a+b)+c vale: " << (a+b)+c << endl;
        cout << "- Per i=" << i << ", a+(b+c) vale: " << a+(b+c) << endl << endl;
    }
    return 0;
}
