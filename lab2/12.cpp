#include<iostream>
using namespace std; 

class Osoba{
    int age; 
    string name;

    public: 
    Osoba() {};
    Osoba(string name, int age) : name(name), age(age) {}
    string getName(){return name;}
    int getAge(){return age;}


    friend bool operator<(Osoba const& a, Osoba const& b){
        int cmp = a.age - b.age;
        if(cmp == 0){
            cmp = a.name[0] - b.name[0];
        }

        return cmp > 0;
    }
};

template <class T> void InsertionSort(T A[], int N){
    int i, j; 
    for(i = 1; i < N; i++){
        T temp = A[i];
        for(j = i; j > 0 && A[j - 1] < temp; j--){ // drugi uvjet vrijedi jer znamo da su sortirani 
            A[j] = A[j - 1]; //ostavljam prostor za umetanje pomicuci ih u desno
        }
        A[j] = temp;
    }
}

int main(void)
{
    static const int MAX = 5;
    Osoba *osobe = new Osoba[MAX];
    for(int i = 0; i < MAX; i++)
    {
        string ime;
        cout << "Upisite ime " << i + 1 << ". osobe: ";
        getline(cin, ime);
        unsigned short int starost;
        cout << "Upisite starost " << i + 1 << ". osobe: ";
        cin >> starost;
        cin.ignore(1, '\n');
        osobe[i] = Osoba(ime, starost);
    }

    InsertionSort(osobe, MAX);

    cout << "{";
    for(int i = 0; i < MAX; i++)
    {
        if(i == MAX - 1)
        {
            cout << "{\"" << osobe[i].getName() << "\"," << osobe[i].getAge() << "}}" << endl;
            break;
        }
        cout << "{\"" << osobe[i].getName() << "\"," << osobe[i].getAge() << "},";
    }

    delete[] osobe;

    return 0;
}
