#include<iostream> 
using namespace std; 

void Zamijeni(string *prvi, string *drugi){
    string temp;
    temp = *prvi; //POINTERI 
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int N, int smjer){
    bool flag; 
    if(smjer){
        for(int i = 0; i < N - 1; i++){
        flag = true; 
        for(int j = 0; j < N - i - 1; j++){
            if(A[j] > A[j + 1]){
                Zamijeni(&A[j], &A[j + 1]); 
                flag = false; 
            }
        }
        if(flag) return;
        }
    }
    else{
        for(int i = 0; i < N - 1; i++){
        flag = true; 
        for(int j = 0; j < N - i - 1; j++){
            if(A[j] < A[j + 1]){
                Zamijeni(&A[j], &A[j + 1]);
                flag = false; 
            }
        }
        if(flag) return;
        }
    }
}

int main(){
    string *stringovi = new string[4];
    cout << "Upisuj imena" << endl; 
    for(int i = 0; i < 4; i++){
        cin >> stringovi[i]; 
    }

    cout << "Upisi smjer ";
    int smjer; 
    cin >> smjer; 

    BubbleSortPoboljsani(stringovi, 4, smjer);

    for(int i = 0; i < 4; i++){
        cout << stringovi[i] << " ";
    }
}