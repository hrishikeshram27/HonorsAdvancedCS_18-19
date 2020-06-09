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
    public:
        Piece();
        Piece(int,int,char,int); //need to add distance traveled later
        int getx();
        int gety();
        int getorigx();
        int getorigy();
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
        void display();
        void execute();
};

Piece::Piece(){
    xpos=0;
    ypos=0;
    originalx=0;
    originaly=0;
    color=0;
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
    }else if(c=='G'){
        piecenumber = "G";
    }else if(c=='Y'){
        piecenumber = "Y";
    }else if(c=='R'){
        piecenumber = "R";
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
    players[2].setx(2);
    players[2].sety(2);
    display();
    gotoxy(0,30);
    cout<<"Player Color: Blue"<<endl;
    int die1,die2;
    char pause;
    cout<<"Press any key + Enter to roll the dice: ";
    cin>>pause;
    if(pause){
        die1 = roll();
        die2 = roll();
        players[2].setx(players[2].getx()+(die1+die2));
        display();
        gotoxy(0,32);
        cout<<"Dice Roll: "<<die1<<" "<<die2<<endl;
        cout<<"Sum: "<<die1+die2<<endl;
        if(die1==die2){
            cout<<"Double: Yes"<<endl;
        }else{
            cout<<"Double: No"<<endl;
        }
    }
}

int main(){
    srand(time(NULL));
    Board b;
    b.execute();
    gotoxy(0,40);
    return 0;
}
