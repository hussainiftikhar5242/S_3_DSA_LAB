#include<iostream>
#include<cmath>
using namespace std ;
int main()
{
    int number;
    cout<<"Enter A number: ";
    cin>>number;
    int *p= &number;
    cout<<" value of the address of the pointer "<<*p<<endl;
    return 0;
}