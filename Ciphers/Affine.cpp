//Affine Cipher

#include <bits/stdc++.h>

using namespace std;



bool isCoprime(int a,int b){


    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }

    if(a==1){
        return true;
    }

    return false;


    


}


string Encrypt(int a,int b,int m,string plainText){

    string enc="";


    for(int i=0;i<plainText.length();i++){
        if(plainText[i]!=' '){
            enc+=((a * (plainText[i]-65)+b)%m)+65;
        }
        else{
            enc+=' ';
        }
    }


    return enc;






}


int modInverse(int a,int m){

    //a*i(mod m)=1
    int modval=-1;
    for(int i=0;i<26;i++){
        if(((a*i)%26)==1){
            modval=i;
            break;
        }
    }


    return modval;

    




}




string Decrypt(string cipher,int a,int b){

    int aIn=modInverse(a,26);
    string dec="";
    for(int i=0;i<cipher.length();i++){

        if(cipher[i]!=' '){
            int x=cipher[i]-65;
            dec+=((aIn*(x-b+26))%26)+65;
        }
        else{
            dec+=' ';
        }
        



    }



    return dec;


}




void Affine(string plainText,int a,int b){

    int m=26;

    //a and 26 should be co prime

    if(!isCoprime(a,m)){
        cout<<"not a co prime"<<endl;
        return;
    }

    string enc=Encrypt(a,b,m,plainText);
    cout<<enc<<endl;


    string dec=Decrypt(enc,a,b);
    cout<<dec<<endl;



}



int  main(){

    Affine("DRAGON",3,20);


}