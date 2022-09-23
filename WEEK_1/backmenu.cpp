#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec;
    string display[3]={"First","Second","Third"};
    int option=-8;
    int count=0;
    cout<<"-1 : Exit"<<endl;
    int front=0;
    while(true)
    {
        if(option == -1)
        {
            break;
        }
        if(option != 0)
        {
            count++;
            cout<<count<<": Go to the "<<display[front--]<<" Menu"<<endl;
        }
        if(option == 0 && vec.empty() == false)
        {
            vec.pop_back();
            front=vec.back();
            count--;
            cout<<"0. Go back"<<endl;
            cout<<count<<": Go to the "<<display[front--]<<" Menu"<<endl;
        }
        cout<<"Your Option"<<endl;
        cin>>option;
        if(option != 0)
        vec.push_back(option);
        front=vec.back();
    }
}