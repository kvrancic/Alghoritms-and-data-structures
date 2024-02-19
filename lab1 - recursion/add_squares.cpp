#include<iostream> 
#include <cmath>
using namespace std; 

/*
Napišite funkciju čiji je prototip: 
int zbrojiKvadrate (int polje[], int n) ; 
koja kao argumente prima polje polje i broj članova (n) te rekurzivno zbraja članove polja koji su kvadrati
nekog drugog prirodnog broja.
Primjer: za polje [0, 1, 2, 3, 4] funkcija treba vratiti 5 (zbrojeni su 1 i 4, koji su kvadrati brojeva 1 i 2). 
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i stvoriti cjelobrojno
polje A od n članova (možete koristiti operator new ili funkciju malloc).
Potrebno je napuniti polje A s n slučajno odabranih prirodnih brojeva iz intervala [1, 100] te ispisati polje
i zbroj članova polja koji su kvadrati nekog drugog prirodnog broja (pozvati funkciju zbrojiKvadrate).
*/

int zbrojiKvadrate (int polje[], int n);

int main(){
    int n; 
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    cout << zbrojiKvadrate(A, n);

    delete[] A; 
}

int zbrojiKvadrate (int polje[], int n){
    if(n <= 0)
        return 0;
    else if(sqrt(*polje) == round(sqrt(*polje))) return *polje + zbrojiKvadrate(polje + 1, n - 1);
    else return zbrojiKvadrate(polje + 1, n - 1);
}
    
