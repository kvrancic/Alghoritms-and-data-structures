#include<iostream>
using namespace std; 

class Stog{
    static const int MAX = 100;
    int stog[MAX];
    int vrh = -1; 
    
    public:
    bool add(int element){
        if(vrh >= MAX - 1) return false; 
        else stog[++vrh] = element; 
        return true; 
    } 

    void ispis(){
        for(int i = 0; i < vrh; i++) cout << stog[i] << " ";
    }
};

int main(){
    Stog st; 
    int num; 

    srand(time(0));
    for(int i = 0; i < 101; i++){
        int x = rand();
        st.add(x);
    }
    st.ispis();
    return 0;
}