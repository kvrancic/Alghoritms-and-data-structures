#include <iostream> 
using namespace std; 

void selection2Sort (int A[], int n, char smjer){
    if (smjer == '0')
    { // uzlazno sortiranje
        for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = A[i], max = A[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (A[k] > max) {
                max = A[k];
                max_i = k;
            } else if (A[k] < min) {
                min = A[k];
                min_i = k;
            }
        }
 
        swap(A[i], A[min_i]);
 
        if (A[min_i] == max) //AKO SMO SLUCAJNO POMAKLI NAJVECI KAD SMO SWAPALI PRVI PUT
            swap(A[j], A[min_i]);
        else
            swap(A[j], A[max_i]);
    }
    }
    else
    {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = A[i], max = A[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (A[k] > max) {
                max = A[k];
                max_i = k;
            } else if (A[k] < min) {
                min = A[k];
                min_i = k;
            }
        }
        swap(A[i], A[max_i]);
        if (A[max_i] == min)
            swap(A[j], A[max_i]);
        else
            swap(A[j], A[min_i]);
    }
    }
}

int main(){
    int n;
    cout << "Upisi n: ";
    cin >> n;

    int *A = new int[n];
    cout << "Upisujte redom elemente polja: " << endl;
    for(int i = 0; i < n; i++) cin >> A[i];

    char smjer;
    cout << "Upisite smjer ";
    cin >> smjer;

    selection2Sort(A, n, smjer);

    for(int i = 0; i < n; i++) cout << A[i] << " ";

    delete[] A;
    return 0;   
}
