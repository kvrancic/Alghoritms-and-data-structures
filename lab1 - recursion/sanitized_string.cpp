#include <iostream>
using namespace std; 

class SanitizedString{
    private: 
        string str; 
    
    public: 
        SanitizedString(string ulaz){
            str = ulaz; 
        }

        void removeDuplicateWhitespace();
        void removeNonAlphaChars();
        friend ostream &operator<<(ostream &out, const SanitizedString &string);
};

void SanitizedString::removeDuplicateWhitespace(){
    for(int i = 0; str[i] != '\0'; i++){
        while(str[i - 1] == ' ' && str[i] == ' ')
            {
                int j;
                for(j = i; str[j] != '\0'; j++)
                {
                    str[j] = str[j + 1];
                }
            }

    }
}

void SanitizedString::removeNonAlphaChars()
{
    for(int i = 0; str[i] != '\0'; i++){
        while(!(isalpha(str[i]) || str[i] == ' '))
            {
                int j;
                for(j = i; str[j] != '\0'; j++)
                {
                    str[j] = str[j + 1];
                }
            }
    }
}

ostream &operator<<(ostream &out, const SanitizedString &string){
    out << string.str;
    return out; 
}

int main(void){
    string ulaz; 

    cout << "Upisi string ";
    getline(cin, ulaz);

    SanitizedString string = SanitizedString(ulaz);
    string.removeDuplicateWhitespace();
    string.removeNonAlphaChars();
    cout << string; 
}
