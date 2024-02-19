#include<iostream>
using namespace std; 

class Stog{
    private: 
    struct Atom{
        int data; 
        Atom *next; 
    };
    Atom *head = nullptr; 

    public: 
    bool push(int el){
        Atom *newElement = new (nothrow) Atom;
        if(!newElement) return false;
        newElement -> data = el; 
        newElement -> next = head; 
        head = newElement; 
        return true;
    }

    void ispis(){
        for(auto curr = head; curr != nullptr; curr = curr -> next){
            cout << curr -> data << " ";
        }
    }
};

int main(){
    srand(time(0));
    Stog st;
    for(int i = 0; i < 101; i++){
        int x = rand();
        st.push(x);
    }

    st.ispis();

}