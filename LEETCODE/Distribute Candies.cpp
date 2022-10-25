class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int size=candyType.size();
        size=size/2;
        int size2=0;
        // candyType.erase(unique( candyType.begin(), candyType.end() ), candyType.end());
    
        vector<int>::iterator ip;
        std::sort(candyType.begin(), candyType.end());
        ip = std::unique(candyType.begin(), candyType.end() );
        candyType.resize(std::distance(candyType.begin(), ip));
        size2=candyType.size();
        if(size<size2)
        {
            return size;
        }
        else 
        {
            return size2;
        }
        return size;
        
    }
};