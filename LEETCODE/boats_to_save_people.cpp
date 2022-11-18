class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // insertionSort(people);
        sort(people.begin(),people.end());
        int count=0;
        int checker=people.size()-1;
        int i=0;
        while(i<=checker)
        {
            if(people[i]+people[checker] <= limit )
            {
                count++;
                i++;
                checker--;
            }
            else if(people[i] <= limit)
            {
                checker--;
                count++;   
            }
        }
        return count;
    }
    void insertionSort(vector<int>& arr)
    {
        for (int x = 1; x < arr.size(); x++)
        {
            int key = arr[x];
            int y = x - 1;
            while (y >= 0 && arr[y] > key)
            {
                arr[y + 1] = arr[y];
                y--;
            }
            arr[y + 1] = key;
        }
    }
};
