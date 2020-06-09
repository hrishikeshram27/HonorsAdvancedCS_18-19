#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

ifstream myFile("D://QuadFile.txt");

void input(string quad, int &a1, int &b1, int &c1){
    cout<<"Equation: "<<quad<<endl;

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
}


void simpOutRad(int &numerator1, int &numerator2, int &denominator, int a1, int b1, int c1, int &outrad){
    numerator1 = (b1*-1);
    numerator2 = outrad;
    denominator = (a1*2);

    int order[3] = {numerator1,numerator2,denominator};
    for(int i=0;i<3;i++){
        if(order[i]<0){
            order[i] = order[i]*(-1);
        }
    }

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

    int counter = order[0];
    if(counter==0){
        counter = order[1];
    }
    while(counter>=2){
        if((order[0]%counter)==0 && (order[1]%counter==0) && (order[2]%counter)==0){
            numerator1 /= counter;
            numerator2 /= counter;
            denominator /= counter;
            counter=1;
        }else{
            counter--;
        }
    }
}

void simpInRad(int a1, int b1, int c1, int &outRad, int &inRad){
    int discriminant = (b1*b1)-(4*a1*c1);
    outRad = 1;
    inRad = discriminant;

    cout<<"Solutions: ";

    if(discriminant>1){
        int largestRad = int(sqrt(discriminant));

        int counter = largestRad;
        while(counter>1){
            if(inRad%(counter*counter)==0){
                inRad /= (counter*counter);
                outRad *= counter;
            }else if(inRad%(counter*counter)!=0){
                counter--;
            }
        }
        int numerator,numerator2,denominator;
        simpOutRad(numerator,numerator2,denominator,a1,b1,c1,outRad);

        if(numerator2!=1){
            if(inRad!=1){
                cout<<"("<<numerator<<"+"<<numerator2<<"{"<<inRad<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<numerator2<<"{"<<inRad<<")/"<<denominator;
            }else if(inRad==1){
                cout<<"("<<numerator<<"+"<<numerator2<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<numerator2<<")/"<<denominator;
            }
        }else if(numerator2==1){
            if(inRad!=1){
                cout<<"("<<numerator<<"+"<<"{"<<inRad<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<"{"<<inRad<<")/"<<denominator;
            }else if(inRad==1){
                cout<<"("<<numerator<<"+"<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<")/"<<denominator;
            }
        }
    }else if(discriminant == 0 || discriminant == 1){
        outRad = 1;
        inRad = discriminant;
        cout<<"("<<(b1*-1)<<"+"<<inRad<<")/"<<(2*a1)<<"     "<<"("<<(b1*-1)<<"-"<<inRad<<")/"<<(2*a1);
    }else if(discriminant<0){
        int largestRad = int(sqrt(discriminant*-1));

        int counter = largestRad;
        while(counter>1){
            if(inRad%(counter*counter)==0){
                inRad /= (counter*counter);
                outRad *= counter;
            }else if(inRad%(counter*counter)!=0){
                counter--;
            }
        }
        int numerator,numerator2,denominator;
        simpOutRad(numerator,numerator2,denominator,a1,b1,c1,outRad);


        if(numerator2!=1){
            if((inRad*-1)!=1){
                cout<<"("<<numerator<<"+"<<numerator2<<"i{"<<-1*inRad<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<numerator2<<"i{"<<-1*inRad<<")/"<<denominator;
            }else if((inRad*-1)==1){
                cout<<"("<<numerator<<"+"<<numerator2<<"i)/"<<denominator<<"     "<<"("<<numerator<<"-"<<numerator2<<"i)/"<<denominator;
            }
        }else if(numerator2==1){
            if((inRad*-1)!=1){
                cout<<"("<<numerator<<"+"<<"i{"<<-1*inRad<<")/"<<denominator<<"     "<<"("<<numerator<<"-"<<"i{"<<-1*inRad<<")/"<<denominator;
            }else if((inRad*-1)==1){
                cout<<"("<<numerator<<"+"<<"i)/"<<denominator<<"     "<<"("<<numerator<<"-"<<"i{)/"<<denominator;
            }
        }
    }
}

//main function
int main(){
    string quad;
    if(myFile.is_open()){
        myFile >> quad;
    }
    myFile.close();
    int a,b,c,x,y;
    input(quad,a,b,c);
    simpInRad(a,b,c,x,y);

    return 0;
}
