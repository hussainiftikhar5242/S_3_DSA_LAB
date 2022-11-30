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
    vector<organizationData> bubbleSort(vector<organizationData> list)
    {
        for (int x = 0; x < list.size() - 1; x++)
        {
            for (int y = 0; y < list.size() - x - 1; y++)
            {
                if (list.at(y).numberOfEmployees > list.at(y+1).numberOfEmployees)
                {
                    swap(list[y],list[y+1]);
                }
            }
        }
        return list;
    }
    int findMaximium(vector<organizationData> arr)
    {
        int min = arr[0].numberOfEmployees;
        int minIndex = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (min < arr[i].numberOfEmployees)
            {
                min = arr[i].numberOfEmployees;
                minIndex = i;
            }
        }
        return min;
    }
    int findMinimum(vector<organizationData> list,int start, int end)
    {
        int min = list[start].numberOfEmployees;
        int minIndex = start;
        for(int x = start; x < end; x++)
        {
            if(min > list[x].numberOfEmployees)
            {
                min = list[x].numberOfEmployees;
                minIndex = x;
            }
        }
        return minIndex;
    }
    void selectionSort(vector<organizationData> &list)
    {
        for(int x = 0; x < list.size() - 1; x++)
        {
            int minIndex = findMinimum(list,x, list.size());
            swap(list[x], list[minIndex]);
        }
    }
    void insertionSort(vector<organizationData> &list)
    {
        for (int x = 1; x < list.size(); x++)
        {
            int key = list[x].numberOfEmployees;
            int y = x - 1;
            while (y >= 0 && list[y].numberOfEmployees > key)
            {
                swap(list[y + 1],list[y]);
                y--;
            }
            list[y + 1].numberOfEmployees = key;
        }
    }
    vector<organizationData> mergeSort(vector<organizationData> &t,int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(t, start, mid);
            mergeSort(t, mid + 1, end);
            merge(t, start, mid, end);
        }
        return t;
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
    vector<organizationData> countingSort(vector<organizationData> arr)
    {
        int max = findMaximium(arr);
        vector<int> count(max+1);
        vector<organizationData> output(max+1);
        for (int x = 0; x < arr.size(); x++)
        {
            count[arr[x].numberOfEmployees]++;   
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = arr.size() - 1; x >= 0; x--)
        {
            int index = count[arr[x].numberOfEmployees] - 1;
            count[arr[x].numberOfEmployees]--;
            output[index ]= arr[x];
        }
        return output;
    }
    void redixSort(vector<organizationData> &list)
    {
        int max = findMaximium(list);
        int place = 1;
        while ((max / place) > 0)
        {
            countSort(list, place);
            place = place * 10;
        }
    }
    void countSort(vector<organizationData> &arr, int place)
    {
        vector<int> count(10);
        vector<organizationData> output(arr.size());
        for (int x = 0; x < arr.size(); x++)
        {
            count[(arr[x].numberOfEmployees / place) % 10]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = arr.size() - 1; x >= 0; x--)
        {
            int index = count[(arr[x].numberOfEmployees / place) % 10] - 1;
            count[(arr[x].numberOfEmployees / place) % 10]--;
            output[index] = arr[x];
        }
        for (int x = 0; x < output.size(); x++)
        {
            arr[x] = output[x];
        }
    }

    // int partition(vector<organizationData> &arr, int start, int end, int pivot)
    // {
    //     int left = start;
    //     int right = end;
    //     while (left <= right)
    //     {
    //         while (arr[left].numberOfEmployees < arr[pivot].numberOfEmployees && left <= end)
    //             left++;
    //         while (arr[right].numberOfEmployees >= arr[pivot].numberOfEmployees && right >= start)
    //             right--;
    //         if (left < right)
    //             swap(arr[left], arr[right]);
    //     }
    //     swap(arr[right], arr[pivot]);
    //     return right;
    // }
    // void quickSort(vector<organizationData> &arr, int start, int end)
    // {
    //     if (start < end)
    //     {
    //         int pivot = start;
    //         int mid = partition(arr, start + 1, end, pivot);
    //         cout << endl;
    //         quickSort(arr, start, mid - 1);
    //         quickSort(arr, mid + 1, end);
    //     }
    // }

    void heapSort(vector<organizationData> &heapArr, int size)
    {
        for (int x = (size / 2) - 1; x >= 0; x--)
        {
            heapify(heapArr, size, x);
        }
        for (int x = size - 1; x > 0; x--)
        {
            organizationData temp1 = heapArr[0];
            heapArr[0] = heapArr[x];
            heapArr[x] = temp1;
            heapify(heapArr, x, 0);
        }
    }
    int parentIndex(int i)
    {
        return (i - 1) / 2;
    }
    int leftChildIndex(int i)
    {
        return (2 * i) + 1;
    }
    int rightChildIndex(int i)
    {
        return (2 * i) + 2;
    }

    void heapify(vector<organizationData> &heapArr, int size, int index)
    {
        int maxIndex;
        while (true)
        {
            int lIdx = leftChildIndex(index);
            int rIdx = rightChildIndex(index);
            if (rIdx >= size)
            {
                if (lIdx >= size)
                    return;
                else
                    maxIndex = lIdx;
            }
            else
            {
                if (heapArr[lIdx].numberOfEmployees >= heapArr[rIdx].numberOfEmployees)
                    maxIndex = lIdx;
                else
                    maxIndex = rIdx;
            }
            if (heapArr[index].numberOfEmployees < heapArr[maxIndex].numberOfEmployees)
            {
                organizationData temp1 = heapArr[index];
                heapArr[index] = heapArr[maxIndex];
                heapArr[maxIndex] = temp1;
                index = maxIndex;
            }
            else
                return;
        }
    }
    int partition(vector<organizationData> &arr, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            while (arr[left].numberOfEmployees < arr[pivot].numberOfEmployees && left <= end)
                left++;
            while (arr[right].numberOfEmployees >= arr[pivot].numberOfEmployees && right >= start)
                right--;
            if (left < right)
                swap(arr[left], arr[right]);
        }
        swap(arr[right], arr[pivot]);
        return right;
    }
    void quickSort(vector<organizationData> &arr, int start, int end)
    {
        if (start < end)
        {
            int pivot = start;
            int mid = partition(arr, start + 1, end, pivot);
            cout << endl;
            quickSort(arr, start, mid - 1);
            quickSort(arr, mid + 1, end);
        }
    }
    // void bucket_sort(vector<organizationData> &ARRAY)
    // {
    //     vector<organizationData> sortedList = new List<CustomerBL>();
    //     var minValue = ARRAY[0].numberOfEmployees;
    //     var maxValue = ARRAY[0].numberOfEmployees;

    //     for (int i = 1; i < ARRAY.size(); i++)
    //     {
    //         if (ARRAY[i].numberOfEmployees > maxValue)
    //             maxValue = ARRAY[i].numberOfEmployees;
    //         if (ARRAY[i].numberOfEmployees < minValue)
    //             minValue = ARRAY[i].numberOfEmployees;
    //     }

    //     var numberOfBuckets = maxValue - minValue + 1;
    //     vector<organizationData> bucket(numberOfBucket) 


    //     for (int i = 0; i < numberOfBuckets; i++)
    //     {
    //         bucket[i] = new vector<organizationData>();
    //     }

    //     for (int i = 0; i < ARRAY.size(); i++)
    //     {
    //         var selectedBucket = (ARRAY[i].numberOfEmployees / numberOfBuckets);
    //         bucket[selectedBucket].Add(ARRAY[i]);
    //     }

    //     for (int i = 0; i < numberOfBuckets; i++)
    //     {
    //         vector<organizationData> temp;
    //         temp = BUCK_INNER_SORT(bucket[i]);
    //         sortedList.AddRange(temp);
    //         temp = nullptr;
    //     }

    // }
    // void BUCK_INNER_SORT(vector<organizationData> &temp)
    // {
    //     for (int x = 0; x < temp.size() - 1; x++)
    //     {
    //         for (int y = 0; y < temp.size() - x - 1; y++)
    //         {
    //             if (temp[y].numberOfEmployees > temp[y + 1].numberOfEmployees)
    //             {
    //                 organizationData a = temp[y];
    //                 temp[y] = temp[y + 1];
    //                 temp[y + 1] = a;

    //             }
    //         }
    //     }
    // }
    
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
    bool writeData(string path,vector<organizationData> list)
    {
        fstream file;
        file.open(path , ios::out);
        if(file.is_open())
        {
            file << "Index" << "," << "Organization" << "," << "Name" << "," << "Website" << "," << "Country" << "," << "Description" << "," << "Founded" << "," << "Industry" << "," << "Number Of Employees" << endl;
            for (int i = 0; i < temp.size(); i++)
            {
                file << list[i].index << "," << list[i].organizationID << "," << list[i].Name << "," << list[i].website << "," << list[i].country << "," << list[i].description << "," << list[i].founded << "," << list[i].industry << "," << list[i].numberOfEmployees << endl;
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
    cout<<"5. Counting Sort "<<endl;
    cout<<"6. Radix Sort "<<endl;
    cout<<"7. Heap Sort"<<endl;
    cout<<"8. Quick Sort "<<endl;
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
                vector<organizationData> newVector=obj.returnVector();
                long start = getTime();
                newVector=obj.bubbleSort(newVector);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("bubbleSorted.csv",newVector);
            }
            else if(sortOption == 2)
            {
                vector<organizationData> newVector=obj.returnVector();
                long start = getTime();
                obj.selectionSort(newVector);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("selectionSorted.csv",newVector);
            }
            else if(sortOption == 3)
            {
                vector<organizationData> newVector=obj.returnVector();
                long start = getTime();
                obj.insertionSort(newVector);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("insertionSorted.csv",newVector);
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
                obj.writeData("mergeSorted.csv",newVector);
            }
            else if(sortOption == 5)
            {
                vector<organizationData> newVector=obj.returnVector();
                int start1=0;
                int end1=newVector.size()-1;
                long start = getTime();
                newVector=obj.countingSort(newVector);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("countingSorted.csv",newVector);   
            }
            else if(sortOption == 6)
            {
                vector<organizationData> newVector=obj.returnVector();
                int start1=0;
                int end1=newVector.size()-1;
                long start = getTime();
                obj.redixSort(newVector);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("radixSorted.csv",newVector);
            }
            else if(sortOption == 7)
            {
                vector<organizationData> newVector=obj.returnVector();
                int start1=0;
                int end1=newVector.size()-1;
                long start = getTime();
                obj.heapSort(newVector,newVector.size()-1);
                long end = getTime();
                cout << "Algorithem takes:" << end - start << " milliseconds" << endl;
                obj.writeData("heapSorted.csv",newVector);
            }
            else if(sortOption == 8)
            {
                vector<organizationData> newVector=obj.returnVector();
                int start1=0;
                int end1=newVector.size()-1;
                long start = getTime();
                obj.quickSort(newVector,0,newVector.size()-1);
                long end = getTime();
                cout << "Algorithem takes: " << end - start << " milliseconds" << endl;
                obj.writeData("quickSorted.csv",newVector);
            }
            
        }   
    }

}