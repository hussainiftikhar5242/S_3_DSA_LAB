#include<iostream>
#include<cmath>
using namespace std ;
class ComplexNumbers
{
    double realNumber ;
    double imaginaryNumber ;
    public:
    ComplexNumbers()
    {
        realNumber = imaginaryNumber = 0 ;
    }
    ComplexNumbers(double realNumber)
    {
        this->realNumber = realNumber ;
        imaginaryNumber = 0 ;
    }
    ComplexNumbers(double realNumber , double imaginaryNumber)
    {
        this->realNumber = realNumber ;
        this->imaginaryNumber = imaginaryNumber ;
    }
    ComplexNumbers(const ComplexNumbers & obj)
    {
        realNumber = obj.realNumber ;
        imaginaryNumber = obj.imaginaryNumber ;
    }
    void Complexadd( ComplexNumbers c1 , ComplexNumbers c2 )
    {
        this->realNumber = c1.realNumber + c2.realNumber;
        this->imaginaryNumber = c1.imaginaryNumber+c2.imaginaryNumber;
    }
    void Complexsubtract( ComplexNumbers c1, ComplexNumbers c2)
    {
        this->realNumber=c1.realNumber-c2.realNumber;
        this->imaginaryNumber=c1.imaginaryNumber-c2.imaginaryNumber;
    }
    void Complexmultiply( ComplexNumbers c1, ComplexNumbers c2)
    {
        double temp=c1.realNumber*c2.realNumber;
        double temp2=c1.realNumber*c2.imaginaryNumber;
        double temp3=c1.imaginaryNumber*c2.realNumber;
        double temp4=c1.imaginaryNumber*c2.imaginaryNumber;
        temp4=(-1)*temp4;
        this->imaginaryNumber=temp2+temp3;
        this->realNumber=temp+temp4;
    }
    void Complexdivide( ComplexNumbers c1, ComplexNumbers c2)
    {
       double temp1=c1.realNumber*c2.realNumber;               // real number one 
       double temp2=c1.imaginaryNumber*c2.imaginaryNumber;           // real number two by formula of divsion
       double temp3=c1.realNumber*c2.imaginaryNumber;           //imaginary number one
       double temp4=c1.imaginaryNumber*c2.realNumber;
       double real=temp1+temp2;
       double imag=(-1)*c2.imaginaryNumber;
       double temp5=c2.realNumber*c2.realNumber;
       double temp8=c2.imaginaryNumber*imag;
       double realNum=temp5-temp8;
       temp4=(-1)*temp4;
       double imaginary=temp3-temp4;
       this->realNumber=(real)/realNum;
       this->imaginaryNumber=(imaginary)/realNum;
    }
    void Complexconjugate( ComplexNumbers c1)
    {
        this->imaginaryNumber=(-1)*c1.imaginaryNumber;
    }
    void print()
    {
        if(this->imaginaryNumber > 0)
        {
            cout<<this->realNumber<<"+"<<this->imaginaryNumber<<"i"<<endl;
        }
        else
        {
            cout<<this->realNumber<<this->imaginaryNumber<<"i"<<endl;
        }
    }
    void setReal(double realNumber)
    {
        this->realNumber=realNumber;
    }
    void setImg(double imaginaryNumber)
    {
        this->imaginaryNumber=imaginaryNumber;
    }
    double getReal()
    {
        return this->realNumber;
    }
    double getImg()
    {
        return this->imaginaryNumber;
    }
    
};
int main()
{
    ComplexNumbers complex1,complex2,complex3;
    double realNumber1,realNumber2,imaginaryNumber1,imaginaryNumber2;
    cout<<"Enter first real Numbers and complex number: ";
    cin>>realNumber1>>imaginaryNumber1;
    cout<<"Enter 2nd real Numbers: and complex number: ";
    cin>>realNumber2>>imaginaryNumber2;
    complex1.setReal(realNumber1);
    complex1.setImg(imaginaryNumber1);
    complex2.setReal(realNumber2);
    complex2.setImg(imaginaryNumber2);
    complex3.Complexadd(complex1,complex2);
    complex3.print();
    complex3.Complexmultiply(complex1,complex2);
    complex3.print();
    complex3.Complexdivide(complex1,complex2);
    complex3.print();
    complex3.Complexsubtract(complex1,complex2);
    complex3.print();
    complex3.Complexconjugate(complex1);
    complex3.print();

    return 0;
}