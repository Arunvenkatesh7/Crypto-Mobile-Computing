#include <bits/stdc++.h>
#include <fstream>


using namespace std;


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

string AffineDecrypt(string cipher,int a,int b){

    int aIn=modInverse(a,26);
    if(aIn==-1){
        cout<<"not possible"<<endl;
        
    }
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



void frequency(vector<pair<char,int>> &array,string cipherText){
    map<char,int> charFreq;

    for(char letter:cipherText){
        charFreq[toupper(letter)]++;
    }
    
    for(auto pair:charFreq){
        if(pair.second > array[0].second){
            array[1] = array[0]; // Shift the first to second
            array[0] = pair;      // Update the first
        }
        else if(pair.second > array[1].second){
            array[1] = pair; // Update the second
        }
    }

    cout << array[0].first << " and " << array[1].first << endl;
}





void AffineAttack(string cipherText,ofstream &file){

    int a,b;
    file<<"All Affine Possiblies"<<endl;
    string mostFreq="ETAOINSHRDLCUMWFGYPBVKJXQZ";

    //E(x)=ax+b mod 26

    vector<pair<char,int>> array(2,{'a',0});
    
    frequency(array,cipherText);

    vector<int> primes={3,5,7,9,11,15,17,19,21,23,25};

    for(int index=0;index<26;index++){
        char temp=mostFreq[index];
        mostFreq[index]=mostFreq[0];
        mostFreq[0]=temp;
    for(int a:primes){
        file<<"under val a: "<<a;
    int ptr1=0;
    int b1=((array[0].first-65)-a*+(mostFreq[0]-65)+26)%26;
    for(int ptr2=1;ptr2<=mostFreq.length();ptr2++){
        int b2=((array[1].first-65)-a*(mostFreq[ptr2]-65)+26)%26;
        if(b1==b2){
            file<<"and under b: "<<b1<<AffineDecrypt(cipherText,a,b1)<<endl;
        }
    }  
    file<<endl;
    file<<endl;
    }
    }


    





}



int main(){

    string cipherText="DTUMKH";
    ofstream file("affine_res.txt");
    AffineAttack(cipherText,file);
    
}