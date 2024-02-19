#include <iostream> 
using namespace std; 

struct Zapis{
    int zip; 
    string name;
};

void insertionSort (Zapis A[], int n, char smjer){
    if(!smjer){
        for(int i = 0; i < n; i++){
            Zapis temp = A[i]; 
            int j;
            //vrti dok god je trenutni element MANJI od elemenata prije sebe 
            for(j = i; j >= 1 && A[j-1].zip < temp.zip; j--){ 
                A[j] = A[j-1]; //pomici elemente u desno da otvoris prostor trenutnom
            }
            A[j] = temp; //pospremi na odgovarajuce mjesto
        }
    } 
    else{
        for(int i = 0; i < n; i++){
            Zapis temp = A[i]; 
            int j;
            //vrti dok god je trenutni element VECI od elemenata prije sebe 
            for(j = i; j >= 1 && A[j-1].zip > temp.zip; j--){ 
                A[j] = A[j-1]; //pomici elemente u desno da otvoris prostor trenutnom
            }
            A[j] = temp; //pospremi na odgovarajuce mjesto
        }
    }

}

int main(void)
{
    int n;
    cout << "Upisite broj koliko zapisa zelite unijeti: ";
    cin >> n;

    Zapis *A = new Zapis[n];
    for (int i = 0; i < n; i++)
    {
        Zapis zapis;
        cout << "Upisite postanski broj mjesta: ";
        cin >> zapis.zip;
        cin.ignore(1, '\n');
        cout << "Upisite naziv mjesta: ";
        getline(cin, zapis.name);
        A[i] = zapis;
    }

    char smjer;
    cout << "Upišite smjer sortiranja: ";
    cin >> smjer;

    insertionSort(A, n, smjer);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << A[i].zip << ":" << A[i].name << endl;
            break;
        }
        cout << A[i].zip << ":" << A[i].name <<  " | ";
    }

    delete[] A;
    return 0;
}