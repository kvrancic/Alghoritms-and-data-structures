#include<iostream>

using namespace std; 

template <typename T> int binarnoTrazi (T polje[], int n, T x);

/*
Napišite funkciju čiji je prototip: 
template <typename T> int binarnoTrazi (T polje[], int n, T x) ;
koja kao argumente prima pokazivač na početak uzlazno sortiranog polja (polje) čiji su članovi tipa T, 
broj članova polja (n) te broj x. U funkciji postupkom binarnog pretraživanja treba provjeriti nalazi li se x
u polju. Funkcija vraća indeks elementa x, ako se x nalazi u polju, a -1 inače. 
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n te realni broj x. 
Stvorite polje A od n članova tipa float (možete koristiti operator new ili funkciju malloc).
Potrebno je napuniti polje A s n vrijednosti tako da je A[i] = i * 1.1 te ispisati članove polja. Za broj x
potrebno je provjeriti nalazi li se u polju A (koristite funkciju binarnoTrazi). Potrebno je ispisati indeks
člana polja, ako je x pronađen u polju A, a poruku „Broj se ne nalazi u polju.“, ako x nije pronađen u polju
A.
Ponovite postupak s članovima tipa int, tako da je A[i] = i + 3;
*/

int main(){
    int n;
    float x;
    cin >> n >> x;
    float *A = new float[n];
    for(int i = 0; i < n; i++) {
        A[i] = i * 1.1;
        cout << A[i] << " ";
    }
    int rez = binarnoTrazi(A, n, x);
    if(rez == -1) cout << "Broj se ne nalazi u polju.";
    else cout << "Nalazi se na indeksu " << rez; 

    delete[] A; 
}

template <typename T> int binarnoTrazi (T polje[], int n, T x){
    //polje je low, polje + n je high
    int left = 0;
    int right = n - 1; 
    int mid = floor((left + right) / 2); 

    if(polje[mid] == x) return mid; 
    else if(left > right) return -1;
    else if(polje[mid] < x){
        left = mid + 1;
        // moramo uvesti y jer pamtimo left za koliko smo se makli u desno zbog ispisivanja indeksa -> svaki y će vratiti svoj left
        int y = binarnoTrazi(polje + left, right - left + 1, x);
        return y + left;  
    }
    else if(polje[mid] > x){
        //na ovoj strani samo smanjujemo n jer i dalje sve kreće od iste točke
        right = mid - 1; 
        return binarnoTrazi(polje, right - left + 1, x);
    }
}