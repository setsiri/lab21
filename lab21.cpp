#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		friend ComplexNumber operator+(double,const ComplexNumber &);
		friend ComplexNumber operator-(double,const ComplexNumber &);
		friend ComplexNumber operator*(double,const ComplexNumber &);
		friend ComplexNumber operator/(double,const ComplexNumber &);
		friend ostream & operator<<(ostream &os,const ComplexNumber &);
		friend bool operator==(const ComplexNumber &,const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)-(imag*c.imag)),((real*c.imag)+(c.real*imag)));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((real*c.imag)-(imag*c.real))/(pow(c.real,2)+pow(c.imag,2))*(-1));
}

ComplexNumber operator+(double c1,const ComplexNumber &c2){
	return ComplexNumber(c1+c2.real,c2.imag);
}

ComplexNumber operator-(double c1,const ComplexNumber &c2){
	return ComplexNumber(c1-c2.real,-c2.imag);
}

ComplexNumber operator*(double c1,const ComplexNumber &c){
	return ComplexNumber(((c1*c.real)-(0*c.imag)),((c1*c.imag)+(c.real*0)));
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real/(pow(c.real,2)+pow(c.imag,2)),s*c.imag/(pow(c.real,2)+pow(c.imag,2))*(-1));
}

bool operator==(const ComplexNumber &d,const ComplexNumber &c){
	if(d.real==c.real&&d.imag==c.imag){
		return true;
	}else{
		return false;
	}
}

double ComplexNumber::abs(){
	double r;
	return r= sqrt((real*real)+(imag*imag));
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/M_PI;
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.real==0&&c.imag!=0)
		return os <<c.imag<<"i";
	else if(c.real!=0&&c.imag==0)
		return os <<c.real;
	else if(c.real==0&&c.imag==0)
		return os <<0;
	else if(c.real!=0&&c.imag<0)
		return os <<c.real<<c.imag<<"i";
	else
		return os <<c.real<<"+"<<c.imag<<"i";
}
//Write your code here

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





