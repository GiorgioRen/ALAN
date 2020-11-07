<!--
> Giorgio Rengucci - 4483986
> ALAN - DIBRIS A.A. 2020/2021
-->
# ALAN - Laboratorio 01

### Errori:

---

1. Si consideri il numero di matricola del primo componente, in ordine alfabetico, del gruppo; si indichi con d0 e d1, rispettivamente, l’ultima e la penultima cifra di tale numero di matricola.
Posto a = (d0 +1)·10i, con i = 0,1,...,6, b = (d1 +1)·1020, c = −b, eseguire i seguenti calcoli in aritmetica di macchina a doppia precisione, cio`e utilizzando variabili di tipo double:
• (a+b)+c • a+(b+c)

Premessa. Una nota tecnica di analisi matematica per approssimare una funzione f(x) difficile da trattare, `e quella che fa uso del “Polinomio di Taylor”: si definisce un opportuno polinomio di grado N (i cui coefficienti dipendono da f), che al crescere del grado approssima sempre meglio la funzione di partenza. Ad esempio, il polinomio
f N ( x ) = 􏰀N x n
n!
rappresenta il polinomio di Taylor di grado N per la funzione f(x) = ex e valori di x non troppo distanti da 0. Si noti che si sta cos`ı approssimando il problema “calcolare f (x)” col nuovo problema “calcolare fN (x)”.

2. Fissato l’intero positivo N, implementare un programma che permetta di calcolare fN(x) per il punto x e il grado N dati in input.
Considerare i due algoritmi seguenti per i valori descritti dei parametri x e N, confrontando i risultati ottenuti per fN (x) con i valori restituiti per f (x) dalla funzione exp della libreria ANSI math.h, tramite errore relativo e assoluto.
        - Algoritmo 1: determinare un’approssimazione di f(x) per il punto x = 0.5 ed il punto x = 30, valutando fN (x) per N = 3, 10, 50, 100, 150. Ripetere l’esercizio considerando il punto x = −0.5 ed il punto x = −30.
        - Algoritmo 2: Osservando che per l’esponenziale vale f (−x) = 1/f (x) e quindi f (−x) ≈ 1/fN (x), de- terminare una diversa approssimazione di f(−0.5) e f(−30) nel modo seguente: valutare fN(+0.5) e fN (+30) per N = 3, 10, 50, 100, 150 e, successivamente, calcolarne il reciproco.

3. Implementare un programma che determina la precisione di macchina eps, ossia il valore positivo eps = 2−d, dove d `e il piu` grande intero positivo tale che 1 + 2−d > 1 in aritmetica di macchina; calcolarne il valore sia in singola che in doppia precisione.
