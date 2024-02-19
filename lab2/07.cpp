#include<iostream> 
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
        Cvor *newAtom = new (nothrow) Cvor; 
        if(!newAtom) return false; 
        newAtom -> data = broj; 
        newAtom -> next = nullptr; 

        if(tail == nullptr) head = newAtom; 
        else{
            tail -> next = newAtom; //prethodni nek pokazuje na novi 
        }
        tail = newAtom; 
        return true; 
    } 

    bool skini(double *broj){
        if(head == nullptr) return false;  //ne mozemo gledati je li == tail jer necemo uzet zadnji el
        *broj = head -> data; 
        Cvor *tbd = head; 
        head = head -> next; 
        delete tbd; 
        if(head == nullptr) tail == nullptr; //!!!!!
        return true;
    }
};

    int main(){
        int n; 
        cout << "kolko brojeva zelis staviti u red "; 
        cin >> n; 

        Red r;
        double x;
        cout << "Upisujte brojeve" << endl;
        for(int i = 0; i < n; i++){
            cin >> x; 
            r.dodaj(x);
        }

        while(r.skini(&x)){
            cout << x << " ";
        }
        return 0;

}