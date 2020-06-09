//Hrishikesh Ram Period 4A 3/22/2019
#include<iostream>
using namespace std;

class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode(int d, ListNode *n){
        data = d;
        next = n;
    }
    int getData(){return data;}
    void setData(int d){data = d;}
    ListNode* getNext(){return next;}
    void setNext(ListNode *n){next = n;}
};

class List{
private:
    ListNode *first;
public:
    List(){
        first = NULL;
    }
    void inserter(int);
    void deleter();
    void print();
    void menu();
};

void List::inserter(int x){
    ListNode *temp = first;
    if(temp==NULL){ //x is the only thing that can go into the list
        temp = new ListNode(x,NULL);
        first = temp;
    }else{
        ListNode *store = new ListNode(x,NULL);
        while(((temp->getNext())!=NULL) && ((temp->getNext()->getData())<x)){ //find where x should go, make sure it isn't going to NULL though
            temp = temp->getNext();
        }
        if(temp->getData()>x){ //insert in beginning, since x is less than temp;
            store->setNext(temp);
            temp = store;
            first = temp;
        }else{ //insert in middle
            store->setNext(temp->getNext());
            temp->setNext(store);
        }
    }
}

void List::deleter(){
    int num;
    cout<<endl<<"What # would you like to delete? ";
    cin>>num;
    ListNode *temp = first;
    if(temp==NULL){
        cout<<"List is empty."<<endl;
    }else{
        if(temp->getData()==num){
            temp = temp->getNext();
            first = temp;
        }else{
            while(temp->getNext()!=NULL && temp->getNext()->getData()!=num){
                temp = temp->getNext(); //before first occurrence
            }
            if(temp->getNext()==NULL){
                cout<<"Value not in list."<<endl;
            }else{
                temp->setNext(temp->getNext()->getNext());
            }
        }
    }
}

void List::print(){
    ListNode *temp = first;
    if(temp==NULL){
        cout<<"The list is empty."<<endl;
    }else{
        while(temp->getNext()!=NULL){
            cout<<temp->getData()<<", ";
            temp = temp->getNext();
        }
        cout<<temp->getData()<<endl;
    }
}

void List::menu(){
    int option;
    bool ending = false;
    while(!ending){
        cout<<"1: Insert a value. 2: Delete a value. 3: Print the list. 4: Quit."<<endl;
        cin>>option;
        if(option==1){
            int input;
            cout<<endl<<"Input the value to insert: ";
            cin>>input;
            inserter(input);
            cout<<endl<<endl;
        }else if(option==2){
            deleter();
            cout<<endl<<endl;
        }else if(option==3){
            cout<<endl;
            print();
            cout<<endl<<endl;
        }else if(option==4){
            ending = true;
        }
    }
}

int main(){
    List l;
    l.menu();
    return 0;
}
