#include<iostream>
#include<string>
using namespace std;

int convertToInt(string x){
    string numerals = "IVXLCDM";
    int numeralVal[7] = {1,5,10,50,100,500,1000};
    int total = 0;
    int tempSubtrct = 0;
    int num[x.length()];
    for(int i=0;i<x.length();i++){
        num[i] = numeralVal[numerals.find(x[i])];
    }
    for(int i=0;i<x.length()-1;i++){
        if(num[i+1]>num[i]){
            tempSubtrct = num[i];
        }else{
            total += (num[i] - tempSubtrct);
            tempSubtrct = 0;
        }
    }
    total += (num[x.length()-1] - tempSubtrct);
    return total;
}

string converToString(int value){
    string romanNum = "";
    string numerals[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int numVals[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int counter = 0;
    while(counter<13){
        for(int i=0;i<value/numVals[counter];i++){
            romanNum += numerals[counter];
        }
        value -= (value/numVals[counter] * numVals[counter]);
        counter++;
    }
    return romanNum;
}

int main(){
    cout<<converToString(4944);
    return 0;
}
