#include <bits/stdc++.h>
using namespace std; 

/*
Napišite funkciju koja prima pokazivač na polje cijelih brojeva i koja vraća pokazivač na novo polje koje
se sastoji od nasumično poredanih kvadriranih elemenata ulaznog polja.
Primjerice, ako se ulazno polje sastoji od elemenata 1, 2, 3, 4 i 5, izlazno polje može biti 25, 16, 1, 9, 4.
Potrebno je napisati i glavni program koji od korisnika učitava cijeli broj n te zatim rezervira memorijski
prostor za cjelobrojno polje (polje) od n članova (možete koristiti operator new ili funkciju malloc).
Članove polja polje treba učitati s tipkovnice. Glavni program zatim poziva funkciju i ispisuje rezultat
izvođenja funkcije (izlazno polje).
*/

vector<int> randomSquares (int *ulaz);

int main(){
    int n; 
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i : randomSquares(A)){
        cout << i << ", ";
    }
    delete[] A;   
}

vector<int> randomSquares (int *ulaz){

    int i;
    for(i = 0; *(ulaz + i) != '\0'; i++);
    vector<int> izlaz; 
    for(i = 0; *(ulaz + i) != '\0'; i++) {
        izlaz.push_back(ulaz[i] * ulaz[i]); 
    }

   random_shuffle(izlaz.begin(), izlaz.end());

    return izlaz; 
}