class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        for(vector<int>& m : matrix)
        {
            if(m.empty())
            {
                return false;
            }
            
            if(target < m.front())
            {
                return false;
            }

            if(m[m.size() - 1] < target)
            {
                continue;
            }
            
            int l = 0;
            int r = m.size() - 1;
            
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(target > m[mid])
                {
                    l = mid + 1;
                }
                else if(target < m[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    return true;
                }
            }
        }

        return false;
    }
};
