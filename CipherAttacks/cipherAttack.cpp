#include <iostream>

using namespace std;


void BruteForce(string cipherText){


    for(int i=0;i<26;i++){
        string enc="";
        for(char letter:cipherText){
            if(isalpha(letter)){
                int base=isupper(letter)?65:97;

                enc+= ((((letter-base)-i)+26)%26)+base;
            }
        }
        cout<<i+1<<")"<<enc<<endl;
    }

    return;
}


int main(){
    string input;
    cout<<"Enter your cipher Text: ";
    getline(cin,input);

    cout<<endl;

    BruteForce(input);

}