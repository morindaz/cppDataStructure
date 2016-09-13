#include<iostream>
using namespace std;
class Complex{
private:
    double real;
    double imag;
public:
    Complex(){real = 0;imag =0;}
    Complex(double r, double i):real(r),imag(i){}
    Complex operator+(Complex &c2);
    friend ostream& operator<<(ostream&,Complex&);
};
Complex Complex::operator+(Complex &c2)
{
    return Complex(this->real+c2.real,this->imag+c2.imag);
}

ostream& operator<<(ostream& output, Complex&c)//that does ostream& mean?
{
    output<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
    return output;
}


int main()
{
    Complex c1(2,4),c2(6,10),c3;
    c3= c1+c2;
    cout<<c3;
    return 0;
}
