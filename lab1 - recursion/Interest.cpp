#include <iostream>
using namespace std;

/*
Zadana suma novaca oročena je u banci na zadani broj godina n uz 
zadanu godišnju kamatnu stopu p. Napisati program koji računa 
dobivenu sumu nakon isteka oročenja. Odredite T(n).
*/

float interest(float sum, int years, float p){
    if(years == 0)
        return sum;
    else
        return interest((sum * (1 + p / 100)), years--, p); 
}

float kamrac (float g, int n, float p) {
// g – glavnica
// n – trajanje oročenja u godinama
// p – kamatna stopa u postotcima
if (n <= 0) return g;
else return (1 + p / 100) * kamrac(g, n - 1, p);
}

int main(){
    int n;
    float suma, p;
    cout << "Upisite sumu, broj godina i kamatnu stopu ";
    cin >> suma >> n >> p;
    cout << "interest rate is " << interest(suma, n, p) << "or" << kamrac(suma, n, p);
}