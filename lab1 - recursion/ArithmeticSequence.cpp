#include <iostream> 
using namespace std;

int elementCalculator(int a1, int d, int n){
    if(n == 0){
        return a1;
    }
    else
        return d + elementCalculator(a1, d, n - 1);
}

int main(){
    cout << "Upiši a1, d i n ";
    int first, d, n; 
    cin >> first >> d >> n; 
    
    cout << elementCalculator(first, d, n);

    return 0;
}