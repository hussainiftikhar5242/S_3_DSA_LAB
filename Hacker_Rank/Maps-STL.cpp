#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map <string, int> numberOfStudent;
    int numberOfQuries;
    vector<int> nums;
    cin>>numberOfQuries;
    int type=0;
    string name="";
    for(int i=0;i<numberOfQuries;i++)
    {
        cin>>type;
        int num;
        if(type == 1)
        {
            cin>>name;
            cin>>num;
            int sum=0;
            sum=num;
            for(auto x:numberOfStudent)
            {
                if(x.first == name)
                {
                    sum=sum+x.second;
                }
            }
            numberOfStudent.erase(name);            
            numberOfStudent.insert(make_pair(name,sum));
        }
        if(type == 2)
        {
            cin>>name;
            numberOfStudent.erase(name);
        }
        if(type == 3)
        {
            bool check=false;
            cin>>name;
            for(auto x:numberOfStudent)
            {
                if(name == x.first)
                {
                    nums.push_back(x.second);
                    check=true;
                }
            }
            if(check == false)
            {
                nums.push_back(0);
            }
        }
    }
    for(int i=0;i<nums.size();i++)
    {
    cout<<nums.at(i)<<endl;
    }  
    return 0;
}



