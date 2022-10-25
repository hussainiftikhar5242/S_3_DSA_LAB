class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int size=magazine.size();
        int size2=ransomNote.size();
        int count=0;
        for(int i=0;i<size;i++)
        {
            for(int y=0;y<size2;y++)
            {
                if(ransomNote[y] == magazine[i])
                {
                    count++;
                    ransomNote[y]='9';
                    break;
                }
            }
        }
        if(size2 == count)
        {
            return true;
        }
        return false;
        
    }
};