#include <bits/stdc++.h>


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



string decrypt(string cipherText,int key){

        vector<vector<char>> matrix(key,vector<char>(cipherText.length(),' '));

        int row=0;
        bool drop_down=false;

        for(int col=0;col<cipherText.length();col++){

            if(row==0 ||row==key-1){
                drop_down=!drop_down;
            }

            matrix[row][col]='*';
            
            if(drop_down){
                row++;
            }
            else{
                row--;
            }


        }

            int ptr=0;

        for(int row=0;row<key;row++){
            for(int col=0;col<cipherText.length();col++){
                if(matrix[row][col]=='*'){
                    matrix[row][col]=cipherText[ptr++]; 
                }
            }
        }

        bool down=false;
        row=0;
        string dec="";

        for(int col=0;col<matrix[0].size();col++){
            
            if(row==0 ||row==key-1){
                down=!down;
            }
            
            dec+=matrix[row][col];

            if(down){row++;}
            else{row--;}

        }


        cout<<"decrypted string: "<<dec<<endl;



return dec;






}






string railFence(string plainText,int key){

    vector<vector<char>> matrix(key,vector<char>(plainText.length(),'*'));

    bool rail_down=false;
    int row=0;

    for(int col=0;col<plainText.length();col++){

        if(row==0 || row==key-1){
            rail_down=!rail_down;
        }

        matrix[row][col]=plainText[col];

        if(rail_down){
            row++;
        }
        else{
            row--;
        }
        


    }


    printMatrix(matrix);

    string enc="";
    int col=0;

    for(int row=0;row<key;row++){
        for(int col=0;col<plainText.length();col++){
            if(matrix[row][col]!='*'){
                enc+=matrix[row][col];
            }
        }
    }

    cout<<"encrypted string: "<<enc<<endl;
    decrypt(enc,key);

    return enc;

}

int main(){

    railFence("Deadpool and Wolverine",4);


}