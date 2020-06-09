#include<iostream>
using namespace std;

class KNode{
private:
    char coord;
    int x;
    int y;
    KNode *left;
    KNode *right;
public:
    KNode(char c, int xC, int yC, KNode *l, KNode *r){
        coord = c;
        x = xC;
        y = yC;
        left = l;
        right = r;
    }
    char getCoord(){return coord;}
    void setCoord(char c){coord = c;}
    int getX(){return x;}
    void setX(int xC){x = xC;}
    int getY(){return y;}
    void setY(int yC){y = yC;}
    KNode* getLeft(){return left;}
    void setLeft(KNode *l){left = l;}
    KNode* getRight(){return right;}
    void setRight(KNode *r){right = r;}
};

class KTree{
private:
    KNode *root;
public:
    KTree(){
        root = NULL;
    }
    void inserter();
    void printA(KNode*);
    void printB(KNode*);
    void printC(KNode*);
    void menu();
};

void KTree::inserter(){
    KNode *temp = root;
    int inputX, inputY;
    cout<<"Enter X Coordinate: ";
    cin>>inputX;
    cout<<"Enter Y Coordinate: ";
    cin>>inputY;
    if(temp==NULL){
        char rootCoord;
        cout<<"What coordinate is root priority? ";
        cin>>rootCoord;
        temp = new KNode(rootCoord,inputX,inputY,NULL,NULL);
        root = temp;
    }else{
        char curCoord = temp->getCoord();
        KNode *hold = new KNode(curCoord,inputX,inputY,NULL,NULL);
        bool inserted = false;
        while(!inserted){
            if(curCoord == 'x' || curCoord == 'X'){
                if(inputX<=temp->getX()){
                    if(temp->getLeft()!=NULL){
                        temp = temp->getLeft();
                        curCoord = temp->getCoord();
                    }else{
                        if(curCoord == 'x' || curCoord == 'X'){
                            hold->setCoord('Y');
                        }else if(curCoord == 'y' || curCoord == 'Y'){
                            hold->setCoord('X');
                        }
                        temp->setLeft(hold);
                        inserted = true;
                    }
                }else{
                    if(temp->getRight()!=NULL){
                        temp = temp->getRight();
                        curCoord = temp->getCoord();
                    }else{
                        if(curCoord == 'x' || curCoord == 'X'){
                            hold->setCoord('Y');
                        }else if(curCoord == 'y' || curCoord == 'Y'){
                            hold->setCoord('X');
                        }
                        temp->setRight(hold);
                        inserted = true;
                    }
                }
            }else if(curCoord == 'y' || curCoord == 'Y'){
                if(inputY<=temp->getY()){
                    if(temp->getLeft()!=NULL){
                        temp = temp->getLeft();
                        curCoord = temp->getCoord();
                    }else{
                        if(curCoord == 'x' || curCoord == 'X'){
                            hold->setCoord('Y');
                        }else if(curCoord == 'y' || curCoord == 'Y'){
                            hold->setCoord('X');
                        }
                        temp->setLeft(hold);
                        inserted = true;
                    }
                }else{
                    if(temp->getRight()!=NULL){
                        temp = temp->getRight();
                        curCoord = temp->getCoord();
                    }else{
                        if(curCoord == 'x' || curCoord == 'X'){
                            hold->setCoord('Y');
                        }else if(curCoord == 'y' || curCoord == 'Y'){
                            hold->setCoord('X');
                        }
                        temp->setRight(hold);
                        inserted = true;
                    }
                }
            }
        }
    }
}

void KTree::printA(KNode *x){
    //option 1
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
    }else{
        if(x->getLeft()!=NULL){
            printA(x->getLeft());
        }
        cout<<"("<<x->getX()<<","<<x->getY()<<")  ";
        if(x->getRight()!=NULL){
            printA(x->getRight());
        }
    }
}

void KTree::printB(KNode *x){
    //option 2
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
    }else{
        if(x->getLeft()!=NULL){
            printB(x->getLeft());
        }
        if(x->getCoord()=='x' || x->getCoord()=='X'){
            cout<<"("<<x->getX()<<","<<x->getY()<<")  ";
        }
        if(x->getRight()!=NULL){
            printB(x->getRight());
        }
    }
}

void KTree::printC(KNode *x){
    //option 3
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
    }else{
        if(x->getLeft()!=NULL){
            printC(x->getLeft());
        }
        if((x->getLeft()==NULL)&&(x->getRight()!=NULL)){
            cout<<"("<<x->getX()<<","<<x->getY()<<")  ";
        }
        if((x->getLeft()!=NULL)&&(x->getRight()==NULL)){
            cout<<"("<<x->getX()<<","<<x->getY()<<")  ";
        }
        if(x->getRight()!=NULL){
            printC(x->getRight());
        }
    }
}

void KTree::menu(){
    int choice;
    cout<<"1) Insert a new coordinate    2) Print the tree    3) Exit"<<endl;
    cin>>choice;
    while(choice!=3){
        if(choice==1){
            inserter();
        }else if(choice==2){
            cout<<"Option A: ";
            printA(root);
            cout<<endl<<endl<<"Option B: ";
            printB(root);
            cout<<endl<<endl<<"Option C: ";
            printC(root);
        }
        cout<<endl<<"1) Insert a new coordinate    2) Print the tree    3) Exit"<<endl;
        cin>>choice;
    }
}

int main(){
    KTree knn;
    knn.menu();
    return 0;
}
