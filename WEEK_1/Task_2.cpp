#include<iostream>
#include<cmath>
using namespace std ;
int main()
{
    int number;
    cout<<"Enter A number: ";
    cin>>number;
    int *p= &number;
    cout<<"Address of the variable is "<<p<<endl;
    return 0;
}