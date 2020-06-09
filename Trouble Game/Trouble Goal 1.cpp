#include "myheader.h"
using namespace std;

void diceRoll(){
    srand(time(NULL)); //is this correct?
    int die1,die2;
    char pause;
    cout<<"Press any key to roll: ";
    cin>>pause;
    while(pause){
        die1 = (rand() % 3) + 1;
        cout<<"Dice 1" <<": "<<die1<<endl;
        die2 = (rand() % 3) + 1;
        cout<<"Dice 2" <<": "<<die2<<endl;
        cout<<"Sum: "<<die1+die2<<endl;
        if(die1 == die2){
            cout<<"These 2 dice have the same value."<<endl;
        }else{
            cout<<"These 2 dice do not have the same value."<<endl;
        }
        cout<<endl<<"Press any key to roll again: ";
        cin>>pause;
    }
}

int main(){
    diceRoll();
    return 0;
}
