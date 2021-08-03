#include <iostream>
#include <cmath>
using namespace std;

/* Funzione fattoriale */
float fact(float n) { return (n<=1) ? 1 : n * fact(n-1); }

/* Funzione calcolo norma infinita */
float norma_inf(float *matrice[], int n) {
	float norma = 0;
	float tmp = 0;
	for (unsigned int i=0; i<n; i++){
		for (unsigned int j=0; j<n; j++){
			tmp += fabs(matrice[i][j]);
		}
		if (tmp > norma){ norma = tmp;}
		tmp=0; //reset
	}
	return norma;
}

float norma_inf_vect(float *vettore, int dim){
	float norma = 0;
	float tmp = 0;
	for (unsigned int i=0; i<dim; i++){
		tmp = fabs(vettore[i]);
		if (tmp>norma){
			norma = tmp;
		}
	}
	return norma;
}

/* PrettyPrint matrice */
void stampa_matrice(float *matrice[], int n1, int n2){
	for (int i=0; i<n1; i++){
		cout << "{ ";
		for (int j=0; j<n2; j++){
			if (matrice[i][j]<0) { cout << matrice[i][j]; }
			else { cout << " " << matrice[i][j]; }
			if (j+1!=n1) { cout << ", "; }// inserimento virgola ','
		}
		cout << " }\n";
	}
}

/* Stampa del vettore */
void stampa_vettore(float vettore[], int dim)
{ for (int i=0; i<dim; i++) { cout << "[" << vettore[i] << "]\n"; }}

/* Stampa del vettore in orizzontale [a1, a2, ..., an] */
void stampa_vettore_trasposto(float vettore[], int dim)
{ for (int i=0; i<dim; i++) { cout << (i==0 ? "[" : "") << vettore[i] << (i+1<dim ? ", " : "]\n"); }}

/* Funzione che moltiplica la matrice per il vettore composto da tutti '1' */
// attenzione: funziona solo con matrici quadrate
// ritorna il vettore calcolato
float* trova_b(float *matrice[], int dim){
	//cout << "\ndim:"<<dim;
	float *b = new float[dim];
	float elem = 0;
	for (unsigned int i=0; i<dim; i++){
		for (unsigned int j=0; j<dim; j++){
			elem += matrice[i][j];
		}
		//cout << "\nb["<<i<<"] = "<<elem;
		b[i] = elem;
		elem = 0;
	}
	return b;
}

/* Perturba il vettore */
float* perturba_b(float *vettore, int dim){
	float *b_perturbato = vettore;
	float n_inf = norma_inf_vect(vettore, dim);

	for (unsigned int i=0; i<dim; i++){
		b_perturbato[i] += (n_inf * (i%2==0 ? -0.01 : 0.01));
	}
	return b_perturbato;
}

/* Eliminazione gaussiana */
float* gauss_plus(float** matrice, float* vettore, int dim){
	float* soluzioni = new float[dim]; // vettore delle soluzioni

	float mat[dim][dim+1]; // matrice composta dalla matrice originale e vettore dei termini noti
	for (int i=0; i<dim; i++){
		for (int j=0; j<dim+1; j++){
			j<dim ? mat[i][j] = matrice[i][j] : mat[i][j] = vettore[i];
		}
	}

	for (int i=0; i<dim-1; i++){
		for (int j=i+1; j<dim; j++){
			float f=mat[j][i]/mat[i][i];
			for (int k=0; k<dim+1; k++){
				mat[j][k] = mat[j][k]-f*mat[i][k];
			}
		}
	}
	// scorrimento indietro per trovare la soluzione
	for (int i=dim-1; i>=0; i--){
		soluzioni[i]=mat[i][dim];
		for (int j=i+1; j<dim ;j++){
			if (i!=j){
				soluzioni[i]=soluzioni[i]-mat[i][j]*soluzioni[j];
			}
		}
		soluzioni[i]=soluzioni[i]/mat[i][i];
	}

	//stampa_vettore_trasposto(soluzioni, dim);
	return soluzioni;
}