#include <iostream>
using namespace std; 
#include <string>
#include<vector>
#include<cctype>

bool PalindromeCheck(vector<char> text){
    if(text.size() <= 1)
        return true; 
    if(*text.begin() == *(text.end() - 1)){
        text.erase(text.begin());
        text.erase(text.end() - 1);
        PalindromeCheck(text);
    }
    else
        return false;
}

int main(){
    string text; 
    getline(cin, text);
    vector<char> trimmedText;
    for(auto i : text){
        if(isalpha(i))
            trimmedText.push_back(toupper(i));
    }
    cout << boolalpha << PalindromeCheck(trimmedText);
}