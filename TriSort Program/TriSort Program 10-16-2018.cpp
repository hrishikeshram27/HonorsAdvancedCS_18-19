#include "E:\\myheader.h"
using namespace std;

const int n = 15;

int main(){
    int intAry[n];
    char charAry[n];
    double doubAry[n];

    srand(time(NULL));

    for(int i=0;i<n;i++){
        intAry[i] = rand() % 30001;
        cout<<intAry[i]<<" ";
    }

    for(int i=0;i<n;i++){
        charAry[i] = rand() % 256;
    }

    for(int i=0;i<n;i++){
        doubAry[i] = double(rand() % 1001);
        doubAry[i] /= double(1000);
    }

    BSort(intAry,n);
    BSort(charAry,n);
    BSort(doubAry,n);

    ofstream myFile("E://TriSortFile.txt");

    for(int i=0;i<n;i++){
        myFile<<intAry[i]<<" ";
        if(i%10==9){
            myFile<<endl;
        }
    }
    myFile<<endl;
    for(int i=0;i<n;i++){
        myFile<<charAry[i]<<" ";
        if(i%10==9){
            myFile<<endl;
        }
    }
    myFile<<endl;
    for(int i=0;i<n;i++){
        myFile<<fixed<<showpoint<<setprecision(3)<<doubAry[i]<<" ";
        if(i%10==9){
            myFile<<endl;
        }
    }
    myFile<<endl;
    myFile.close();
    return 0;
}
