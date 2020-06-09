#include<iostream>
#include<iomanip>
#include <windows.h>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;

//remaining things: LOTS OF TESTING!!!!!!!
//bugs: ex: also red moveGoal might not work

COORD coord = { 0,0 };

void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Piece{
    private:
        int xpos;
        int ypos;
        //need to add distance traveled later
        char color;
        string piecenumber;
        int originalx;
        int originaly;
        int goalx;
        int goaly;
        int outHomeX;
        int outHomeY;
        int distGoal;
        int goalPath;
    public:
        Piece();
        Piece(int,int,char,int); //need to add distance traveled later
        int getx();
        int gety();
        int getorigx();
        int getorigy();
        int getOutX();
        int getOutY();
        int getDist();
        int getPath();
        char getc();
        string getPName();
        void setx(int);
        void sety(int);
        void setDist(int);
        void setPath(int);
        void piecedisplay();
};

class Board{
    private:
        Piece players[8];
    public:
        Board();
        int roll();
        int atHome(Piece);
        int atGoal(Piece);
        void moveGoal(int,int,int);
        void moveNormal(int,int,int);
        void knockBack(int);
        void display();
        void execute();
};

Piece::Piece(){
    xpos=0;
    ypos=0;
    originalx=0;
    originaly=0;
    color=0;
    outHomeX=0;
    outHomeY=0;
    piecenumber="1";
    distGoal=23;
    goalPath = 0;
}

Piece::Piece(int x,int y,char c,int n){
    xpos = x;
    originalx = x;
    ypos = y;
    originaly = y;
    color = c;
    if(c=='B'){
        piecenumber = "B";
        outHomeX = 6;
        outHomeY = 2;
    }else if(c=='G'){
        piecenumber = "G";
        outHomeX = 8;
        outHomeY = 6;
    }else if(c=='Y'){
        piecenumber = "Y";
        outHomeX = 4;
        outHomeY = 8;
    }else if(c=='R'){
        piecenumber = "R";
        outHomeX = 2;
        outHomeY = 4;
    }
    if(n==1){
        piecenumber += "1";
    }else if(n==2){
        piecenumber += "2";
    }
    distGoal = 23;
    goalPath = 0;
}

int Piece::getx(){
    return xpos;
}

int Piece::gety(){
    return ypos;
}

int Piece::getorigx(){
    return originalx;
}

int Piece::getorigy(){
    return originaly;
}

int Piece::getOutX(){
    return outHomeX;
}

int Piece::getOutY(){
    return outHomeY;
}

int Piece::getPath(){
    return goalPath;
}

char Piece::getc(){
    return color;
}

string Piece::getPName(){
    return piecenumber;
}

int Piece::getDist(){
    return distGoal;
}

void Piece::setx(int x){
    xpos = x;
}

void Piece::sety(int y){
    ypos = y;
}

void Piece::setDist(int d){
    distGoal = d;
}

void Piece::setPath(int p){
    goalPath = p;
}

void Piece::piecedisplay(){
    gotoxy(6*(xpos-1)+3,3*(ypos-1)+2);
    cout<<piecenumber;
}

Board::Board(){
    Piece R1(1,3,'R',1);
    Piece R2(1,4,'R',2);
    Piece B1(6,1,'B',1);
    Piece B2(7,1,'B',2);
    Piece G1(9,6,'G',1);
    Piece G2(9,7,'G',2);
    Piece Y1(3,9,'Y',1);
    Piece Y2(4,9,'Y',2);
    players[0] = B1;
    players[1] = B2;
    players[2] = G1;
    players[3] = G2;
    players[4] = Y1;
    players[5] = Y2;
    players[6] = R1;
    players[7] = R2;
}

int Board::roll(){
    return (rand()%3 + 1);
}

int Board::atHome(Piece x){
    if(x.getx()==x.getorigx() && x.gety()==x.getorigy()){
        return 1;
    }else{
        return 0;
    }
}

int Board::atGoal(Piece x){
    if(x.getx()==5 && x.gety()==5){
        return 1;
    }else{
        return 0;
    }
}

void Board::moveGoal(int die1,int die2,int playerNum){
    int currentX = players[playerNum].getx();
    int currentY = players[playerNum].gety();
    int dist,overshoot;
    if(playerNum==0 || playerNum==1){ //Blue
        if(currentY==2){dist=3;}
        if(currentY==3){dist=2;}
        if(currentY==4){dist=1;}
        if((die1+die2)<dist){
            players[playerNum].sety(players[playerNum].gety()+(die1+die2));
        }else{
            overshoot = fabs((dist-(die1+die2)));
            while(overshoot>4){overshoot-=4;}
            if(overshoot==0){players[playerNum].sety(5);}
            else if(overshoot==1){players[playerNum].sety(2);}
            else if(overshoot==2){players[playerNum].sety(3);}
            else if(overshoot==3){players[playerNum].sety(4);}
            else if(overshoot==4){players[playerNum].sety(5);}
        }
    }else if(playerNum==2 || playerNum==3){ //Green
        if(currentX==8){dist=3;}
        if(currentX==7){dist=2;}
        if(currentX==6){dist=1;}
        if((die1+die2)<dist){
            players[playerNum].setx(players[playerNum].getx()-(die1+die2));
        }else{
            overshoot = fabs((dist-(die1+die2)));
            while(overshoot>4){overshoot-=4;}
            if(overshoot==0){players[playerNum].setx(5);}
            else if(overshoot==1){players[playerNum].setx(8);}
            else if(overshoot==2){players[playerNum].setx(7);}
            else if(overshoot==3){players[playerNum].setx(6);}
            else if(overshoot==4){players[playerNum].setx(5);}
        }
    }else if(playerNum==4 || playerNum==5){ //Yellow
        if(currentY==8){dist=3;}
        if(currentY==7){dist=2;}
        if(currentY==6){dist=1;}
        if((die1+die2)<dist){
            players[playerNum].sety(players[playerNum].gety()-(die1+die2));
        }else{
            overshoot = fabs((dist-(die1+die2)));
            while(overshoot>4){overshoot-=4;}
            if(overshoot==0){players[playerNum].sety(5);}
            else if(overshoot==1){players[playerNum].sety(8);}
            else if(overshoot==2){players[playerNum].sety(7);}
            else if(overshoot==3){players[playerNum].sety(6);}
            else if(overshoot==4){players[playerNum].sety(5);}
        }
    }else if(playerNum==6 || playerNum==7){ //Red
        if(currentX==2){dist=3;}
        if(currentX==3){dist=2;}
        if(currentX==4){dist=1;}
        if((die1+die2)<dist){
            players[playerNum].setx(players[playerNum].getx()+(die1+die2));
        }
        overshoot = fabs((dist-(die1+die2)));
        while(overshoot>4){overshoot-=4;}
        if(overshoot==0){players[playerNum].setx(5);}
        else if(overshoot==1){players[playerNum].setx(2);}
        else if(overshoot==2){players[playerNum].setx(3);}
        else if(overshoot==3){players[playerNum].setx(4);}
        else if(overshoot==4){players[playerNum].setx(5);}
    }
}

void Board::moveNormal(int die1,int die2,int playerNum){
    int currentX = players[playerNum].getx();
    int currentY = players[playerNum].gety();
    if((players[playerNum].getDist()-(die1+die2))>=0){
        if(currentY==2){ //top row
            if((currentX+(die1+die2))<9){
                players[playerNum].setx(currentX+(die1+die2));
            }else{
                players[playerNum].setx(8);
                players[playerNum].sety(currentY+((die1+die2)-(8-currentX)));
            }
        }else if(currentY==8){ //bottom row
            if((currentX-(die1+die2))>2){
                players[playerNum].setx(currentX-(die1+die2));
            }else{
                players[playerNum].setx(2);
                players[playerNum].sety(currentY-((die1+die2)-(currentX-2)));
            }
        }else{
            if(currentX==8){ //right column
                if((currentY+(die1+die2))<9){
                    players[playerNum].sety(currentY+(die1+die2));
                }else{
                    players[playerNum].sety(8);
                    players[playerNum].setx(currentX-((die1+die2)-(8-currentY)));
                }
            }else if(currentX==2){ //left column
                if((currentY-(die1+die2))>2){
                    players[playerNum].sety(currentY-(die1+die2));
                }else{
                    players[playerNum].sety(2);
                    players[playerNum].setx(currentX+((die1+die2)-(currentY-2)));
                }
            }
        }
        players[playerNum].setDist((players[playerNum].getDist())-(die1+die2));
    }else if((players[playerNum].getDist()-(die1+die2))<0){
        int leftover = fabs(players[playerNum].getDist()-(die1+die2));
        if(players[playerNum].getc()=='B'){
            players[playerNum].setx(5);
            players[playerNum].sety(2);
        }else if(players[playerNum].getc()=='G'){
            players[playerNum].setx(8);
            players[playerNum].sety(5);
        }else if(players[playerNum].getc()=='Y'){
            players[playerNum].setx(5);
            players[playerNum].sety(8);
        }else if(players[playerNum].getc()=='R'){
            players[playerNum].setx(2);
            players[playerNum].sety(5);
        }
        moveGoal(0,leftover,playerNum);
        players[playerNum].setPath(1);
    }

    //chance cards
    if((players[playerNum].getx()==4 && players[playerNum].gety()==2) || (players[playerNum].getx()==8 && players[playerNum].gety()==4) || (players[playerNum].getx()==6 && players[playerNum].gety()==8) || (players[playerNum].getx()==2 && players[playerNum].gety()==6)){
        display();
        gotoxy(0,35);
        char chance;
        cout<<"You landed on a chance square! Would you like to accept the chance condition or not? (y or n): ";
        cin>>chance;
        if(chance=='y'){
            int die3 = roll();
            int die4 = roll();
            cout<<"Chance dice roll sum: "<<(die3+die4)<<endl;
            Sleep(3000);
            if((die3+die4)==5 || (die3+die4)==6){
                //need to move forward 3
                moveNormal(0,3,playerNum);
            }else if((die3+die4)==2){
                players[playerNum].setx(players[playerNum].getorigx());
                players[playerNum].sety(players[playerNum].getorigy());
            }
        }
    } //end of chance cards if statement
}

void Board::knockBack(int playerNum){
    if(atGoal(players[playerNum])!=1){
        if(players[playerNum].getc()=='B'){ //Blue
            for(int i=2;i<8;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
        }else if(players[playerNum].getc()=='G'){ //Green
            for(int i=0;i<2;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
            for(int i=4;i<8;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
        }else if(players[playerNum].getc()=='Y'){
            for(int i=0;i<4;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
            for(int i=6;i<8;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
        }else if(players[playerNum].getc()=='R'){
            for(int i=0;i<6;i++){
                if((players[playerNum].getx()==players[i].getx()) && (players[playerNum].gety()==players[i].gety())){ //another piece at location
                    gotoxy(0,35);
                    cout<<"Player "<<players[i].getPName()<<" has been knocked back home by Player "<<players[playerNum].getPName()<<"."<<endl;
                    Sleep(3000);
                    players[i].setx(players[i].getorigx());
                    players[i].sety(players[i].getorigy());
                    players[i].setDist(23);
                }
            }
        }
    }
}

void Board::display(){
    gotoxy(0,0);
    cout << " ______________________________________________________" << endl;
	for (int i = 1;i <10;i++) {
		cout << "|     |     |     |     |     |     |     |     |     |" << endl;
		cout << "|     |     |     |     |     |     |     |     |     | " << i << endl;
		cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	}
    cout << "   1     2     3     4     5     6     7     8     9";
    for(int i=1;i<6;i++){
        gotoxy(6*(i-1)+3,3*(1-1)+2);
        cout<<"X";
    }
    for(int i=5;i<10;i++){
        gotoxy(6*(1-1)+3,3*(i-1)+2);
        cout<<"X";
    }
    gotoxy(6*(2-1)+3,3*(1-1)+2);
    cout<<"X";
    gotoxy(6*(2-1)+3,3*(9-1)+2);
    cout<<"X";
    gotoxy(6*(8-1)+3,3*(1-1)+2);
    cout<<"X";
    gotoxy(6*(8-1)+3,3*(9-1)+2);
    cout<<"X";
    gotoxy(6*(1-1)+3,3*(2-1)+2);
    cout<<"X";
    gotoxy(6*(9-1)+3,3*(8-1)+2);
    cout<<"X";
    for(int i=5;i<10;i++){
        gotoxy(6*(i-1)+3,3*(9-1)+2);
        cout<<"X";
    }
    for(int i=1;i<6;i++){
        gotoxy(6*(9-1)+3,3*(i-1)+2);
        cout<<"X";
    }
    for(int i=3;i<5;i++){
        for(int j=3;j<5;j++){
            gotoxy(6*(i-1)+3,3*(j-1)+2);
            cout<<"X";
        }
    }
    for(int i=3;i<5;i++){
        for(int j=6;j<8;j++){
            gotoxy(6*(i-1)+3,3*(j-1)+2);
            cout<<"X";
        }
    }
    for(int i=6;i<8;i++){
        for(int j=3;j<5;j++){
            gotoxy(6*(i-1)+3,3*(j-1)+2);
            cout<<"X";
        }
    }
    for(int i=6;i<8;i++){
        for(int j=6;j<8;j++){
            gotoxy(6*(i-1)+3,3*(j-1)+2);
            cout<<"X";
        }
    }
    gotoxy(6*(5-1)+3,3*(5-1)+2);
    cout<<"G";
    for(int i=0;i<8;i++){
        players[i].piecedisplay();
    }
}

void Board::execute(){
    bool game = true;
    int choice,numPlay;
    cout<<"Please enter the number of players (1,2,3,4): ";
    cin>>numPlay;
    while(game){
        for(int i=0;i<numPlay;i++){
            system("CLS");
            display();
            //goes at beginning of game loop, see if game has ended: finish the game loop in that case
            if(atGoal(players[0])==1 && atGoal(players[1])==1){
                gotoxy(0,35);
                cout<<"The game has ended: Blue has won!";
                game = false;
            }else if(atGoal(players[2])==1 && atGoal(players[3])==1){
                gotoxy(0,35);
                cout<<"The game has ended: Green has won!";
                game = false;
            }else if(atGoal(players[4])==1 && atGoal(players[5])==1){
                gotoxy(0,35);
                cout<<"The game has ended: Yellow has won!";
                game = false;
            }else if(atGoal(players[6])==1 && atGoal(players[7])==1){
                gotoxy(0,35);
                cout<<"The game has ended: Red has won!";
                game = false;
            }
            //check if game is still supposed to run
            if(game){
                gotoxy(0,30);
                cout<<"Player color: ";
                if(i==0){
                    cout<<"Blue"<<endl;
                }else if(i==1){
                    cout<<"Green"<<endl;
                }else if(i==2){
                    cout<<"Yellow"<<endl;
                }else{
                    cout<<"Red"<<endl;
                }
                system("PAUSE");
                int die1 = roll();
                int die2 = roll();
                cout<<"Dice roll: "<<die1<<" "<<die2<<endl;
                if(die1==die2){
                    cout<<"Doubles: yes"<<endl;
                    if(atHome(players[2*i])==1 && atHome(players[(2*i)+1])==1){ //both at home
                        cout<<"Which player would you like to move out of home (1 or 2)?"<<endl;
                        cin>>choice;
                        if(choice==1){
                            players[2*i].setx(players[2*i].getOutX());
                            players[2*i].sety(players[2*i].getOutY());
                            knockBack((2*i));
                        }else if(choice==2){
                            players[(2*i)+1].setx(players[(2*i)+1].getOutX());
                            players[(2*i)+1].sety(players[2*i+1].getOutY());
                            knockBack((2*i)+1);
                        }
                    }else if(atHome(players[2*i])==1 && atHome(players[(2*i)+1])!=1){ //1 at home, 2 not
                        if(atGoal(players[(2*i)+1])!=1){
                            cout<<"Would you like to move 1 out of home or 2 around the board? (1 or 2)"<<endl;
                            cin>>choice;
                            if(choice==1){
                                players[2*i].setx(players[2*i].getOutX());
                                players[2*i].sety(players[2*i].getOutY());
                                knockBack((2*i));
                            }else if(choice==2){
                                if(players[(2*i)+1].getPath()==0){
                                    moveNormal(die1,die2,(2*i)+1);
                                }else{
                                    if(atGoal(players[(2*i)+1])!=1){
                                        moveGoal(die1,die2,(2*i)+1);
                                    }
                                }
                                knockBack((2*i)+1);
                            }
                        }else if(atGoal(players[(2*i)+1])==1){
                            cout<<"Must move piece 1 out of home."<<endl;
                            Sleep(3000);
                            players[2*i].setx(players[2*i].getOutX());
                            players[2*i].sety(players[2*i].getOutY());
                            knockBack((2*i));
                        }
                    }else if(atHome(players[2*i])!=1 && atHome(players[(2*i)+1])==1){ //2 at home, 1 not
                        if(atGoal(players[(2*i)])!=1){
                            cout<<"Would you like to move 1 around the board or 2 out of home? (1 or 2)"<<endl;
                            cin>>choice;
                            if(choice==1){
                                if(players[(2*i)].getPath()==0){
                                    moveNormal(die1,die2,(2*i));
                                }else{
                                    if(atGoal(players[(2*i)])!=1){
                                        moveGoal(die1,die2,(2*i));
                                    }
                                }
                                knockBack((2*i));
                            }else if(choice==2){
                                players[(2*i)+1].setx(players[(2*i)+1].getOutX());
                                players[(2*i)+1].sety(players[2*i+1].getOutY());
                                knockBack((2*i)+1);
                            }
                        }else if(atGoal(players[(2*i)])==1){
                            cout<<"Must move piece 2 out of home."<<endl;
                            Sleep(3000);
                            players[(2*i)+1].setx(players[(2*i)+1].getOutX());
                            players[(2*i)+1].sety(players[2*i+1].getOutY());
                            knockBack((2*i)+1);
                        }
                    }else if(atHome(players[2*i])!=1 && atHome(players[(2*i)+1])!=1){ //neither at home
                        if(atGoal(players[(2*i)])!=1 && atGoal(players[(2*i)+1])!=1){ //neither at goal
                            cout<<"Which player would you like to move? (1 or 2)?"<<endl;
                            cin>>choice;
                            if(choice==1){
                                if(players[(2*i)].getPath()==0){
                                    moveNormal(die1,die2,(2*i));
                                }else{
                                    if(atGoal(players[(2*i)])!=1){
                                        moveGoal(die1,die2,(2*i));
                                    }
                                }
                                knockBack((2*i));
                            }else if(choice==2){
                                if(players[(2*i)+1].getPath()==0){
                                    moveNormal(die1,die2,(2*i)+1);
                                }else{
                                    if(atGoal(players[(2*i)+1])!=1){
                                        moveGoal(die1,die2,(2*i)+1);
                                    }
                                }
                                knockBack((2*i)+1);
                            }
                        }else if(atGoal(players[(2*i)])==1 && atGoal(players[(2*i)+1])!=1){ //1 at goal, 2 not
                            cout<<"Must move piece 2."<<endl;
                            Sleep(3000);
                            if(players[(2*i)+1].getPath()==0){
                                moveNormal(die1,die2,(2*i)+1);
                            }else{
                                if(atGoal(players[(2*i)+1])!=1){
                                    moveGoal(die1,die2,(2*i)+1);
                                }
                            }
                            knockBack((2*i)+1);
                        }else if(atGoal(players[(2*i)])!=1 && atGoal(players[(2*i)+1])==1){ //2 at goal, 1 not
                            cout<<"Must move piece 1."<<endl;
                            Sleep(3000);
                            if(players[(2*i)].getPath()==0){
                                moveNormal(die1,die2,(2*i));
                            }else{
                                if(atGoal(players[(2*i)])!=1){
                                    moveGoal(die1,die2,(2*i));
                                }
                            }
                            knockBack((2*i));
                        }
                    }
                }else if(die1!=die2){
                    cout<<"Doubles: no"<<endl;
                    if(atHome(players[2*i])==1 && atHome(players[(2*i)+1])==1){ //both at home
                        cout<<"Cannot move any player out of home. Try again next time."<<endl;
                        Sleep(3000);
                    }else if(atHome(players[2*i])==1 && atHome(players[(2*i)+1])!=1){ //1 at home, 2 not
                        if(atGoal(players[(2*i)+1])!=1){
                            cout<<"Must move piece 2."<<endl;
                            Sleep(3000);
                            if(players[(2*i)+1].getPath()==0){
                                moveNormal(die1,die2,(2*i)+1);
                            }else{
                                if(atGoal(players[(2*i)+1])!=1){
                                    moveGoal(die1,die2,(2*i)+1);
                                }
                            }
                            knockBack((2*i)+1);
                        }else if(atGoal(players[(2*i)+1])==1){
                            cout<<"Cannot move piece 1 out of home. Try again next time."<<endl;
                            Sleep(3000);
                        }
                    }else if(atHome(players[2*i])!=1 && atHome(players[(2*i)+1])==1){ //2 at home, 1 not
                        if(atGoal(players[(2*i)])!=1){
                            cout<<"Must move piece 1."<<endl;
                            Sleep(3000);
                            if(players[(2*i)].getPath()==0){
                                moveNormal(die1,die2,(2*i));
                            }else{
                                if(atGoal(players[(2*i)])!=1){
                                    moveGoal(die1,die2,(2*i));
                                }
                            }
                            knockBack((2*i));
                        }else if(atGoal(players[(2*i)])==1){
                            cout<<"Cannot move piece 2 out of home. Try again next time."<<endl;
                            Sleep(3000);
                        }
                    }else if(atHome(players[2*i])!=1 && atHome(players[(2*i)+1])!=1){ //neither at home
                        if(atGoal(players[(2*i)])!=1 && atGoal(players[(2*i)+1])!=1){ //neither at goal
                            cout<<"Which player would you like to move? (1 or 2)?"<<endl;
                            cin>>choice;
                            if(choice==1){
                                if(players[(2*i)].getPath()==0){
                                    moveNormal(die1,die2,(2*i));
                                }else{
                                    if(atGoal(players[(2*i)])!=1){
                                        moveGoal(die1,die2,(2*i));
                                    }
                                }
                                knockBack((2*i));
                            }else if(choice==2){
                                if(players[(2*i)+1].getPath()==0){
                                    moveNormal(die1,die2,(2*i)+1);
                                }else{
                                    if(atGoal(players[(2*i)+1])!=1){
                                        moveGoal(die1,die2,(2*i)+1);
                                    }
                                }
                                knockBack((2*i)+1);
                            }
                        }else if(atGoal(players[(2*i)])==1 && atGoal(players[(2*i)+1])!=1){ //1 at goal, 2 not
                            cout<<"Must move piece 2."<<endl;
                            Sleep(3000);
                            if(players[(2*i)+1].getPath()==0){
                                moveNormal(die1,die2,(2*i)+1);
                            }else{
                                if(atGoal(players[(2*i)+1])!=1){
                                    moveGoal(die1,die2,(2*i)+1);
                                }
                            }
                            knockBack((2*i)+1);
                        }else if(atGoal(players[(2*i)])!=1 && atGoal(players[(2*i)+1])==1){ //2 at goal, 1 not
                            cout<<"Must move piece 1."<<endl;
                            Sleep(3000);
                            if(players[(2*i)].getPath()==0){
                                moveNormal(die1,die2,(2*i));
                            }else{
                                if(atGoal(players[(2*i)])!=1){
                                    moveGoal(die1,die2,(2*i));
                                }
                            }
                            knockBack((2*i));
                        }
                    }
                } //end of doubles or not statements
            }//if game statement ends here
        }//for loop for turns ends here
    }//end of game loop
}

int main(){
    srand(time(NULL));
    Board b;
    b.execute();
    gotoxy(0,40);
    return 0;
}

//scenario for moving into goal
/*
//put this below int goalPath = 0; change the coordinates according to Potter
players[0].setx(3);
players[0].sety(2);

//put this inside while game
if(atGoal(players[0])==1){
    game = false;
    cout<<"The player is at goal!";
}
display();
gotoxy(0,30);
int die1,die2;
system("PAUSE");
die1 = roll();
die2 = roll();
cout<<"Dice: "<<die1<<" "<<die2<<endl;
if(goalPath==0){
    players[0].setDist(2);
    moveNormal(die1,die2,0,goalPath);
}else{
    if(atGoal(players[0])!=1){
        moveGoal(die1,die2,0);
    }
}
*/
