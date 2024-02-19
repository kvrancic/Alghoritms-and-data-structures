#include <iostream> 
using namespace std;

int main(){
    int x, y, rez = 1;
    cout << "Upisite x i y ";
    cin >> x >> y;

    for(int i = 0; i < y; i++)
        rez *= x;

    cout << rez;

    return 0;
}