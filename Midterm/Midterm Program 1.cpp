#include<iostream>
using namespace std;

int gcfCalc(int x1, int x2){
    if(x1<0){
        x1 *= (-1);
    }
    if(x2<0){
        x2 *= (-1);
    }
    int minNum = x1;

    if(x1>=x2){
        minNum=x2;
    }

    int gcf1 = 1;
    int counter = minNum;
    while(counter>1){
        if(x1%counter==0 && x2%counter==0){
            gcf1 = counter;
            return gcf1;
        }
        counter--;
    }

    return gcf1;
}

int main(){
    int num1,denom1,num2,denom2;
    cout<<"Input fraction 1 numerator: ";
    cin>>num1;
    cout<<"Input fraction 1 denominator: ";
    cin>>denom1;

    cout<<"Input fraction 2 numerator: ";
    cin>>num2;
    cout<<"Input fraction 2 denominator: ";
    cin>>denom2;

    int numSum = num1 + num2;
    int gcf = gcfCalc(numSum,denom1);
    numSum /= gcf;
    denom1 /= gcf;
    denom2 /= gcf;

    if(numSum==0){
        cout<<"Answer: 0"<<endl;
    }else if(denom1==1){
        cout<<"Answer: "<<numSum<<endl;
    }
    else if(numSum%denom1==0){
        cout<<"Answer: "<<numSum/denom1<<endl;
    }else{
        cout<<"Answer: "<<numSum<<"/"<<denom1<<endl;
    }

    return 0;
}
