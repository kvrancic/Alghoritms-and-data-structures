#include <iostream>
using namespace std;
/* 
Napišite funkciju čiji je prototip: 
double exp (double x, int n, int *fakt, double *xpot); 
koja kao argument prima realni broj x i broj članova reda (n) te rekurzivno računa e na x
Funkcija prima i dva dodatna argumenta: fakt (adresa na kojoj je pohranjen n! za trenutni n) i xpot
(adresa na kojoj je pohranjena n-ta potencija broja x za trenutni n). Korištenjem ovih pomoćnih
argumenata trebate napisati funkciju exp koja se izvodi u vremenu O(n). 
Primjer: za x = 1 i n = 0, funkcija treba vratiti 1; za x = 1 i n = 1, funkcija treba vratiti 2; za x = 1 i n = 3 
funkcija treba vratiti 2.666667; x = 1 i n = 10, funkcija treba vratiti 2.718282, itd. 
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i broj x tipa double. 
Stvorite polje A od n članova tipa double (možete koristiti operator new ili funkciju malloc). 
Polje A treba popuniti tako da član polja A[i] sadrži vrijednost izraza e
x izračunatog korištenjem funkcije
exp za i članova reda. Npr. za n = 5 i x = 1, polje A treba sadržavati vrijednosti [1.000000, 2.000000, 
2.500000, 2.666667, 2.708333]. Ispisati članove polja A. 
*/ 

double exp (double x, int n, int *fakt, double *xpot); 

int main(){
    int n, x; 
    cin >> n >> x;
    int *A = new int[n];
    int fakt;
    double xpot; 
    for(int i = 0; i < n; i++) {
        A[i] = exp(x, i, &fakt, &xpot);
        cout << A[i] << " ";
}
    delete[] A; 
}

double exp (double x, int n, int *fakt, double *xpot){
    if(n == 0){
        *fakt = 1; 
        *xpot = 1;
        return 1; 
    }
    double prev = exp(x, n - 1, fakt, xpot);
    *xpot *= x; 
    *fakt *= n; 
    return prev + *xpot / *fakt;
}
