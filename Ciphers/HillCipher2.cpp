#include <bits/stdc++.h>

using namespace std;


void printMatrix(vector<vector<int>> &matrix){

    for(int row=0;row<matrix.size();row++){
        cout<<"+---+---+---+"<<endl;
        cout<<"| ";
        for(int col=0;col<matrix[row].size();col++){
            cout<<matrix[row][col]<<" | ";
        }
        cout<<endl;
    }
}


string getCipher(vector<vector<int>> &keyMat,vector<int> &plainMat){

    string result="";

    for(int row=0;row<3;row++){
        int total=0;
        for(int col=0;col<3;col++){
            if(plainMat[col]!=32){
                total+=(keyMat[row][col]*plainMat[col]);
            }
        }
        result+=((total%26)+97);
    }
    return result;




}



vector<vector<int>> AdjMat(vector<vector<int>> &keyMat){

    vector<vector<int>> matrix=keyMat;

    for(int row=0;row<keyMat.size();row++){
        for(int col=0;col<keyMat.size()-1;col++){
            matrix[row].push_back(matrix[row][col]);
        }
    }

    for(int row=0;row<matrix.size()-1;row++){
        matrix.push_back(matrix[row]);
    }

    vector<vector<int>> result(3,vector<int>(3,0));

    for(int row=1;row<=3;row++){
        for(int col=1;col<=3;col++){
            result[row-1][col-1]=matrix[row][col]*matrix[row+1][col+1]-matrix[row][col+1]*matrix[row+1][col];
        }
    }

    return result;






}




void getPlainMatrices(string plainText,vector<vector<int>> &collector){
    int ptr=0;
    while(ptr<plainText.length()){
        vector<int> temp(3,0);
        for(int col=0;col<3 && ptr<plainText.length();col++){
                temp[col]=plainText[ptr++]-97;
        }
        collector.push_back(temp);
    }




}


int detA(vector<vector<int>> &matrix){

    int det=(matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]))-
            (matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]))+
            (matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]));

        return det;

}


// Recursive function to perform the Extended Euclidean Algorithm using quotients and remainders
int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int quotient, remainder;
    int x1, y1;

    // Recursive call
    int gcd = extendedGCD(b % a, a, x1, y1);

    // Update quotient and remainder
    quotient = b / a;
    remainder = b % a;

    // Update x and y using results from recursion
    x = y1 - quotient * x1;
    y = x1;

    return gcd;
}

// Function to find the modular inverse of 'a' under modulo 'm'
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        std::cerr << "Inverse doesn't exist";  // a and m must be coprime
        return -1;
    } else {
        // Make sure the result is positive
        return (x % m + m) % m;
    }
}




void getKeyMat(string key,vector<vector<int>> &matrix){
    int ptr=0;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            matrix[row][col]=key[ptr++]-97;
        }
    }




}



vector<vector<int>> AInverse(vector<vector<int>> keyMat){

        

    vector<vector<int>> keyMat_Temp=keyMat;
    int det=detA(keyMat);
    int mod_val=modInverse(1,det);
    if(mod_val==-1){
        cout<<"cannot able to decrypt"<<endl;
        exit;
    }
   vector<vector<int>> Adj_Mat=AdjMat(keyMat_Temp);

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            Adj_Mat[row][col]=(mod_val*Adj_Mat[row][col])%26;
        }
    }
    cout<<"AInverse matrix"<<endl;
    printMatrix(Adj_Mat);
    return Adj_Mat;


    

}



string getDecrypt(vector<vector<int>> &keyMatIn,vector<int> cipherMat){

    string res="";

    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum+=keyMatIn[row][col]*cipherMat[col];
        }
        res+=(sum%26)+97;
    }

    return res;


}


void HillCipher(string key,string plainText){

    if(key.length()!=9){
        cout<<"put proper key"<<endl;
        return;
    }   
    vector<vector<int>> keyMat(3,vector<int>(3,0));
    getKeyMat(key,keyMat);

    vector<vector<int>> plainMats;
    getPlainMatrices(plainText,plainMats);

    string res="";

    for(int row=0;row<plainMats.size();row++){
        res+=(getCipher(keyMat,plainMats[row]));
    }

    cout<<"Encrpted String is: "<<res<<endl;
    string cipher=res;

    vector<vector<int>> cipherMats;
    getPlainMatrices(cipher,cipherMats);
    printMatrix(cipherMats);
    vector<vector<int>> keyMatIn(3,vector<int>(3,0));
    vector<vector<int>> keyMatIn1= AInverse(keyMatIn);
    printMatrix(keyMatIn1);


    string dec="7";
    for(int row=0;row<cipherMats.size();row++){
        dec+=(getDecrypt(keyMatIn1,cipherMats[row]));
    }


    cout<<"decrypted message: "<<dec<<endl;






   


 


}




int main(){

    HillCipher("gybnqkurp","act");

}