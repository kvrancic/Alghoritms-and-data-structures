#include <iostream>
#include<string>
using namespace std; 

char *ostaviSlova (string ulaz);

int main(){
    string s; 
    getline(cin, s); 
    cout << ostaviSlova(s);
}

char *ostaviSlova (string ulaz){
    char *letterString = new char[ulaz.size()];
    char *pointer = letterString;
    for(char c : ulaz){
        if(isalpha(c)){
            *pointer = c;
            pointer++;  
        }
    }

    return letterString; 

}