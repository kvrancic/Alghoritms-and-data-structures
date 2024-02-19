#include<iostream> 
#include<cmath>
using namespace std; 

void f (int polje[], int n, int m); 

int main(){
    int m, n;
    cin >> n >> m; 
    int *A = new int[n]; 
    f(A, n, m); 
    

    for(int i = 0; A[i] != '\0'; i++){
        cout << A[i] << ", ";
    }
    

    delete[] A;
}

void f (int polje[], int n, int m){
    if(n == 1) {
        polje[0] = 1;
        return;
    }
    else{
        polje[n - 1] = pow(m, n - 1);
    } 
    f(polje, n - 1, m);
    
}

