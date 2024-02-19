#include <iostream>
using namespace std; 

template <typename T> class List{
    struct Cvor{
        T data; 
        Cvor *next; 
    };
    Cvor *head = nullptr;

    public: 
    bool upis(T element){
        Cvor *newElement = new (nothrow) Cvor; 
        if(!newElement) return false; 
        newElement -> data = element; 
        newElement -> next = nullptr; 
        if(!head) head = newElement;
        else{
            Cvor *curr;
            for(curr = head; curr -> next != nullptr; curr = curr -> next);
            curr -> next = newElement;
        }
    }

    void ispis(){
        for(auto curr = head; curr != nullptr; curr = curr -> next)
            cout << curr -> data << " ";
    }
};

int main(){
    int n; 
    cout << "Koliko stringova zelis upisati ";
    cin >> n;
    List<string> *lista = new List<string>; 
    for(int i = 0; i < n; i++){
        string x; 
        cin >> x;
        lista->upis(x);
    }

    lista -> ispis();
    delete lista;
    return 0;
}

