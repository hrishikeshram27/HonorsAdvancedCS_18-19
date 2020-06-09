#include<iostream>

using namespace std;

class Time{
	public :       //Accessors - has access
                            // wherever the program has access to an object of class
		Time();
		Time(int, int, int, char);
		void setTime(int, int, int, char);
		void setMin(int);
		int getMin();
		int miltary(int);
		void print();
	private:       //Accessors that are only member to functions in the class
		int hour;
		int min;
		int sec;
		char ampm;
	};

Time::Time(){
	hour = 12;
	min=sec=0;
	ampm = 'a';
	}

Time::Time(int first, int second, int third, char fourth){
	hour=first;
	min=second;
	sec=third;
	ampm=fourth;
}

void Time::setTime( int h, int m, int s, char a){
	hour=h;
	min=m;
	sec=s;
	ampm=a;
	}

void Time::setMin(int stuff){
	min= stuff;
	}

int Time::getMin(){
	return min;}


int Time::miltary(int hour){
	return hour+12;
	}

void Time::print(){
	cout<<"The time in military time is ->";
	if (ampm=='p'){
		hour = miltary(hour);}
	cout<<hour<<":"<<min<<":"<<sec;
	}

int main(){
	Time d; //create a new time class variable 'd' set by default constructor, 12:0:0 AM
	d.print(); //print time d
	cout<<endl;

	Time hello(5,34,20,'p'); //create new time class variable "hello" set by particular/non-default constructor, 5:34:20 AM or 17:34:20(PM)
	hello.print(); //print time hello
	cout<<endl;

	int mike,don,leo; //teenage mutant ninja turtles: "mutators"
	char ralph;
	cout<<"Enter hour: ";
	cin>>mike;
	cout<<"Enter minute: ";
	cin>>don;
	cout<<"Enter second: ";
	cin>>leo;
	cout<<"Enter ampm: ";
	cin>>ralph;

	d.setTime(mike,don,leo,ralph); //changes/mutates time d from default 12:0:0 AM to whatever the 4 values are
	d.print(); //print time d

    //cout<<hour; doesn't work since hour isn't declared in the scope
    //cout<<d.hour; doesn't work since hour is private

	return 0;
	}
