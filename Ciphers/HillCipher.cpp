#include <bits/stdc++.h>

using namespace std;


void printMatrix(vector<vector<int>> &matrix){
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


vector<vector<int>> cofactorMatrix(const vector<vector<int>> &matrix) {
    vector<vector<int>> cofactor(3, vector<int>(3));
    cofactor[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    cofactor[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    cofactor[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];

    cofactor[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    cofactor[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    cofactor[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);

    cofactor[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    cofactor[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
    cofactor[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return cofactor;
}


vector<vector<int>> transpose(vector<vector<int>> &matrix){

        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<row;col++){
                int temp=matrix[row][col];
                matrix[row][col]=matrix[col][row];
                matrix[col][row]=temp;
            }
        }


        return matrix;
}








int detA(vector<vector<int>> &matrix){  
    int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}


vector<vector<int>> AInverse(vector<vector<int>> &matrix,int detA){
    detA=detA%26;
    for(int row=0;row<3;row++){
        for(int col=0;col<2;col++){
            matrix[row].push_back(matrix[row][col]);
        }
    }

    for(int row=0;row<2;row++){
        matrix.push_back(matrix[row]);
    }

    printMatrix(matrix);

    //adj A
    vector<vector<int>> adjMat;
    for(int col=1;col<=3;col++){
        vector<int>temp(3,0);
        for(int row=1;row<=3;row++){
            temp[row-1]=(matrix[row][col]*matrix[row+1][col+1])-(matrix[row][col+1]*matrix[row+1][col]);
            
            
        }
        adjMat.push_back(temp);
    }
    
    transpose(adjMat);
    return adjMat;

    


}



string encryptString(vector<vector<int>> &keyMat,vector<vector<int>> &plainMat){

    vector<vector<int>> result;


for(int mat=0;mat<plainMat.size();mat++){
    vector<int> temp(3,0);
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(plainMat[mat][col]!=32){
                temp[row]+=keyMat[row][col]*plainMat[mat][col];
            }
            temp[row]=temp[row]%26;
        }
    }
    result.push_back(temp);
}




string res="";

for(int row=0;row<result.size();row++){
    for(int col=0;col<3;col++){
        res+=(char)(result[row][col]+97);
    }
}
cout<<"result encrypted: "<<res<<endl;
return res;



}




void getPlainMatrix(string plainText,vector<vector<int>> &plainMat){

        

        for(int ptr=0;ptr<plainText.length();ptr+=3){
            vector<int> temp(3,0);
            int index=ptr;
            for(int i=0;i<3;i++){
                if(index<plainText.length()){
                    temp[i]=plainText[index++]-97;
                }
                else{
                    temp[i]=32;//white space;
                }

                
            }
            plainMat.push_back(temp);
          
        }

       





}



void getKeyMatrix(string key,vector<vector<int>> &keyMat){

    int ptr=0;

    for(int row=0;row<keyMat.size();row++){
        for(int col=0;col<keyMat[row].size();col++){
            keyMat[row][col]=key[ptr++]-97;
        }
    }

  








}



string decryptString(vector<vector<int>> &keyMat,string cipherText){

    int det=detA(keyMat);
    cout<<"detA: "<<det%26<<endl;
    vector<vector<int>> A_in=AInverse(keyMat,det);
    printMatrix(A_in);
    // vector<vector<int>> cipherMat;

    // getPlainMatrix(cipherText,cipherMat);

    // printMatrix(cipherMat);


    

    return "";



}





void HillCipher(string key,string plainText){

        if(key.length()!=9){
            cout<<"Invalid key.."<<endl;
            return;
        }


    vector<vector<int>> keyMat(3,vector<int>(3,0));

    getKeyMatrix(key,keyMat);

    vector<vector<int>> plainMat;

    getPlainMatrix(plainText,plainMat);

    printMatrix(keyMat);
    encryptString(keyMat,plainMat);
  

    
    decryptString(keyMat,"poh");









}



int main(){

// hill cipher for a 3*3 matrix

HillCipher("gybnqkurp","act");






}



