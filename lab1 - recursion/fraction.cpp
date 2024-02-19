#include<iostream> 
#include<cmath>
using namespace std; 

double f (double z, int k); 

int main(){
    float z = 0.5; 
    int k;
    cin >> k;
    while(k != 0)
    {   
        cout << f(z, k) << endl;
        cin >> k;
    }
}

    double f(double z, int k){

        static int predznak = k; 
        if(k <= 0) return z * pow(-1 , predznak);
        return  (pow(z, 2) / ((2*k + 1) * 2*k)) * f(z, k - 1);

    }
