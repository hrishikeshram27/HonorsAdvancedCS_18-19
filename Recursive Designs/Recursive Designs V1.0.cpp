#include<iostream>
#include<windows.h>
using namespace std;

 //will he take off for return 0 getting in the way? where will he have starting points be? can we do gotoxy(90,90) b4 return 0?

COORD coord = { 0,0 };

void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw(int power){
    if(power>=1){
        for(int i=0;i<power;i++){
            cout<<"-";
            Sleep(50);
        }
        cout<<"$";
        Sleep(50);
        draw(power/2);
    }
}

int main(){
    int x,y,val;
    cout<<"Input starting location x value: ";
    cin>>x;
    cout<<"Input starting location y value: ";
    cin>>y;
    cout<<"Input power of 2: ";
    cin>>val;
    system("CLS");
    gotoxy(x,y);
    cout<<"$";
    Sleep(50);
    draw(val);
    return 0;
}
