#include<iostream>
#include<list>
#include<vector>
#include <set> 
#include <algorithm>
using namespace std;
void isMember(int num,vector<int> new_list)
{
    int check=0;
    for(int i=0;i<new_list.size();i++)
    {
        if(num == new_list.at(i))
        {
            cout<<"Enter Number is member"<<endl;
            check=1;
            break;
        }
    }
    if(check == 0)
    {
        cout<<"Enter Number is not member"<<endl;
    }
}
void Union(vector<int> list1,vector<int> list2)
{ 
    vector<int> result;     
    set_union(begin(list1), end(list1),begin(list2), end(list2),inserter(result, end(result)));  
    for_each(begin(result), end(result), [](int x) {  
    cout << x << endl;  
    }); 
}
void interSection(vector<int> list1,vector<int> list2)
{
    vector<int> result;
    for(int i=0;i<list1.size();i++)
    {
        for(int y=0;y<list2.size();y++)
        {
            if( list1.at(i) == list2.at(y) )
            {
                result.push_back(list1.at(i));
                break;
            }
        }
    }
    for (int i=0;i<result.size();i++)
    {
        cout<<result.at(i)<<" ";
    }
}
void isSubset(vector<int> list1,vector<int> list2)
{
    int count=0;
    for(int i=0;i<list2.size();i++)
    {
        for(int y=0;y<list1.size();y++)
        {
            if ( list2.at(i) == list1.at(y) )
            {
                count++;
            }
        }
    }
    if(count >= list2.size())
    {
        cout<<"Enter List is subset"<<endl;
    }
    else 
    {
        cout<<"Enter list is not subset  "<<endl;
    }
}
int main()
{
    vector<int> list1={1,343,45,65,3,2,33,77};
    int i=0;
    cout<<"Enter Number is ";
    cin>>i;
    list1.push_back(i);
    cout<<" Enter element you want to remove: ";
    cin>>i;
    list1.erase(list1.begin()+i);
    int num;
    cout<<"Enter Number for check "<<endl;
    cin>>num;
    isMember(num,list1);
    vector<int> list2={2,34,54,56,7,78,90};
    Union(list1,list2);
    interSection(list1,list2);
    int size;
    cout<<"Enter SIze of set "<<endl;
    cin>>size;
    vector<int> list3;
    cout<<"Enter Subset "<<endl;
    for(int i=0;i<size;i++)
    {
        int num=0;
        cin>>num;
        list3.push_back(num);
    }
    isSubset(list1,list3);
}