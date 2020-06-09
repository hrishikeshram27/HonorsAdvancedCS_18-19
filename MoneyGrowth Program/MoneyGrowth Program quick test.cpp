#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
using namespace std;

void input(double &princ,double &rate,double &goal,int &compound){
    cout<<"P = ";
    cin>>princ;
    cout<<"r = ";
    cin>>rate;
    rate/=100;
    cout<<"n = ";
    cin>>compound;
    cout<<"Goal = ";
    cin>>goal;
}

double calc(double princ,double rate,int compound,int time){
    double parantheses = (rate/compound)+1;
    double exponent = compound*time;
    double a = pow(parantheses,exponent);
    double money = a*princ;
    return money;
}

void output(double princ,double rate,double goal,int compound){
    int yearcount = 0;
    cout<<"Year"<<"\t"<<"Amount"<<endl;

    vector <double> amount;

    double money = princ;
    while(yearcount<=10){
        money = calc(princ,rate,compound,yearcount);
        amount.push_back(money);
        yearcount++;
    }

    int counter = 0;
    while(counter<=10){
        cout.setf(ios::fixed|ios::showpoint);
        cout<<counter<<"\t"<<setprecision(2)<<"$"<<amount[counter]<<endl;
        if(amount[counter]-goal<0.001){
            cout<<"Congrats goal met exactly"<<endl;
            counter = 12;
        }else if(amount[counter]>goal){
            cout.setf(ios::fixed|ios::showpoint);
            cout<<"Congrats goal met, and you have $"<<setprecision(2)<<((amount[counter])-goal)<<" left over"<<endl;
            counter = 12;
        }
        counter++;
    }

    if(counter==11){
        cout.setf(ios::fixed|ios::showpoint);
        cout<<"Goal not met, you still need $"<<setprecision(2)<<(goal-(amount[10]))<<endl;
    }
}

int main(){
    double principle,rate,goal;
    int compound;

    input(principle,rate,goal,compound);
    output(principle,rate,goal,compound);

    return 0;
}
