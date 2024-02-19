#include <iostream> 
using namespace std; 

class Red{
    struct Cvor{
        double data; 
        Cvor *next; 
    };
    Cvor* head = nullptr; //read
    Cvor *tail = nullptr; //write 

    public: 
    bool dodaj(double broj){
        Cvor *newAtom = new(nothrow) Cvor; 
        if(!newAtom) return false; 
        newAtom -> data = broj; 
        newAtom -> next = nullptr; 

        if(head == nullptr) head = newAtom; 
        else tail -> next = newAtom; 
        tail = newAtom; 
        return true; 
    }

    bool poljeURed(int polje[], int n){
        if(n == 0) return true;  
        if(!dodaj(polje[n - 1])) return false; 
        else return poljeURed(polje, n - 1);
    }
};

int main(){
    srand(time(0));
    int A[10];
    for(int i = 0; i < 10; i++){
        int x = rand() % 10 + 1;
        cout << x << " ";
        A[i] = x; 
    }

    Red r;
    r.poljeURed(A, 10);

    return 0;
}