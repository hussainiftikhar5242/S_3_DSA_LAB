#include<iostream>
#include<cmath>
using namespace std ;
void findGreatest(int *num1,int *num2,int *num3)
{
    if(*num1 > *num2 && *num1 > *num3)
    {
        cout<<" Largest Number is "<<*num1<<endl;
    }
    else if(*num2 > *num1 && *num2 > *num3)
    {
        cout<<" Largest Number is "<<*num2<<endl;
    } 
    else
    {
        cout<<" Largest Number is "<<*num3<<endl;
    }
}
void findSmallest(int *num1,int *num2,int *num3)
{
    if(*num1 < *num2 && *num1 < *num3)
    {
        cout<<" Smalllest Number is "<<*num1<<endl;
    }
    else if(*num2 < *num1 && *num2 < *num3)
    {
        cout<<" Smallest Number is "<<*num2<<endl;
    } 
    else
    {
        cout<<" smallest Number is "<<*num3<<endl;
    }
}
int main()
{
    int num1,num2,num3;
    cout<<" Enter Three Number: "<<endl;
    cin>>num1>>num2>>num3;
    findGreatest(&num1,&num2,&num3);
    findSmallest(&num1,&num2,&num3);
    return 0;
}