#include<iostream> 
using namespace std; 

class Vozilo{
    string model; 
    int year; 

    public: 
    Vozilo(){};
    Vozilo(string model, int year) : model(model), year(year) {}
    string getModel(){return model;}
    int getYear(){return year;}
    
    bool operator < (const Vozilo &other){
        if (model < other.model) return true;
        else if (model > other.model) return false;
        else {
            if (year > other.year) return true;
            else return false;
        }
    }
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi){
    Vozilo temp = prvi;
    prvi = drugi; 
    drugi = temp; 
}

template <class T> void SelectionSort(T A[], int N){
    for(int i = 0; i < N; i++){
        T min = A[i];
        int ind_min = i; 
        for(int j = i + 1; j < N; j++){
            if(A[j] < min) {
                ind_min = j;
                min = A[j];
            }  
        }
        Zamijeni(A[i], A[ind_min]);
    }

}

int main(){
    Vozilo *A = new Vozilo[6];
    for(int i = 0; i < 6; i++){
        cout << "Model: "; 
        string model; 
        cin >> model; 
        cout << "Godina: ";
        int godiste; 
        cin >> godiste; 
        A[i] = Vozilo(model, godiste);
    }

    SelectionSort(A, 6);

    for(int i = 0; i < 6; i++){
        cout << A[i].getModel() << " " << A[i].getYear() << endl;
    }

    return 0;
}