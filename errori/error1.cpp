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
 * xxxxx86
 * d0 = 6
 * d1 = 8
 */
int main(){
    // matricola: xxxxx86
    int d0=6, d1=8;
    double a, b=(d1+1)*pow(10,20), c=-b, o1, o2;

    for (int i = 0; i < 7; i++){
        //calcolo a
        a = (d0 +1)*pow(10,i);
        // calcolo di 01 e 02
        o1=a+b;
        o2=b+c;
        o1=o1+c;
        o2=o2+a;
        cout << "- Per i=" << i << " di (a+b)+c vale: " << o1 << endl;
        cout << "- Per i=" << i << " di a+(b+c) vale: " << o2 << endl;
    }
    return 0;
}
