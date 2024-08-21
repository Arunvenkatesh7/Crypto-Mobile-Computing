#include <bits/stdc++.h>


using namespace std;


bool custom(pair<int,char> &a,pair<int,char> &b){
    return a.first>b.first;
}

void frequency(string cipherText,vector<pair<int,char>> &vectorFreq){

    map<char,int> charFreq;

    for(char letter:cipherText){
        charFreq[toupper(letter)]++;
    }


    for(auto &pair:charFreq){
        vectorFreq.push_back({pair.second,pair.first});
    }

    sort(vectorFreq.begin(),vectorFreq.end(),custom);

    for(auto pair:vectorFreq){
        cout<<pair.second<<"-"<<pair.first<<endl;
    }


    






}




void MAlpha(string cipherText){

   vector<pair<int,char>> charFreqSorted;

    frequency(cipherText,charFreqSorted);

    string mostFreq="ETAOINSHRDLCUMWFGYPBVKJXQZ";

    unordered_map<char,char> Mapper;
    int ptr=0;

    for(auto &pair:charFreqSorted){
        Mapper[pair.second]=mostFreq[ptr++];
    }

    string enc="";

    for(char letter:cipherText){

        if(isupper(letter)){
            enc+=Mapper[letter];
        }
        else if(islower(letter)){
            enc+=tolower(Mapper[toupper(letter)]);
        }
        else{
            enc+=letter;
        }

    }


    cout<<"The Encrypted Word is "<<enc<<endl;






}

int main(){
    string input;
    cout<<"Enter the cipher Text: ";
    input="ohLsKzszpSLDsLxszSMLsmErzhDWSzePsWRSWsqPsrLhzsiXWppWLszWhPxkLfhPzrPSzkWekrPfkSRWrLOzhuLhrLXPfLuPzSRyPhkPhLRSWsekWSWsrPppPfrzsihPSLRhfPSrLyhLrPfrrkPxLhpi";
    


    MAlpha(input);


}