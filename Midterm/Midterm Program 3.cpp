#include <iostream>
#include <String>

using namespace std;

class BinaryNum{
    private:			//you may not change anything with the prototype
            string stringVal;
    public:
        BinaryNum();
        string getBin(){
            return(stringVal);}
        void setBin(string str){
            stringVal = str;}
        string operator -();
        void operator >(int);
        string operator * (BinaryNum);

};

BinaryNum::BinaryNum(){			//do not change the constructor
    stringVal ="10001";
    }

void BinaryNum::operator> (int shift){		//take note of the cout  stringVal is the original
						//string. shift is the integer value, and newstr is
						//the shifted string. You must create a new string for
						//this operator. Do not augment the cout line of code.
						//This will be the last line of your operator method
    string remain = stringVal.substr(0,stringVal.length()-shift);
    string newstr;
    for(int i=0;i<shift;i++){newstr+="0";}
    newstr+=remain;
    cout<<"The Right Shift of "<< stringVal<<" by "<<shift<<" is:"<<newstr<<endl;
}

string BinaryNum::operator -(){			//newstr is the name of the variable passed back to main
						// that will hold the 'negated' string
    string newstr;
    for(int i=0;i<stringVal.length();i++){
        if(stringVal[i]=='0'){
            newstr+="1";
        }else if(stringVal[i]=='1'){
            newstr+="0";
        }
    }
    return (newstr);
}


string BinaryNum::operator *(BinaryNum other){	// Take note of the variable names being used.
						// Yes these must be used.
						//'other' refers to the 2nd BinaryNum.

						//'orstr' is the string used to hold the value after
						// Or-ing
						// 'andstr is the string used to hold the value after
						// And-ing

						//Definition of true vs false: True = 1    False = 0
						//Definition of Or-ing: Only false if both are false, otherwise 						//    true
						//Definition of And-ing: False, unless both are true
						// final line of code may not be changed.
    string orStr,andStr;
    for(int i=0;i<stringVal.length();i++){
        if(stringVal[i]=='1' || other.getBin()[i]=='1'){
            orStr+="1";
        }else{
            orStr+="0";
        }

        if(stringVal[i]=='1' && other.getBin()[i]=='1'){
            andStr+="1";
        }else{
            andStr+="0";
        }
    }
    return ("OR String: " + orStr + "   AND String: " + andStr);
}


int main(){
	// Below is the main program to be run. You may NOT change it unless specifically noted
        // The only major change allowed - you may comment out any line of code in the main() that
      	// is not working.

    BinaryNum firstBin, secondBin;
    string input1, input2;
    cout<<"Input 1st number ";
    cin>>input1;
    cout<<"input 2nd number ";
    cin>>input2;
    firstBin.setBin(input1);

     	// in one line display the values of firstBin and secondBin. Please denote which is which.
	// And yes, this is where I want it.
    cout<<"firstBin: "<<firstBin.getBin()<<endl;
    cout<<"secondBin: "<<secondBin.getBin()<<endl;

    secondBin.setBin(input2);




    cout<<endl<<endl<<"The negation of "<<firstBin.getBin()<<" is: "<<-firstBin<<endl;


    //Missing line of code.  set firstBin to its negated value
    firstBin.setBin(-firstBin);


    int shiftvalue;
    cout<<"Input the shift right value";
    cin>>shiftvalue;
    secondBin>(shiftvalue);



    cout<<endl<<endl;
    cout<<"The first input (new) is: "<<firstBin.getBin()<<endl;
    cout<<"The second number is: "<<secondBin.getBin()<<endl;
    cout<<endl<<"The OR-ing and AND-ing of the inputs are: "<<endl<<firstBin * secondBin;
    return 0;
    }
