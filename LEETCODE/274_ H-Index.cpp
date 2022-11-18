class Solution {
public:
    int hIndex(vector<int>& citations) {
        for(int i=0;i<citations.size()-1;i++)
        {
            for(int y=0;y<citations.size()-i-1;y++)
            {
                if(citations[y] < citations[y+1])
                {
                    swap(citations[y],citations[y+1]);
                }
            }
        }
        int count=1;
        int result=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i] >= count)
            {
                result++;
            }
            count++;
        }
        return result;
        
    }
};