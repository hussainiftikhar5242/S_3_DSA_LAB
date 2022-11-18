class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        double count=salary.size()-2;
        for(int i=0;i<salary.size()-1;i++)
        {
            for(int y=0;y<salary.size()-i-1;y++)
            {
                if(salary.at(y) > salary.at(y+1))
                {
                    swap(salary.at(y),salary.at(y+1));
                }
            }
        }
        for(int i=1;i<salary.size()-1;i++)
        {
            sum=sum+salary.at(i);
        }
        return sum/count;
    }
};