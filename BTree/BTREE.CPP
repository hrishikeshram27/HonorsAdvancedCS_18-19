#include<iostream>
using namespace std;

class BNode{
private:
    char data;
    BNode *left;
    BNode *right;
public:
    BNode(char d, BNode *l, BNode *r){
        data = d;
        left = l;
        right = r;
    }
    char getData(){return data;}
    void setData(char d){data = d;}
    BNode* getLeft(){return left;}
    void setLeft(BNode *l){left = l;}
    BNode* getRight(){return right;}
    void setRight(BNode *r){right = r;}
};

class BTree{
private:
    BNode *root;
public:
    BTree(){
        root = NULL;
    }
    void inserter(char);
    void print(BNode*);
    void menu();
};

void BTree::inserter(char x){
    BNode *temp = root;
    if(temp==NULL){
        temp = new BNode(x,NULL,NULL);
        root = temp;
    }else{
        BNode *holdChar = new BNode(x,NULL,NULL);
        bool inserted = false;
        while(!inserted){
            if(x<=temp->getData()){
                if(temp->getLeft()!=NULL){
                    temp = temp->getLeft();
                }else{
                    temp->setLeft(holdChar);
                    inserted = true;
                }
            }else{
                if(temp->getRight()!=NULL){
                    temp = temp->getRight();
                }else{
                    temp->setRight(holdChar);
                    inserted = true;
                }
            }
        }
    }
}

void BTree::print(BNode *x){
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
    }else{
        if(x->getLeft()!=NULL){
            print(x->getLeft());
        }
        cout<<x->getData();
        if(x->getRight()!=NULL){
            print(x->getRight());
        }
    }
}

void BTree::menu(){
    cout<<"Enter string (either all caps or all lower): "<<endl;
    string input;
    cin>>input;
    for(int i=0;i<input.length();i++){
        inserter(input[i]);
    }
    print(root);
}

int main(){
    BTree bin;
    bin.menu();
    return 0;
}
