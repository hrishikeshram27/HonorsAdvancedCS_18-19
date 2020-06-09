#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const int n = 5;

struct Person{
    string name;
    int nameLen;
    int numvowels;
};

int NumberOfVowels(string x){
    int counter = 0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u'){
            counter++;
        }
    }
    return counter;
}

void input(Person name[]){
    string a;
    int vowel;
    for(int i=0;i<n;i++){
        cout<<"Name #"<<i+1<<": ";
        getline(cin,a);
        name[i].name = a;
        name[i].nameLen = a.length();
        name[i].numvowels = NumberOfVowels(a);
    }
}

void swapName(Person &x,Person &y){
    Person hold = x;
    x = y;
    y = hold;
}

void SortLength(Person x[]){
    Person hold;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i].nameLen>x[j].nameLen){
                swapName(x[i],x[j]);
            }
        }
    }
}

void SortVowels(Person x[]){
    Person hold;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i].numvowels>x[j].numvowels){
                swapName(x[i],x[j]);
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i].numvowels==x[j].numvowels){
                if(x[i].nameLen>x[j].nameLen){
                    SortLength(x);
                    for(int i=0;i<n-1;i++){
                        for(int j=i+1;j<n;j++){
                            if(x[i].numvowels>x[j].numvowels){
                                swapName(x[i],x[j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void OutputDisplay(Person k[]){
    cout.setf(ios::fixed);
    cout<<setw(10)<<left<<"Name"<<"\t"<<"Length"<<"\t"<<"Vowels"<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<setw(10)<<left<<k[i].name<<"\t"<<k[i].nameLen<<"\t"<<k[i].numvowels<<endl;
    }
}

int main(){
    Person length[n];
    input(length);

    //cout<<"Output #1"<<endl;
    //SortLength(length);
    //OutputDisplay(length);

    cout<<"Output #2"<<endl;
    SortVowels(length);
    OutputDisplay(length);

    return 0;
}
