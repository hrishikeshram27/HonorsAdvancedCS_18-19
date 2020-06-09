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

void draw(int power,int dir,int curX,int curY){
    if(power>=1){
        if(dir==0){ //go right
            gotoxy(curX,curY);
            for(int i=0;i<power;i++){
                cout<<"-";
                Sleep(50);
            }
            cout<<"$";
            Sleep(50);
            curX += power;
            curY--;
            dir++;
        }else if(dir==1){ //go up
            gotoxy(curX,curY-power);
            cout<<"$";
            Sleep(50);
            for(int i=0;i<power;i++){
                gotoxy(curX,(curY-power)+1+i);
                cout<<"-";
                Sleep(50);
            }
            curY -= power;
            curX--;
            dir++;
        }else if(dir==2){ //go left
            gotoxy(curX-power,curY);
            cout<<"$";
            Sleep(50);
            for(int i=0;i<power;i++){
                cout<<"-";
                Sleep(50);
            }
            curX -= power;
            curY++;
            dir++;
        }else if(dir==3){ //go down
            gotoxy(curX,curY);
            for(int i=0;i<power;i++){
                gotoxy(curX,curY+i);
                cout<<"-";
                Sleep(50);
            }
            gotoxy(curX,curY+power);
            cout<<"$";
            Sleep(50);
            curY += power;
            curX++;
            dir = 0;
        }
        draw((power/2),dir,curX,curY);
    }
}

int main(){
    int x,y,val,dir;
    cout<<"Input starting location x value: ";
    cin>>x;
    cout<<"Input starting location y value: ";
    cin>>y;
    cout<<"Input power of 2: ";
    cin>>val;
    cout<<"Input direction (0 = right, 1 = up, 2 = left, 3 = down): ";
    cin>>dir;
    system("CLS");
    gotoxy(x,y);
    cout<<"$";
    Sleep(50);
    if(dir==0){x++;}
    else if(dir==1){y--;}
    else if(dir==2){x--;}
    else if(dir==3){y++;}
    draw(val,dir,x,y);
    gotoxy(50,50);
    return 0;
}
