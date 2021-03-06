#include "myheader.h"
using namespace std;

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
    public:
        Piece();
        Piece(int,int,char,int); //need to add distance traveled later
        int getx();
        int gety();
        int getorigx();
        int getorigy();
        int getOutX();
        int getOutY();
        char getc();
        string getPName();
        //need to add get distance traveled later
        void setx(int);
        void sety(int);
        //need to add set distance traveled later
        void piecedisplay();
};

class Board{
    private:
        Piece players[8];
    public:
        Board();
        int roll();
        void moveGoal(int,int,int);
        void moveNormal(int,int,int);
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

char Piece::getc(){
    return color;
}

string Piece::getPName(){
    return piecenumber;
}

void Piece::setx(int x){
    xpos = x;
}

void Piece::sety(int y){
    ypos = y;
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
    players[0] = R1;
    players[1] = R2;
    players[2] = B1;
    players[3] = B2;
    players[4] = G1;
    players[5] = G2;
    players[6] = Y1;
    players[7] = Y2;
}

int Board::roll(){
    return (rand()%3 + 1);
}

void Board::moveNormal(int die1,int die2,int playerNum){
    int currentX = players[playerNum].getx();
    int currentY = players[playerNum].gety();
    int sum = die1+die2;
    if(currentY==2){
        if((currentX+(die1+die2))<9){
            players[playerNum].setx(currentX+(die1+die2));
        }else{
            players[playerNum].setx(8);
            sum-=(8-currentX);
            players[playerNum].sety(currentY+sum);
        }
    }else if(currentY==8){
        if((currentX-(die1+die2))>2){
            players[playerNum].setx(currentX-(die1+die2));
        }else{
            players[playerNum].setx(2);
            sum-=(currentX-2);
            players[playerNum].sety(currentY-sum);
        }
    }else{
        if(currentX==8){
            if((currentY+(die1+die2))<9){
                players[playerNum].sety(currentY+(die1+die2));
            }else{
                players[playerNum].sety(8);
                sum-=(8-currentY);
                players[playerNum].setx(currentX-sum);
            }
        }else if(currentX==2){
            if((currentY-(die1+die2))>2){
                players[playerNum].sety(currentY-(die1+die2));
            }else{
                players[playerNum].sety(2);
                sum-=(currentY-2);
                players[playerNum].setx(currentX+sum);
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
    display();
    gotoxy(0,35);
    cout<<"Player Color: Blue"<<endl;
    int die1,die2,choice;
    char pause;
    cout<<"Press any key + Enter to roll the dice: ";
    cin>>pause;
    if(pause){
        die1 = roll();
        die2 = roll();
        cout<<"Dice Roll: "<<die1<<" "<<die2<<endl;
        if(die1==die2){ //doubles rolled
            gotoxy(0,38);
            cout<<"Doubles: Yes"<<endl;
            if(players[2].gety()==1 && players[3].gety()==1){ //both pieces at home
                cout<<"Which piece would you like to move out of home? (1 or 2): ";
                cin>>choice;

                if(choice==1){ //piece 1
                    players[2].setx(players[2].getOutX());
                    players[2].sety(players[2].getOutY());
                }else if(choice==2){ //piece 2
                    players[3].setx(players[3].getOutX());
                    players[3].sety(players[3].getOutY());
                }
            }else if(players[2].gety()==1 || players[3].gety()==1){ //one at home, one not
                if(players[2].gety()==players[2].getorigy()){ //blue 1 at home, blue 2 not
                    cout<<"Would you like to move B1 out of home or move B2 around the board? (1 or 2): ";
                    cin>>choice;

                    if(choice==1){
                        players[2].setx(players[2].getOutX());
                        players[2].sety(players[2].getOutY());
                    }else if(choice==2){
                        moveNormal(die1,die2,3);
                    }
                }else{
                    cout<<"Would you like to move B1 around the board or B2 out of home? (1 or 2): ";
                    cin>>choice;

                    if(choice==1){
                        moveNormal(die1,die2,2);
                    }else if(choice==2){
                        players[3].setx(players[3].getOutX());
                        players[3].sety(players[3].getOutY());
                    }
                }
            }else{ //nothing at home
                gotoxy(0,38);
                cout<<"Which player would you like to move? (1 or 2): ";
                cin>>choice;
                if(choice==1){
                    moveNormal(die1,die2,2);
                }else if(choice==2){
                    moveNormal(die1,die2,3);
                }
            }
            display();
        }
    }
}

int main(){
    srand(time(NULL));
    Board b;
    b.execute();
    gotoxy(0,55);
    return 0;
}
