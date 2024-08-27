#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void printMatrix(vector<vector<char>> &matrix){
    cout<<endl;
    for(int row=0;row<matrix.size();row++){
        cout<<"| ";
        for(int col=0;col<matrix[row].size();col++){
            cout<<matrix[row][col]<<" | ";
        }
        cout<<endl;
        cout<<"--------------"<<endl;
    }


}



void AddPoints(vector<vector<char>> &matrix){

    int row=0;
    int col=0;

    bool down=false;

    while(col<matrix[0].size()){
    
        if(row ==0 || row==matrix.size()-1){
            down=!down;
        }

        matrix[row][col]='*';

        
        if(down){
            row++;
        
        }
        else{
            row--;
            
        }

        col++;





    }


}


string Decrypt(vector<vector<char>> &matrix){

    int row=0;
    bool down=false;
    string dec="s";
   
    for(int col=0;col<matrix[0].size();col++){
        if(row==0 ||row==matrix.size()-1){
            down=!down;
        }

        dec+=matrix[row][col];

        if(down)row++;
        else row--;
    }

    return dec;


}


void railFenceAttack(string cipherText,ofstream &file){

    file<<"Rail Fence Attack"<<endl;
    
    for(int key=2;key<=10;key++){
      
        vector<vector<char>> matrix(key,vector<char>(cipherText.length()));
        AddPoints(matrix);
        
       
        int ptr=0;


        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[row].size();col++){
                if(matrix[row][col]=='*'){
                    matrix[row][col]=cipherText[ptr++];
                }
            }
        }
        


        string plainText=Decrypt(matrix);
      

        file<<"key: "<<key<<"plainText: "<<plainText<<endl;



    }






}


int main(){
    ofstream file("railFence.txt");
    railFenceAttack("Do reoldWeiap novndale",file);

}