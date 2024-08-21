#include <bits/stdc++.h>

using namespace std;


string encrypt(string plainText,int key){
    string enc="";
    for(char letter:plainText){
        int ascii=int(letter);

        if(ascii>=65 && ascii<=90){
            //upper
            enc+=(char)((letter-65+key)%26)+65;
        }
        else{
            //lower
            enc+=(char)((letter-97+key)%26)+97;
        }
    }

    return enc;
}


string decrypt(string cipherText,int key){
    string dec="";
    for(int letter:cipherText){
        int ascii=int(letter);

        if(ascii>=65 && ascii<=90){
            //upper
            dec+=(char)((26+(letter-65-key))%26)+65;
        }
        else{
            dec+=(char)((26+(letter-97-key))%26)+97;
        }

        
    }

    return dec;


}


int main(){
        string plainText;
        int key;
        cout<<"Enter the plain text: ";
        getline(cin,plainText);
        cout<<endl;
        cout<<5/2;
        cout<<"Enter the key: ";
        cin>>key;
        cout<<endl;


       string enc=encrypt(plainText,key);
       cout<<"encrypted: "<<enc<<endl;
       cout<<"decryted: "<<decrypt(enc,key)<<endl;

       return 0;






}