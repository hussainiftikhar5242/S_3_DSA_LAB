#include<iostream>
#include <cstdlib>
#include<unistd.h> 
#include<fstream>
#include<vector>
#include<string>
#include <sstream>
#include<thread>
#include<chrono>
#include<queue>
#include<stack>
#include<algorithm>
#include<sys/time.h>
using namespace std;
using namespace std::chrono;
// --------------------------------------------organizantio  stucture---------------------------//
struct  organizationData
{
    int index;
    string organizationID;
    string Name;
    string country;
    string website;
    string description;
    string founded;
    string industry;
    int numberOfEmployees;
};
// ------------------------------------------------organization class--------------------------------------------//
class organizationClass{
    vector<organizationData> temp;
    public: 
    vector<organizationData> createRecord(int index,string organizationID,string name,string website,string country,string description,string founded,string industry,int numberOfEmployees)
    {
        organizationData newtemp;
        newtemp.Name=name;
        newtemp.index=index;
        newtemp.organizationID=organizationID;
        newtemp.country=country;
        newtemp.website=website;
        newtemp.description=description;
        newtemp.founded=founded;
        newtemp.industry=industry;
        newtemp.numberOfEmployees=numberOfEmployees;
        temp.push_back(newtemp);
        return temp;
    }
    // --------------------------------sorting algorithem--------------------------------//
    void bubbleSort()
    {
        for (int x = 0; x < temp.size() - 1; x++)
        {
            for (int y = 0; y < temp.size() - x - 1; y++)
            {
                if (temp.at(y).numberOfEmployees > temp.at(y+1).numberOfEmployees)
                {
                    swap(temp[y].index, temp[y + 1].index);
                    swap(temp[y].organizationID, temp[y + 1].organizationID);
                    swap(temp[y].Name, temp[y + 1].Name);
                    swap(temp[y].founded, temp[y + 1].founded);
                    swap(temp[y].industry, temp[y + 1].industry);
                    swap(temp[y].description, temp[y + 1].description);
                    swap(temp[y].numberOfEmployees, temp[y + 1].numberOfEmployees);
                    swap(temp[y].website, temp[y + 1].website);
                    swap(temp[y].country, temp[y + 1].country);
                }
            }
        }
    }
    int findMinimum(int start, int end)
    {
        int min = temp[start].numberOfEmployees;
        int minIndex = start;
        for(int x = start; x < end; x++)
        {
            if(min > temp[x].numberOfEmployees)
            {
                min = temp[x].numberOfEmployees;
                minIndex = x;
            }
        }
        return minIndex;
    }
    void selectionSort()
    {
        for(int x = 0; x < temp.size() - 1; x++)
        {
            int minIndex = findMinimum(x, temp.size());
            swap(temp[x], temp[minIndex]);
        }
    }
    void insertionSort()
    {
        for (int x = 1; x < temp.size(); x++)
        {
            int key = temp[x].numberOfEmployees;
            int y = x - 1;
            while (y >= 0 && temp[y].numberOfEmployees > key)
            {
                swap(temp[y + 1],temp[y]);
                y--;
            }
            temp[y + 1].numberOfEmployees = key;
        }
    }
    void mergeSort(vector<organizationData> &t,int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(temp, start, mid);
            mergeSort(temp, mid + 1, end);
            merge(temp, start, mid, end);
        }
    }
    void merge(vector<organizationData> &arr, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        queue<organizationData> tempArr;
        while (i <= mid && j <= end){
        if (arr[i].numberOfEmployees < arr[j].numberOfEmployees)
        {
            tempArr.push(arr[i]);
            i++;
        }
        else
        {
            tempArr.push(arr[j]);
            j++;
        }
        }
        while (i <= mid)
        {
            tempArr.push(arr[i]);
            i++;
        }
        while (j <= end)
        {
            tempArr.push(arr[j]);
            j++;
        }
        for (int x = start; x <= end; x++)
        {
            arr[x] = tempArr.front();
            tempArr.pop();
        }
    }
    // ------------------------------end of sorting function------------------------------//
    vector<organizationData> returnVector()
    {
        return temp;
    }
    void loadData(string path)
    {
        fstream myFile;
        myFile.open(path,ios::in);
        string line;
        int index;
        string organizationID;
        string name;
        string website;
        string city;
        string country;
        string description;
        string founded;
        string industry;
        int numberOfEmployees=0;
        int count=0;
        string temp;
        while(!(myFile.eof()))
        {
            getline(myFile,line);
            if(count == 0)
            {
                count=1;
            }
            else
            {
                string a=parseData(line,1);
                stringstream s(a);
                s>>index;
                organizationID=parseData(line,2);
                name=parseData(line,3);
                website=parseData(line,4);
                country=parseData(line,5);
                description=parseData(line,6);
                founded=parseData(line,7);
                industry=parseData(line,8);
                temp=parseData(line,9);
                stringstream i(temp);
                i>>numberOfEmployees;
                createRecord(index,organizationID,name,website,country,description,founded,industry,numberOfEmployees);
            }
        }
    }
    string parseData(string record, int field)
    {
        int comma = 1;
        string item = "";
        for(int x = 0; x < record.length(); x++)
        {
            if (record[x] == ',' )
            {
                comma++;
            }
            else if (comma == field)
            {
                item = item + record[x];
            }
        }
        return item;
    }
    bool writeData(string path)
    {
        fstream file;
        file.open(path , ios::out);
        if(file.is_open())
        {
            file << "Index" << "," << "Organization" << "," << "Name" << "," << "Website" << "," << "Country" << "," << "Description" << "," << "Founded" << "," << "Industry" << "," << "Number Of Employees" << endl;
            for (int i = 0; i < temp.size(); i++)
            {
                file << temp[i].index << "," << temp[i].organizationID << "," << temp[i].Name << "," << temp[i].website << "," << temp[i].country << "," << temp[i].description << "," << temp[i].founded << "," << temp[i].industry << "," << temp[i].numberOfEmployees << endl;
            }
            file.close();
            return true;
        }
        else
        {
            return false;
        }
    }
};
// =--------------------------------end of class------------------------------//
int loadMenu()
{
    cout<<"1. Load 100 Records "<<endl;
    cout<<"2. Load 1000 Records "<<endl;
    cout<<"3. Load 10000 Records "<<endl;
    cout<<"4. Load 100000 Records "<<endl;
    cout<<"5. Load 500000 Records "<<endl;
    cout<<" Back: ";
    cout<<"Your Option:  ";
    int option=0;
    cin>>option;
    return option;

}
int sortingMenu()
{
    cout<<"1. Bubble Sort "<<endl;
    cout<<"2. Selection Sort "<<endl;
    cout<<"3. Insertion Sort "<<endl;
    cout<<"4. Merge Sort "<<endl;
    cout<<"you Option "<<endl;
    int option;
    cin>>option;
    return option;
}
long getTime()
{
    struct timeval start;
    gettimeofday(&start , NULL);
    return start.tv_sec*1000000 + start.tv_usec;
}
// ================================main function-----------------------------------//
int main()
{
    organizationClass obj;
    while(true)
    { 
        int loadOption=loadMenu();
        if(loadOption == 1)
        {
            string path="organizations-100.csv";
            obj.loadData(path);
        }
        else if(loadOption == 2)
        {
            obj.loadData("organizations-1000.csv");
        }
        else if(loadOption == 3)
        {
            obj.loadData("organizations-10000.csv");
        }
        else if(loadOption == 4)
        {
            obj.loadData("organizations-100000.csv");
        }
        else if(loadOption == 5)
        {
            obj.loadData("organizations-500000.csv");
        }
        while (true)
        {
            int sortOption=sortingMenu();
            if(sortOption == 1)
            {
                long start = getTime();
                obj.bubbleSort();
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("bubbleSorted.csv");
            }
            else if(sortOption == 2)
            {
                long start = getTime();
                obj.selectionSort();
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("selectionSorted.csv");
            }
            else if(sortOption == 3)
            {
                long start = getTime();
                obj.insertionSort();
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("insertionSorted.csv");
            }
            else if(sortOption == 4)
            {
                vector<organizationData> newVector=obj.returnVector();
                int start1=0;
                int end1=newVector.size()-1;
                long start = getTime();
                obj.mergeSort(newVector,start1,end1);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("mergeSorted.csv");
            }
        }   
    }

}