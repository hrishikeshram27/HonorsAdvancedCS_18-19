//Quick Class Exerrcise
#include<iostream>
#include <math.h>

using namespace std;

class Cube{
	private:
		double Side;

    public:
		Cube();				//default constructor set at   “ – 2 “
		Cube(double a);
		void setSide(double s);
		double getSide();		// used in Properties
		double Diagonal();		// used in Properties
        double Area();			// used in Properties
		double Volume();		// used in Properties
		void Properties();		// Calls all functions and displays them
		void challenge(Cube x);
		void operator+(Cube);
		void operator-();
};

Cube::Cube(){
    Side = -2;
}

Cube::Cube(double first){
    Side = first;
}

void Cube::setSide(double s){
    Side = s;
}

double Cube::getSide(){
    return Side;
}

double Cube::Diagonal(){
    return (Side*(sqrt(2)));
}

double Cube::Area(){
    return (6*Side*Side);
}

double Cube::Volume(){
    return (Side*Side*Side);
}

void Cube::Properties(){
    cout<<"The side length is: "<<getSide()<<endl;
    cout<<"The diagonal face is: "<<Diagonal()<<endl;
    cout<<"The surface area is: "<<Area()<<endl;
    cout<<"The volume is: "<<Volume()<<endl;
}

void Cube::challenge(Cube other){
    double answer = (other.getSide())+Side;
    cout<<endl<<answer<<endl;
}

void Cube::operator+(Cube temp){
    cout<<endl<<"operator "<<Side+temp.getSide()<<endl;
}

void Cube::operator-(){
    cout<<endl<<Volume()-Area()<<endl;
}

int main(){
	Cube c;
	double myside;
	cout<<"Enter side length: ";
	cin>>myside;
	c.setSide(myside);
	c.Properties();

	Cube p(3);
	double added = c.getSide() + p.getSide();
	Cube add(added);
	add.Properties();

	c.challenge(p);
	c+p;
	-c;
	return 0;
}
