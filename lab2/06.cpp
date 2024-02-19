#include <iostream>
using namespace std; 

class Red{
    static const int MAX = 10; 
    int read = 0;
    int write = 0;
    double red[MAX]; 

    public: 
    bool dodaj(double broj){
        if (write >= MAX) return false; 
        else{
            red[write++] = broj;
            return true;  
        }
    }  
    bool skini(double *broj){
        if(write == read) return false; 
        else{
            *broj = red[read++];
            return true;
        }
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
