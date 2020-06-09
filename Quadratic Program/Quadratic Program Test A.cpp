#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

int gcf2input(int x1, int x2){
    if(x1<0){
        x1 *= (-1);
    }
    if(x2<0){
        x2 *= (-1);
    }
    int minNum = x1;

    if(x1>=x2){
        minNum=x2;
    }

    int gcf1 = 1;
    int counter = minNum;
    while(counter>1){
        if(x1%counter==0 && x2%counter==0){
            gcf1 = counter;
        }
        counter--;
    }

    return gcf1;
}

int gcf3input(int x1, int x2, int x3){
    if(x1<0){
        x1 *= (-1);
    }
    if(x2<0){
        x2 *= (-1);
    }
    if(x3<0){
        x3 *= (-1);
    }

    int order[3] = {x1,x2,x3};
    int hold;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(order[j]<order[j+1]){
                hold = order[j];
                order[j] = order[j+1];
                order[j+1] = hold;
            }
        }
    }
    int minNum = order[0];

    int gcf1 = 1;
    int counter = minNum;
    while(counter>1){
        if(x1%counter==0 && x2%counter==0 && x3%counter==0){
            gcf1 = counter;
        }
        counter--;
    }

    return gcf1;
}

void simpInRad(int &outer, int &inner, int discriminant){
    if(discriminant<0){
        discriminant *= (-1);
    }
    int largest = int(sqrt(discriminant));

    int counter = largest;
    while(counter>1){
        if(inner%(counter*counter)==0){
            inner /= (counter*counter);
            outer *= counter;
        }else{
            counter--;
        }
    }
}

int main(){
    int a = 1;
    int b = 0;
    int c = -9;
    int discrim = (b*b) - (4*a*c);
    int outRad = 1;
    int inRad = discrim;
    int gcf;
    if(b==0 && c!=0){
        int innerRad = (-1)*a*c;
        int outerRad = 1;
        int inValue = innerRad;
        simpInRad(outerRad,innerRad,inValue);
        if(innerRad>0){
            int num1 = outRad;
            int denom1 = a;
            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;
            if(innerRad==1){
                if(denom1==num1){
                    cout<<"(+1)"<<endl<<"(-1)"<<endl;
                }else if(denom1!=1 && denom1!=num1){
                    cout<<"("<<num1<<")/"<<denom1<<endl;
                    cout<<"(-"<<num1<<")/"<<denom1<<endl;
                }else if(denom1==1 && denom1!=num1){
                    cout<<"("<<num1<<")"<<endl;
                    cout<<"(-"<<num1<<")"<<endl;
                }
            }else if(innerRad!=1){
                if(denom1==num1){
                    cout<<"(+{"<<inRad<<")"<<endl;
                    cout<<"(-{"<<inRad<<")"<<endl;
                }else if(denom1!=1 && denom1!=num1){
                    cout<<"(+"<<num1<<"{"<<inRad<<")/"<<denom1<<endl;
                    cout<<"(-"<<num1<<"{"<<inRad<<")/"<<denom1<<endl;
                }else if(denom1==1 && denom1!=num1){
                    cout<<"(+"<<num1<<"{"<<inRad<<")"<<endl;
                    cout<<"(-"<<num1<<"{"<<inRad<<")"<<endl;
                }
            }
        }else if(innerRad<0){
            int num1 = outRad;
            int denom1 = a;
            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;
            if(innerRad==(-1)){
                if(denom1==num1){
                    cout<<"(+i)"<<endl<<"(-i)"<<endl;
                }else if(denom1!=1 && denom1!=num1){
                    cout<<"("<<num1<<"i)/"<<denom1<<endl;
                    cout<<"(-"<<num1<<"i)/"<<denom1<<endl;
                }else if(denom1==1 && denom1!=num1){
                    cout<<"("<<num1<<"i)"<<endl;
                    cout<<"(-"<<num1<<"i)"<<endl;
                }
            }else if(innerRad!=(-1)){
                if(denom1==num1){
                    cout<<"(+i{"<<inRad<<")"<<endl;
                    cout<<"(-i{"<<inRad<<")"<<endl;
                }else if(denom1!=1 && denom1!=num1){
                    cout<<"(+"<<num1<<"i{"<<inRad<<")/"<<denom1<<endl;
                    cout<<"(-"<<num1<<"i{"<<inRad<<")/"<<denom1<<endl;
                }else if(denom1==1 && denom1!=num1){
                    cout<<"(+"<<num1<<"i{"<<inRad<<")"<<endl;
                    cout<<"(-"<<num1<<"i{"<<inRad<<")"<<endl;
                }
            }
        }
    }
}
