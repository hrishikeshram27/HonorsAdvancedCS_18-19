#include<iostream>
#include<string>
using namespace std;

class Roman{
	public:
		Roman();		// default constructor  rStr = “Blank”, iStr = 0;
		Roman(string);	 	// constructs a Roman Numeral  given a String. Calls
                            // convertToInt() to assign the correct numeric value
		Roman(int);		// constructs a Roman numeral given a String. Calls
						// convertToStr to assign the correct numeric value
		void setStr(string);	// Sets the Roman Numeral String
		string getStr();		// Returns the Roman Numeral
		void setInt(int);		// Sets the Roman Numeral Value
		int getInt();		// Returns the Roman Numeral Value
		void displayProp();	// Displays the String and Integer Values of the Roman Numeral
        void convertToInt(string);	// coverts the string to its integer value
        void convertToStr(int);		// converts the integer to its string value
        int operator^(Roman);	// Compares to see if the two inputs are verified to be
                                // equal. Returns 1 if true, or 0 if false
	private:
		string romanStr;
		int romanInt;
};

Roman::Roman(){
    romanStr = "Blank";
    romanInt = 0;
}

Roman::Roman(string x){
    romanStr = x;
    convertToInt(x);
}

Roman::Roman(int y){
    romanInt = y;
    convertToStr(y);
}

void Roman::setStr(string first){
    romanStr = first;
}

string Roman::getStr(){
    return romanStr;
}

void Roman::setInt(int second){
    romanInt = second;
}

int Roman::getInt(){
    return romanInt;
}

void Roman::displayProp(){
    cout<<romanStr<<endl<<romanInt<<endl;
}
//takes in string. creates an array of which each element is the numerical value associated with each letter in the input string. ex: "MCMIV" --> {1000,100,1000,1,5}
//takes array of values. loops through all but last element. if the next element is greater than this one, then store this value in a variable tempSubtract.
//next iteration, the value cannot be a special case, so it will go into else, and it will add the current value and take away tempSubtract.
//final element of array is added outside for loop because looping through the last element in the loop itself means it will check for element after last one, doesn't exist
//example of algorithm: "MCMIV" --> {1000,100,1000,1,5}
//iteration 1: total = 1000, tempSubtract = 0. iteration 2: total = 1000, tempSubtract = 100. iteration 3: total = 2000 - 100 = 1900, tempSubtract = 0.
//iteration 4: total = 1900, tempSubtract = 1. OUTSIDE LOOP: total = 1905 - 1 = 1904. setInt(1904). DONE.
void Roman::convertToInt(string romanNum){
    string numerals = "IVXLCDM";
    int numeralVal[7] = {1,5,10,50,100,500,1000};
    int add[romanNum.length()];
    for(int i=0;i<romanNum.length();i++){
        add[i] = numeralVal[numerals.find(romanNum[i])];
    }
    int total = 0;
    int tempSubtrct = 0;
    for(int i=0;i<romanNum.length()-1;i++){
        if(add[i+1]>add[i]){
            tempSubtrct = add[i];
        }else{
            total += (add[i] - tempSubtrct);
            tempSubtrct = 0;
        }
    }
    total += (add[romanNum.length()-1] - tempSubtrct);
    setInt(total);
}

//takes in value. creates blank string to later return. has parallel arrays for each numeral and for each corresponding numerical value (incl. special cases).
//while loops through all 13 indexes of the parallel arrays.
//value/numVals[counter] = the digit at that place
//for example, if the number was 3498, and counter = 0, you are checking for 3498/numVals[0] = 3498/1000 = 3 (truncates since its an int value)
//for each place value, add the number of letters that needs to go in the number based on the digit at that place (ex: thousands digit is 3, so add "MMM" to the string)
//once each place value is done, counter++. Also, take away whatever you added to the string from number
//ex: for thousands place, 3498/numVals[0] = 3, so added "MMM", then 1000*(3498/numVals[0]) = 1000*3 = 3000, so take away 3000 from the input value because this has already been added to string in form of letters
//example of algorithm: input 1904. loops through.
//1904/numVals[0] = 1904/1000 = 1 (int value truncates). so add 1 "M", string is now just "M". Also take away 1904/numVals[0] * 1000 from value, so value = 904.
//904/numVals[1] = 904/900 = 1 (int truncates). so add 1 "CM" to string, total string is now "MCM", take away 904/numVals[1] * 900 from value, so value = 4.
//skips through rest, because 4/numVals[whatever] = 0 until the index is 11.
//4/numVals[11] = 4/4 = 1 (actually no need to truncate here, huh!). so add 1 "IV" to string, now string is "MCMIV", take away 4/numVals[11] from value, so value = 0.
//it loops through last element, and value/numVals[whatever] = 0 for the rest of the loop, so its done now.
//setStr("MCMIV"). DONE.
void Roman::convertToStr(int value){
    string romanNum = "";
    string numerals[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int numVals[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int counter = 0;
    while(counter<13){
        for(int i=0;i<value/numVals[counter];i++){
            romanNum += numerals[counter];
        }
        value -= (value/numVals[counter] * numVals[counter]);
        counter++;
    }
    setStr(romanNum);
}

int Roman::operator^(Roman temp){
    if(romanInt==temp.getInt() && romanStr==temp.getStr()){
        return 1;
    }else{
        return 0;
    }
}

void option1(){
    string numeral;
    cout<<"Enter a valid Roman numeral here: ";
    cin>>numeral;

    Roman strRoman(numeral);
    strRoman.displayProp();
}

void option2(){
    int integer;
    cout<<"Enter a valid integer between 1 and 10000 here: ";
    cin>>integer;

    Roman intRoman(integer);
    intRoman.displayProp();
}

void option3(){
    Roman defaultRoman;
    cout<<"Default: "<<endl;
    defaultRoman.displayProp();
    cout<<endl;

    string numeral;
    cout<<"Enter a valid Roman numeral here: ";
    cin>>numeral;
    Roman Roman1(numeral);
    Roman1.displayProp();
    cout<<endl;

    int integer;
    cout<<"Enter a valid integer between 1 and 10000 here: ";
    cin>>integer;
    Roman Roman2(integer);
    Roman2.displayProp();
    cout<<endl;

    cout<<"Are they equal? "<<(Roman1^Roman2)<<endl;
}

int main(){
    int option = 0;
    while(option!=4){
        cout<<"Which option would you like?"<<endl<<endl;
        cout<<"1) Create a String Only Roman Numeral"<<endl;
        cout<<"2) Create an Integer Numeral"<<endl;
        cout<<"3) Create a Default Roman Numeral"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Type 1, 2, 3, or 4 here to choose an option from the menu above: ";
        cin>>option;

        if(option==1){
            option1();
        }else if(option==2){
            option2();
        }else if(option==3){
            option3();
        }
    }

    /*
    //Please comment out - do NOT delete - all of your code for main except the "int main()"
    //Also comment out any  lines of code test that you are not able to do


    Roman enloe;
    cout<<"Test 1: "<<enloe.getStr()<<endl;			//Tests Default

    enloe.setStr("Potter");
    cout<<"Test 2: "<<enloe.getStr()<<endl<<endl<<endl;	// Tests setStr

    Roman high("MCXVI");					// Tests basic Roman given string
    cout<< "Test3:"<<endl;
    high.displayProp();
    cout<<endl<<endl;

    Roman school(2772);					// Tests basic Roman given and integer
    cout<<"Test4: "<<endl;
    school.displayProp();
    cout<<endl<<endl;

    cout<<"Test5:"<<endl;					// Tests getInt and Conversion
    cout<<5 + school.getInt()<<endl;
    int value = 5+school.getInt();
    school.setInt(value);
    school.convertToStr(value);
    school.displayProp();
    cout<<endl<<endl;

    cout<<"Test 6:"<<endl;					// Tests special case given integer
    Roman special1(4944);
    special1.displayProp();
    cout<<endl;

    cout<<"Test 7"<<endl;					// Tests special case given string
    Roman special2("CDXLIX");
    special2.displayProp();

    cout<<endl<<endl<<"Test 8";				// Test Operator overlaod
    Roman op1(6);
    Roman op2("VII");
    Roman op3(7);
    cout<<"Check 1:"<<(op1^op2)<<endl;
    cout<<"Check 2:"<<(op2^op3)<<endl;
    cout<<"Check 3:"<<(op1^op3)<<endl<<"DONE";
    */

    return 0;
}
