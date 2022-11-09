class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int y=0;
        for(int i=0;i<g.size() && y < s.size();)
        {
            if(s[y]>=g[i])
            {
                i++;
                count++;
            }
            y++;
        }
        
        return count;
        
    }
    void insertionSort(vector<int>& g,vector<int>& s)
    {
        for(int i=1;i<g.size();i++)
        {
            int key=g.at(i);
            int y=i-1;
            while(y>=0 && g.at(y)>key)
            {
                g.at(y+1)=g.at(y);
                y--;
            }
            g.at(y+1)=key;
        }
        for(int i=1;i<s.size();i++)
        {
            int key=s.at(i);
            int y=i-1;
            while(y>=0 && s.at(y)>key)
            {
                s.at(y+1)=s.at(y);
                y--;
            }
            s.at(y+1)=key;
            
        }
        
    }
};