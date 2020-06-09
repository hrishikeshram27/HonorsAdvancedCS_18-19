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
    if(power>1){
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
    }else{
        if(dir==0){ //go right
            gotoxy(curX,curY);
            cout<<"-";
            Sleep(50);
            cout<<"$";
            Sleep(50);
        }else if(dir==1){ //go up
            gotoxy(curX,curY);
            cout<<"-";
            Sleep(50);
            gotoxy(curX,curY-1);
            cout<<"$";
            Sleep(50);
        }else if(dir==2){ //go left
            gotoxy(curX-1,curY);
            cout<<"$";
            Sleep(50);
            cout<<"-";
            Sleep(50);
        }else if(dir==3){ //go down
            gotoxy(curX,curY);
            cout<<"-";
            Sleep(50);
            gotoxy(curX,curY+1);
            cout<<"$";
            Sleep(50);
        }
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
