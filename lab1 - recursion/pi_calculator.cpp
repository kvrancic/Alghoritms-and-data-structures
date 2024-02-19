#include<iostream>
#include <cmath>
using namespace std; 

/* 
Napišite funkciju čiji je prototip: 
double pi (int n) ; 
koja kao argument prima broj članova reda (n) te rekurzivno računa broj π prema izrazu:

Primjer: za n = 1, funkcija treba vratiti 4; za n = 2, funkcija treba vratiti 2.666667; za n = 10, funkcija treba
vratiti 3.041840, itd. 
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i stvoriti polje A od n
članova tipa double (možete koristiti operator new ili funkciju malloc).
Zatim polje treba popuniti tako da član polja A[i] sadrži aproksimaciju broja π izračunatu korištenjem
funkcije pi za i+1 članova reda. Npr. za n = 3, polje treba sadržavati vrijednosti [4.000000, 2.666667, 
3.466667]. Ispisati članove polja A.
*/

double pi (int n) ; 

int main(){
    int n; 
    cin >> n;
    cout << pi(n);
}

double pi(int n){
    if(n == 1)
        return 4; 
    else return 4 * pow(-1, n + 1)/(2*n - 1) + pi(n - 1);
}
    
    
