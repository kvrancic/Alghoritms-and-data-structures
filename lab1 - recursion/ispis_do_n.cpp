#include <iostream> 
using namespace std;

void print_rec_desc(int n){
    cout << n << endl;
    if(n == 0)
        return;
    else
        print_rec_desc(n - 1);

}

int main()
{
    int n; 
    cout << "Do kojeg broja zelite ispisivati brojeve ";
    cin >> n;
    print_rec_desc(n);
}