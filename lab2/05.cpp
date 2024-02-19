#include<iostream> 
using namespace std; 

class Stog{
    static const int MAX = 10; 
    int stog[MAX]; 
    int vrh = -1; 

    public: 
    bool push(int el){
        if(vrh >= MAX - 1) return false; 
        else{
            stog[++vrh] = el; 
            return true;
        }
    }

    bool pop(int &el){
        if(vrh < 0) return false; 
        else{
            el = stog[vrh--];
            return true; 
        }
    }

    void ispis(){
        for(int i = 0; i < vrh; i++){
            cout << stog[i] << " ";
        }
    }
};

int main(){
    Stog st, pom;
    srand(time(0));
    int num, zamj;

    cout << "stog: ";
    for (int i = 0; i < 10; ++i) {
        num = rand()%10 + 1;
        cout << num << ", ";
        st.push(num);
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        st.pop(zamj);
        pom.push(zamj);
    }

    cout << "ispis: ";
    for (int i = 0; i < 10; ++i) {
        pom.pop(zamj);
        cout << zamj << ", ";
    }


    return 0;
}