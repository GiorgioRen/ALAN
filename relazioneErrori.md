# Algebra Lineare e Analisi Numerica

## Laboratorio Errori - A.A. 2020/2021

### Esercizio 1

I risultati delle operazioni differiscono in quanto:
- a: è variabile, va da $7$ a $7\,000\,000$
- b: 9e+20
- c: -9e+20

Per la prima operazione $(a+b)+c$ il valore di $a$ viene perso in quanto la precisione di macchina non è abbastanza per poter memorizzare il valore. Solo per valori grandi di $a$ si ottiene un risultato che approssima il valore reale dell'operazione.

La seconda operazione $a+(b+c)$ riesce a calcolare il valore reale in quanto $b$ e $c$ si annullano.


### Esercizio 2

Approssimazione di $f(x)=e^x$ con polinomio di Taylor:

Per i valori $e^{0.5}$ ed $e^{30}$, si può notare come aumentando il numero di iterazioni dell'algoritmo l'approssimazione si avvicina al valore "vero" calcolato con la libreria *math.h*

Per i valori $e^{-0.5}$ ed $e^{-30}$ oltre all'algoritmo precedente è stato utilizzato un secondo algoritmo per calcolare il risultato come $ e^{-x} \approx \frac{1}{\text{Taylor}(x)}$
Dall'output del programma si nota come a parità di iterazioni, il secondo algoritmo sia più preciso rispetto al primo.

### Esercizio 3

- Eps in singola precisione: 5.96046e-08
- Eps in doppia precisione: 1.11022e-16

### Output prodotto da `Errori.cpp`

```
+===========================+
+ ALAN - Laboratorio Errori +
+===========================+

*** Es 1 ***
- Per i=0, (a+b)+c vale: 0
- Per i=0, a+(b+c) vale: 7

- Per i=1, (a+b)+c vale: 0
- Per i=1, a+(b+c) vale: 70

- Per i=2, (a+b)+c vale: 0
- Per i=2, a+(b+c) vale: 700

- Per i=3, (a+b)+c vale: 0
- Per i=3, a+(b+c) vale: 7000

- Per i=4, (a+b)+c vale: 131072
- Per i=4, a+(b+c) vale: 70000

- Per i=5, (a+b)+c vale: 655360
- Per i=5, a+(b+c) vale: 700000

- Per i=6, (a+b)+c vale: 6.94682e+06
- Per i=6, a+(b+c) vale: 7e+06


*** Es 2 ***
Valori piccoli di errore => miglior approssimazione
Valore calcolato con math.h exp(0.5): 1.64872
  - Valore di exp(0.5) con Taylor da n=0 a 3: 1.64583
      Errore assoluto: 0.00288794
      Errore relativo: 0.00175162
  - Valore di exp(0.5) con Taylor da n=0 a 10: 1.64872
      Errore assoluto: 1.27627e-11
      Errore relativo: 7.74096e-12
  - Valore di exp(0.5) con Taylor da n=0 a 50: 1.64872
      Errore assoluto: 4.44089e-16
      Errore relativo: 2.69354e-16
  - Valore di exp(0.5) con Taylor da n=0 a 100: 1.64872
      Errore assoluto: 4.44089e-16
      Errore relativo: 2.69354e-16
  - Valore di exp(0.5) con Taylor da n=0 a 150: 1.64872
      Errore assoluto: 4.44089e-16
      Errore relativo: 2.69354e-16

Valore calcolato con math.h exp(30): 1.06865e+13
  - Valore di exp(30) con Taylor da n=0 a 3: 4981
      Errore assoluto: 1.06865e+13
      Errore relativo: 1
  - Valore di exp(30) con Taylor da n=0 a 10: 2.3883e+08
      Errore assoluto: 1.06862e+13
      Errore relativo: 0.999978
  - Valore di exp(30) con Taylor da n=0 a 50: 8.52041e+12
      Errore assoluto: 2.16606e+12
      Errore relativo: 0.202692
  - Valore di exp(30) con Taylor da n=0 a 100: 8.52041e+12
      Errore assoluto: 2.16606e+12
      Errore relativo: 0.202692
  - Valore di exp(30) con Taylor da n=0 a 150: 8.52041e+12
      Errore assoluto: 2.16606e+12
      Errore relativo: 0.202692

Valore calcolato con math.h exp(-0.5): 0.606531
  - Valore di exp(-0.5) con Taylor da n=0 a 3: 0.604167
      Errore assoluto: 0.00236399
      Errore relativo: 0.00389757
  - Valore di exp(-0.5) con Taylor da n=0 a 3 come 1/exp(x): 0.607595
      Errore assoluto: 0.00106428
      Errore relativo: 0.0017547
  - Valore di exp(-0.5) con Taylor da n=0 a 10: 0.606531
      Errore assoluto: 1.17416e-11
      Errore relativo: 1.93586e-11
  - Valore di exp(-0.5) con Taylor da n=0 a 10 come 1/exp(x): 0.606531
      Errore assoluto: 4.69513e-12
      Errore relativo: 7.74097e-12
  - Valore di exp(-0.5) con Taylor da n=0 a 50: 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16
  - Valore di exp(-0.5) con Taylor da n=0 a 50 come 1/exp(x): 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16
  - Valore di exp(-0.5) con Taylor da n=0 a 100: 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16
  - Valore di exp(-0.5) con Taylor da n=0 a 100 come 1/exp(x): 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16
  - Valore di exp(-0.5) con Taylor da n=0 a 150: 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16
  - Valore di exp(-0.5) con Taylor da n=0 a 150 come 1/exp(x): 0.606531
      Errore assoluto: 1.11022e-16
      Errore relativo: 1.83045e-16

Valore calcolato con math.h exp(-30): 9.35762e-14
  - Valore di exp(-30) con Taylor da n=0 a 3: -4079
      Errore assoluto: 4079
      Errore relativo: 4.35901e+16
  - Valore di exp(-30) con Taylor da n=0 a 3 come 1/exp(x): 0.000200763
      Errore assoluto: 0.000200763
      Errore relativo: 2.14545e+09
  - Valore di exp(-30) con Taylor da n=0 a 10: 1.21255e+08
      Errore assoluto: 1.21255e+08
      Errore relativo: 1.29579e+21
  - Valore di exp(-30) con Taylor da n=0 a 10 come 1/exp(x): 4.18709e-09
      Errore assoluto: 4.18699e-09
      Errore relativo: 44744.2
  - Valore di exp(-30) con Taylor da n=0 a 50: 2.62577e+11
      Errore assoluto: 2.62577e+11
      Errore relativo: 2.80602e+24
  - Valore di exp(-30) con Taylor da n=0 a 50 come 1/exp(x): 1.17365e-13
      Errore assoluto: 2.3789e-14
      Errore relativo: 0.25422
  - Valore di exp(-30) con Taylor da n=0 a 100: 2.62577e+11
      Errore assoluto: 2.62577e+11
      Errore relativo: 2.80602e+24
  - Valore di exp(-30) con Taylor da n=0 a 100 come 1/exp(x): 1.17365e-13
      Errore assoluto: 2.3789e-14
      Errore relativo: 0.25422
  - Valore di exp(-30) con Taylor da n=0 a 150: 2.62577e+11
      Errore assoluto: 2.62577e+11
      Errore relativo: 2.80602e+24
  - Valore di exp(-30) con Taylor da n=0 a 150 come 1/exp(x): 1.17365e-13
      Errore assoluto: 2.3789e-14
      Errore relativo: 0.25422


*** Es 3 ***
Valore massimo di ds=24
Valore massimo di dd=53
Singola precisione di eps=5.96046e-08
Doppia precisione di eps=1.11022e-16
```
