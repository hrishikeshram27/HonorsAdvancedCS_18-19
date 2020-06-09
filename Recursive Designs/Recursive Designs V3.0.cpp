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
                Sleep(1);
            }
            cout<<"$";
            Sleep(1);
            curX += power;
            draw((power/2),0,curX+1,curY);
            draw((power/2),1,curX,curY-1);
            draw((power/2),3,curX,curY+1);
        }else if(dir==1){ //go up
            gotoxy(curX,curY-power);
            cout<<"$";
            Sleep(1);
            for(int i=0;i<power;i++){
                gotoxy(curX,(curY-power)+1+i);
                cout<<"-";
                Sleep(1);
            }
            curY -= power;
            draw((power/2),1,curX,curY-1);
            draw((power/2),0,curX+1,curY);
            draw((power/2),2,curX-1,curY);
        }else if(dir==2){ //go left
            gotoxy(curX-power,curY);
            cout<<"$";
            Sleep(1);
            for(int i=0;i<power;i++){
                cout<<"-";
                Sleep(1);
            }
            curX -= power;
            draw((power/2),1,curX,curY-1);
            draw((power/2),3,curX,curY+1);
            draw((power/2),2,curX-1,curY);
        }else if(dir==3){ //go down
            gotoxy(curX,curY);
            for(int i=0;i<power;i++){
                gotoxy(curX,curY+i);
                cout<<"-";
                Sleep(1);
            }
            gotoxy(curX,curY+power);
            cout<<"$";
            Sleep(1);
            curY += power;
            draw((power/2),3,curX,curY+1);
            draw((power/2),0,curX+1,curY);
            draw((power/2),2,curX-1,curY);
        }
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
    Sleep(1);
    if(dir==0){x++;}
    else if(dir==1){y--;}
    else if(dir==2){x--;}
    else if(dir==3){y++;}
    draw(val,dir,x,y);
    gotoxy(0,0);
    return 0;
}
