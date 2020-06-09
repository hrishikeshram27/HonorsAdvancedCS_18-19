#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
string input;
int curPos = 0;

int fact(int x){
    int result=1;
    if(x!=0 && x!=1){
        for(int i=1;i<=x;i++){
            result*=i;
        }
    }
    return result;
}

class ENode{
private:
    string data;
    double value;
    ENode *left;
    ENode *right;
public:
    ENode(string d, ENode *l, ENode *r){
        data = d;
        if(d!="+" && d!="-" && d!="*" && d!="/" && d!="^" && d!="f"){
            value = atoi(d.c_str());
        }
        left = l;
        right = r;
    }
    string getData(){return data;}
    void setData(string d){data = d;}
    double getValue(){return value;}
    void setValue(double n){value = n;}
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
    bool fact = false;
    if(root==NULL){
        root = new ENode(input.substr(curPos,1),NULL,NULL);
        current = root;
    }
    if(input[curPos]=='f'){
        fact = true;
    }
    curPos++;
    ENode *newLNode;
    if(input[curPos]=='('){
        newLNode = new ENode(input.substr(curPos,4),NULL,NULL);
        newLNode->setValue((input[curPos+2] - '0')*(-1));
        curPos+=3;
    }else{
        newLNode = new ENode(input.substr(curPos,1),NULL,NULL);
    }
    current->setLeft(newLNode);
    if(input[curPos]=='+' || input[curPos]=='-' || input[curPos]=='*' || input[curPos]=='/' || input[curPos]=='^' || input[curPos]=='f'){
        create(current->getLeft());
    }
    curPos++;
    ENode *newRNode;
    if(fact){
        curPos--;
        newRNode = new ENode("0",NULL,NULL);
    }
    else if(input[curPos]=='('){
        newRNode = new ENode(input.substr(curPos,4),NULL,NULL);
        newRNode->setValue((input[curPos+2] - '0')*(-1));
        curPos+=3;
    }else{
        newRNode = new ENode(input.substr(curPos,1),NULL,NULL);
    }
    current->setRight(newRNode);
    if(input[curPos]=='+' || input[curPos]=='-' || input[curPos]=='*' || input[curPos]=='/' || input[curPos]=='^' || input[curPos]=='f'){
        create(current->getRight());
    }
}

void ETree::evaluate(ENode *current){
    if(current->getData()=="+" || current->getData()=="-" || current->getData()=="*" || current->getData()=="/" || current->getData()=="^" || current->getData()=="f"){ //if current is operator
        if(current->getLeft()->getData()=="+" || current->getLeft()->getData()=="-" || current->getLeft()->getData()=="*" || current->getLeft()->getData()=="/" || current->getLeft()->getData()=="^" || current->getLeft()->getData()=="f"){ //if left is operator
            evaluate(current->getLeft());
        }
        if(current->getRight()->getData()=="+" || current->getRight()->getData()=="-" || current->getRight()->getData()=="*" || current->getRight()->getData()=="/" || current->getRight()->getData()=="^" || current->getRight()->getData()=="f"){ //if right is operator
            evaluate(current->getRight());
        }
        if(current->getData()=="+"){
            current->setValue((current->getLeft()->getValue())+(current->getRight()->getValue()));
        }else if(current->getData()=="-"){
            current->setValue((current->getLeft()->getValue())-(current->getRight()->getValue()));
        }else if(current->getData()=="*"){
            current->setValue((current->getLeft()->getValue())*(current->getRight()->getValue()));
        }else if(current->getData()=="/"){
            if(current->getRight()->getValue()!=0){
                current->setValue((current->getLeft()->getValue())/(current->getRight()->getValue()));
            }else{
                current->setValue(pow(10,309));
                cout<<endl<<"You're bad. No dividing by 0."<<endl;
            }
        }else if(current->getData()=="^"){
            current->setValue(pow((current->getLeft()->getValue()),(current->getRight()->getValue())));
        }else if(current->getData()=="f"){
            current->setValue(fact(current->getLeft()->getValue()));
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
    //cout<<endl<<"Infix expression: ";
    //print(root);
    cout<<endl;
    PrintAnswer();
}

int main(){
    for(int i=0;i<7;i++){
        ETree expr;
        expr.menu();
        curPos = 0;
    }
    return 0;
}
