#include<iostream>
#include<cmath>
using namespace std ;
void displayNumber(int *p)
{
    cout<<" value of the address of the pointer "<<*p<<endl;
}
int main()
{
    int number;
    cout<<"Enter A number: ";
    cin>>number;
    displayNumber(&number);
    return 0;
}