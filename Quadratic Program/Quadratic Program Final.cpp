#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

ifstream myFile("S:\\Public\\Potter\\Quad\\Quad5.txt");

void input(string quad, int &a1, int &b1, int &c1){
    cout<<"Equation: ";

    char a = quad[0];
    a1 = int(a)-48;

    char b = quad[4];
    b1 = int(b)-48;
    if(quad[3]=='+'){
        b1 = b1;
    }else if(quad[3]=='-'){
        b1 -= (2*b1);
    }

    char c = quad[7];
    c1 = int(c)-48;
    if(quad[6]=='+'){
        c1 = c1;
    }else if(quad[6]=='-'){
        c1 -= (2*c1);
    }

    char superscript = 253;
    if(a1!=1){
        cout<<a1<<"x"<<superscript;
    }else if(a1==1){
        cout<<"x"<<superscript;
    }
    if(b1!=0){
        if(b1<0){
            if(b1!=(-1)){
                cout<<b1<<"x";
            }else if(b1==(-1)){
                cout<<"-x";
            }
        }else if(b>0){
            if(b1!=1){
                cout<<"+"<<b1<<"x";
            }else if(b1==1){
                cout<<"+x";
            }
        }
    }
    if(c1!=0){
        if(c1<0){
            cout<<c1;
        }else if(c1>0){
            cout<<"+"<<c1;
        }
    }
    cout<<"=0"<<endl;
}

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
            return gcf1;
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
            return gcf1;
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

void output(int a, int b, int c){
    int discrim = (b*b) - (4*a*c);
    int outRad = 1;
    int inRad = discrim;

    char sqroot = 251;

    cout<<"Solution(s): "<<endl;

    int gcf;
    if(discrim==0 && b!=0 && c!=0){
        int num1 = (-1*b);
        int denom1 = (2*a);
        gcf = gcf2input(num1,denom1);
        num1 /= gcf;
        denom1 /= gcf;
        if(denom1!=1){
            cout<<"("<<num1<<")/"<<denom1<<endl;
        }else{
            cout<<"("<<num1<<")"<<endl;
        }
    }else if(b==0 && c!=0){
        int innerRad = (-1)*a*c;
        int outerRad = 1;
        int inValue = innerRad;
        simpInRad(outerRad,innerRad,inValue);
        if(innerRad>0){
            int num1 = outerRad;
            int denom1 = a;
            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;
            if(innerRad==1){
                if(denom1==num1){
                    cout<<"(+1)"<<endl<<"(-1)"<<endl;
                }else if(denom1!=1){
                    cout<<"("<<num1<<")/"<<denom1<<endl;
                    cout<<"(-"<<num1<<")/"<<denom1<<endl;
                }else if(denom1==1){
                    cout<<"("<<num1<<")"<<endl;
                    cout<<"(-"<<num1<<")"<<endl;
                }
            }else if(innerRad!=1){
                if(denom1==num1){
                    cout<<"(+"<<sqroot<<innerRad<<")"<<endl;
                    cout<<"(-"<<sqroot<<innerRad<<")"<<endl;
                }else if(denom1!=1){
                    if(num1!=1){
                        cout<<"(+"<<num1<<sqroot<<innerRad<<")/"<<denom1<<endl;
                        cout<<"(-"<<num1<<sqroot<<innerRad<<")/"<<denom1<<endl;
                    }else if(num1==1){
                        cout<<"(+"<<sqroot<<innerRad<<")/"<<denom1<<endl;
                        cout<<"(-"<<sqroot<<innerRad<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num1!=1){
                        cout<<"(+"<<num1<<sqroot<<innerRad<<")"<<endl;
                        cout<<"(-"<<num1<<sqroot<<innerRad<<")"<<endl;
                    }else if(num1==1){
                        cout<<"(+"<<sqroot<<innerRad<<")"<<endl;
                        cout<<"(-"<<sqroot<<innerRad<<")"<<endl;
                    }
                }
            }
        }else if(innerRad<0){
            int num1 = outerRad;
            int denom1 = a;
            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;
            if(innerRad==(-1)){
                if(denom1==num1){
                    cout<<"(+i)"<<endl<<"(-i)"<<endl;
                }else if(denom1!=1){
                    if(num1!=1){
                        cout<<"("<<num1<<"i)/"<<denom1<<endl;
                        cout<<"(-"<<num1<<"i)/"<<denom1<<endl;
                    }else if(num1==1){
                        cout<<"("<<"i)/"<<denom1<<endl;
                        cout<<"(-"<<"i)/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num1!=1){
                        cout<<"("<<num1<<"i)"<<endl;
                        cout<<"(-"<<num1<<"i)"<<endl;
                    }else if(num1==1){
                        cout<<"("<<"i)"<<endl;
                        cout<<"(-"<<"i)"<<endl;
                    }
                }
            }else if(innerRad!=(-1)){
                if(denom1==num1){
                    cout<<"(+i{"<<innerRad*(-1)<<")"<<endl;
                    cout<<"(-i{"<<innerRad*(-1)<<")"<<endl;
                }else if(denom1!=1){
                    if(num1!=1){
                        cout<<"(+"<<num1<<"i"<<sqroot<<innerRad*(-1)<<")/"<<denom1<<endl;
                        cout<<"(-"<<num1<<"i"<<sqroot<<innerRad*(-1)<<")/"<<denom1<<endl;
                    }else if(num1==1){
                        cout<<"(+"<<"i"<<sqroot<<innerRad*(-1)<<")/"<<denom1<<endl;
                        cout<<"(-"<<"i"<<sqroot<<innerRad*(-1)<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num1!=1){
                        cout<<"(+"<<num1<<"i"<<sqroot<<innerRad*(-1)<<")"<<endl;
                        cout<<"(-"<<num1<<"i"<<sqroot<<innerRad*(-1)<<")"<<endl;
                    }else if(num1==1){
                        cout<<"(+"<<"i"<<sqroot<<innerRad*(-1)<<")"<<endl;
                        cout<<"(-"<<"i"<<sqroot<<innerRad*(-1)<<")"<<endl;
                    }
                }
            }
        }
    }else if(b!=0 && c==0){
        int num1 = (-1*b);
        int denom1 = a;
        gcf = gcf2input(num1,denom1);
        num1 /= gcf;
        denom1 /= gcf;
        cout<<"(0)"<<endl;
        if(denom1!=1){
            cout<<"("<<num1<<")/"<<denom1<<endl;
        }else{
            cout<<"("<<num1<<")"<<endl;
        }
    }else if(b==0 && c==0){
        cout<<"(0)";
    }else if(b!=0 && c!=0){
        simpInRad(outRad,inRad,discrim);

        if(outRad==1 && inRad==1){
            int num1 = ((-1*b)+1);
            int denom1 = (2*a);
            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;

            if(denom1!=1){
                if(num1!=denom1){
                    cout<<"("<<num1<<")/"<<denom1<<endl;
                }else{
                    cout<<"(1)"<<endl;
                }
            }else{
                cout<<"("<<num1<<")"<<endl;
            }

            int num2 = ((-1*b)-1);
            gcf = gcf2input(num2,denom1);
            num2 /= gcf;
            denom1 /= gcf;

            if(denom1!=1){
                if(num2!=denom1){
                    cout<<"("<<num2<<")/"<<denom1<<endl;
                }else{
                    cout<<"(1)"<<endl;
                }
            }else{
                cout<<"("<<num2<<")"<<endl;
            }
        }else if(outRad==1 && inRad!=1){
            if((2*a)!=1){
                if(inRad>0){
                    cout<<"("<<(-1*b)<<"+"<<sqroot<<inRad<<")/"<<(2*a)<<endl;
                }else if(inRad<0){
                    cout<<"("<<(-1*b)<<"+i"<<sqroot<<(-1*inRad)<<")/"<<(2*a)<<endl;
                }
            }else if((2*a)==1){
                if(inRad>0){
                    cout<<"("<<(-1*b)<<"+"<<sqroot<<inRad<<")"<<endl;
                }else if(inRad<0){
                    cout<<"("<<(-1*b)<<"+i"<<sqroot<<(-1*inRad)<<")"<<endl;;
                }
            }

            if((2*a)!=1){
                if(inRad>0){
                    cout<<"("<<(-1*b)<<"-"<<sqroot<<inRad<<")/"<<(2*a)<<endl;
                }else if(inRad<0){
                    cout<<"("<<(-1*b)<<"-i"<<sqroot<<(-1*inRad)<<")/"<<(2*a)<<endl;
                }
            }else if((2*a)==1){
                if(inRad>0){
                    cout<<"("<<(-1*b)<<"-"<<sqroot<<inRad<<")"<<endl;
                }else if(inRad<0){
                    cout<<"("<<(-1*b)<<"-i"<<sqroot<<(-1*inRad)<<")"<<endl;;
                }
            }
        }else if(outRad!=1 && inRad==1){
            int num1 = (b*-1) + outRad;
            int denom1 = (2*a);

            gcf = gcf2input(num1,denom1);
            num1 /= gcf;
            denom1 /= gcf;

            if(denom1!=1){
                if(num1!=denom1){
                    cout<<"("<<num1<<")/"<<denom1<<endl;
                }else{
                    cout<<"(1)"<<endl;
                }
            }else{
                cout<<"("<<num1<<")"<<endl;
            }

            int num2 = (b*-1) - outRad;
            denom1 = (2*a);

            gcf = gcf2input(num2,denom1);
            num2 /= gcf;
            denom1 /= gcf;

            if(denom1!=1){
                if(num2!=denom1){
                    cout<<"("<<num2<<")/"<<denom1<<endl;
                }else{
                    cout<<"(1)"<<endl;
                }
            }else{
                cout<<"("<<num2<<")"<<endl;
            }
        }else if(outRad!=1 && inRad!=1){
            int num1 = (-1*b);
            int num2 = outRad;
            int denom1 = (2*a);

            gcf = gcf3input(num1,num2,denom1);
            num1 /= gcf;
            num2 /= gcf;
            denom1 /= gcf;

            if(inRad>0){
                if(denom1!=1){
                    if(num2!=1){
                        cout<<"("<<num1<<"+"<<num2<<sqroot<<inRad<<")/"<<denom1<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"+"<<sqroot<<inRad<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num2!=1){
                        cout<<"("<<num1<<"+"<<num2<<sqroot<<inRad<<")"<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"+"<<sqroot<<inRad<<")"<<endl;
                    }
                }
            }else if(inRad<0){
                if(denom1!=1){
                    if(num2!=1){
                        cout<<"("<<num1<<"+"<<num2<<"i"<<sqroot<<(-1)*inRad<<")/"<<denom1<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"+"<<"i"<<sqroot<<(-1)*inRad<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num2!=1){
                        cout<<"("<<num1<<"+"<<num2<<"i"<<sqroot<<(-1)*inRad<<")"<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"+"<<"i"<<sqroot<<(-1)*inRad<<")"<<endl;
                    }
                }
            }

            if(inRad>0){
                if(denom1!=1){
                    if(num2!=1){
                        cout<<"("<<num1<<"-"<<num2<<sqroot<<inRad<<")/"<<denom1<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"-"<<sqroot<<inRad<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num2!=1){
                        cout<<"("<<num1<<"-"<<num2<<sqroot<<inRad<<")"<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"-"<<sqroot<<inRad<<")"<<endl;
                    }
                }
            }else if(inRad<0){
                if(denom1!=1){
                    if(num2!=1){
                        cout<<"("<<num1<<"-"<<num2<<"i"<<sqroot<<(-1)*inRad<<")/"<<denom1<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"-"<<"i"<<sqroot<<(-1)*inRad<<")/"<<denom1<<endl;
                    }
                }else if(denom1==1){
                    if(num2!=1){
                        cout<<"("<<num1<<"-"<<num2<<"i"<<sqroot<<(-1)*inRad<<")"<<endl;
                    }else if(num2==1){
                        cout<<"("<<num1<<"-"<<"i"<<sqroot<<(-1)*inRad<<")"<<endl;
                    }
                }
            }
        }
    }
}

int main(){
    string quad;
    if(myFile.is_open()){
        myFile >> quad;
    }else{
        cout<<"Unable to open file. Try again.";
        return 0;
    }
    myFile.close();

    int a,b,c;
    input(quad,a,b,c);
    output(a,b,c);

    return 0;
}
