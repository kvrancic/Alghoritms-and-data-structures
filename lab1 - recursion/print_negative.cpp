#include <iostream> 
using namespace std;

void ispis (float polje[], int n);

int main(){
    int n; 
    cin >> n; 
    float *A = new float[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }


    ispis(A, n);

    delete[] A;
    return 0;
}

void ispis (float polje[], int n){
    if(n <= 0) return; 
    if(*polje < 0) cout << *polje << endl; 
    return ispis(polje + 1, n - 1);
}