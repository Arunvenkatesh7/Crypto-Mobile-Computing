#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void printMatrix(vector<vector<char>> &matrix){


    for(int row=0;row<matrix.size();row++){
        cout<<"+---+---+---+"<<endl;
        cout<<"| ";
        for(int col=0;col<matrix[row].size();col++){
            cout<<matrix[row][col]<<" |";
        }
        cout<<endl;
    }
}









void priority(string key,map<char,vector<int>> &Mapper){

    for(int i=0;i<key.length();i++){
        Mapper[key[i]].push_back(i);
    }

}



string Decrypt(string cipher,string key){

    map<char,vector<int>> Mapper;

    priority(key,Mapper);
     int max_rows=(int)(cipher.length()/key.length())+1;

    vector<vector<char>> matrix(max_rows,vector<char>(key.length(),'_'));

    int ptr=0;

    for(auto &pair:Mapper){
        vector<int> arr=pair.second;

        for(int col:arr){
            for(int row=0;row<max_rows && ptr<cipher.length();row++){
                matrix[row][col]=cipher[ptr++];
            }
        }
    }

    string result="";

    for(int row=0;row<max_rows;row++){
        for(int col=0;col<key.length();col++){
            if(matrix[row][col]!='_')
            result+=matrix[row][col];
        }
    }

    return result;



}






string Encrypt(string plainText,string key){

    map<char,vector<int>> Mapper;
    

    int max_rows=(int)(plainText.length()/key.length()+1);

    vector<vector<char>> matrix(max_rows,vector<char>(key.length(),'_'));
    printMatrix(matrix);
    int ptr=0;

    for(int row=0;row<max_rows;row++){
        for(int col=0;col<key.length() && ptr<plainText.length();col++){
            matrix[row][col]=plainText[ptr++];
        }
    }

    printMatrix(matrix);

    priority(key,Mapper);
    string result="";
    for(auto &pair:Mapper){
        vector<int> arr=pair.second;
        for(int col:arr){
            for(int row=0;row<max_rows;row++){
                if(matrix[row][col]!='_'){
                    result+=matrix[row][col];
                }
            }
        }
    }



    return result;


    




}



void Columnar(string plainText,string key){

    string enc=Encrypt(plainText,key);
   
    string dec=Decrypt(enc,key);
    cout<<"encryption: "<<enc<<endl;
     cout<<"decryption: "<<dec<<endl;


}


int main(){

    Columnar("Geeks for Geeks","HACK");




}