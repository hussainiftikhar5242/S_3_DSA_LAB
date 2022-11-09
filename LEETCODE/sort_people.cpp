class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i=0;i<heights.size()-1;i++)
        {
            long max=findLargest(heights,i,heights.size());
            swap(names.at(i),names.at(max));
            swap(heights.at(i),heights.at(max));
        }
        return names;
        
    }
    long findLargest(vector<int>& heights,int start,int end)
    {
        long larg=heights.at(start);
        long maxIndex=start;
        for(int i=start;i<end;i++)
        {
            if(larg < heights.at(i))
            {
                larg=heights.at(i);
                maxIndex=i;
            }
        }
        return maxIndex;
    }
};