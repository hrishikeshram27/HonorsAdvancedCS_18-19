#include<iostream>
using namespace std;
string input;
int curPos = 0;

class ENode{
private:
    char data;
    int value;
    ENode *left;
    ENode *right;
public:
    ENode(char d, ENode *l, ENode *r){
        data = d;
        if(d!='+' && d!='-' && d!='*'){
            value = d - '0';
        }
        left = l;
        right = r;
    }
    char getData(){return data;}
    void setData(char d){data = d;}
    int getValue(){return value;}
    void setValue(int n){value = n;}
    ENode* getLeft(){return left;}
    void setLeft(ENode *l){left = l;}
    ENode* getRight(){return right;}
    void setRight(ENode *r){right = r;}
};

class ETree{
private:
    ENode *root;
public:
    ETree(){
        root = NULL;
    }
    void create(ENode*);
    void evaluate(ENode*);
    void print(ENode*);
    void PrintAnswer();
    void menu();
};

void ETree::create(ENode *current){
    if(root==NULL){
        root = new ENode(input[curPos],NULL,NULL);
        current = root;
    }
    curPos++;
    ENode *newLNode = new ENode(input[curPos],NULL,NULL);
    current->setLeft(newLNode);
    if(input[curPos]=='+' || input[curPos]=='-' || input[curPos]=='*'){
        create(current->getLeft());
    }
    curPos++;
    ENode *newRNode = new ENode(input[curPos],NULL,NULL);
    current->setRight(newRNode);
    if(input[curPos]=='+' || input[curPos]=='-' || input[curPos]=='*'){
        create(current->getRight());
    }
}

void ETree::evaluate(ENode *current){
    if(current->getData()=='+' || current->getData()=='-' || current->getData()=='*'){ //if current is operator
        if(current->getLeft()->getData()=='+' || current->getLeft()->getData()=='-' || current->getLeft()->getData()=='*'){ //if left is operator
            evaluate(current->getLeft());
        }
        if(current->getRight()->getData()=='+' || current->getRight()->getData()=='-' || current->getRight()->getData()=='*'){ //if left is operator
            evaluate(current->getRight());
        }
        if(current->getData()=='+'){
            current->setValue((current->getLeft()->getValue())+(current->getRight()->getValue()));
        }else if(current->getData()=='-'){
            current->setValue((current->getLeft()->getValue())-(current->getRight()->getValue()));
        }else if(current->getData()=='*'){
            current->setValue((current->getLeft()->getValue())*(current->getRight()->getValue()));
        }
    }
}

void ETree::print(ENode *x){
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

void ETree::PrintAnswer(){
    if(root==NULL){
        cout<<endl<<"No Tree = No Answer"<<endl;
    }else{
        evaluate(root);
        cout<<endl<<"The answer is: "<<root->getValue()<<endl;
        cout<<endl<<"Done.";
    }
}

void ETree::menu(){
    cout<<"Enter prefix string: "<<endl;
    cin>>input;
    create(root);
    cout<<endl<<"Infix expression: ";
    print(root);
    cout<<endl;
    PrintAnswer();
}

int main(){
    ETree expr;
    expr.menu();
    return 0;
}
