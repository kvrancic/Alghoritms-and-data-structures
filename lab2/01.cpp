#include <iostream>

using namespace std;

template <typename T> class List{
    private: 
        struct Cvor{
            T data; 
            Cvor *next; 
        };
        Cvor *head; 

public: 
    List() {head = nullptr;}
    bool upis(T data){
        Cvor *node = new (nothrow) Cvor;
        if(!node) return false; 
        node -> data = data; 
        node -> next = nullptr; 
        if(!head || data < head->data){
            node -> next = head;
            head = node; 
        }
        else{
            Cvor *curr = head;
            Cvor *prev; // moramo ga pamtim izmedu prev i curr treba staviti novi 
            while(curr != nullptr && curr->data < data){
                prev = curr; 
                curr = curr -> next; 
            }
            node -> next = curr; 
            prev -> next = node; 
        }
        return true; 
    }

    void ispis(){
        for(auto curr = head; curr != nullptr; curr = curr -> next){
            cout << curr -> data << " ";
        }
        return;
    }
};


int main(){
    int n; 
    cout << "Broj elemenata: ";
    cin >> n; 

    List<int> *lista = new List<int>; 

    cout << "Upisujte elemente: ";
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        lista->upis(x);
    }

    cout << endl; 
    lista -> ispis();
    delete lista; 

    return 0;
}
