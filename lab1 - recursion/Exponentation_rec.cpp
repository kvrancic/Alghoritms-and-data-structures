#include <iostream>
using namespace std;

int exponentiate(int x, int y){ 
    if(y == 0)
        return 1; 
    else
        return x * exponentiate(x , y - 1);
}

int main(){
    cout << "Upisi x i y: ";
    int x, y;
    cin >> x >> y;
    cout << exponentiate(x, y);

    return 0;
}