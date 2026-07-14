class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());

        int l = 0;
        int r = rows * columns - 1;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            int row = mid / columns;
            int column = mid % columns;

            int value = matrix[row][column];

            if(value < target)
            {
                l = mid + 1;
            }
            else if(value > target)
            {
                r = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
