#include <iostream> 
using namespace std; 

struct zapis
{
    int sifra; 
    string naziv; 
};


void obicanBubbleSort (zapis A[], int n, char smjer){
    int i, j;
    if(!smjer){
        for(int i = 0; i < n - 1; i++)
            for(int j = 1; j < n - i; j++)
                if(A[j].sifra < A[j - 1].sifra) swap(A[j], A[j - 1]);
    }
    else{
        for(int i = 0; i < n - 1; i++)
            for(int j = 1; j < n - i; j++)
                if(A[j].sifra < A[j - 1].sifra) swap(A[j], A[j - 1]);
    }

}

int main(){
    int n;
    cout << "Upisite broj koliko zapisa zelite unijeti: ";
    cin >> n;

    zapis *A = new zapis[n];
    for (int i = 0; i < n; i++)
    {
        zapis zapis;
        cout << "Upisite sifru: ";
        cin >> zapis.sifra;
        cin.ignore(1, '\n');
        cout << "Upisite naziv jela: ";
        getline(cin, zapis.naziv);
        A[i] = zapis;
    }

    char smjer;
    cout << "Upišite smjer sortiranja: ";
    cin >> smjer;

    obicanBubbleSort(A, n, smjer);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << A[i].sifra << ":" << A[i].naziv << endl;
            break;
        }
        cout << A[i].sifra << ":" << A[i].naziv <<  " | ";
    }

    delete[] A;
    return 0;
}