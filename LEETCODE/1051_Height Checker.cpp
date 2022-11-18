class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int max = *max_element(heights.begin(), heights.end());
        vector<int> count(max + 1);
        vector<int> output(heights.size());
        for (int x = 0; x < heights.size(); x++)
        {
            count[heights[x]]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = heights.size() - 1; x >= 0; x--)
        {
            int index = count[heights[x]] - 1;
            count[heights[x]]--;
            output[index] = heights[x];
        }
        int result=0;
        for (int x = 0; x < output.size(); x++)
        {
            if(heights[x] != output[x])
            {
                result++;
            }
        }
        return result;
        
    }
};