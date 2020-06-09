#include<iostream>
#include<vector>
using namespace std;

int main(){
    int input,inputCopy;
    cout<<"Enter a number (2,3,4 digits): ";
    cin>>input;
    inputCopy = input;

    vector <int> digits;

    int digitCount = -1;
    while(inputCopy!=0){ //initial digits
        digits.insert(digits.begin(),(inputCopy%10));
        inputCopy/=10;
        digitCount++;
    }

    int curPos = 0;
    int tempSum;
    while(digits[curPos+digitCount]<input){ //while under value
        tempSum = 0;
        for(int i=curPos;i<=(curPos+digitCount);i++){
            tempSum += digits[i];
        }
        digits.push_back(tempSum);
        curPos++;
    }

    if(tempSum==input){
        cout<<endl<<"It is a Potter Number"<<endl;
        for(int i=0;i<digits.size();i++){
            cout<<digits[i]<<"\t";
        }
    }else{
        cout<<"It is NOT a Potter Number"<<endl<<tempSum;
    }
    return 0;
}
