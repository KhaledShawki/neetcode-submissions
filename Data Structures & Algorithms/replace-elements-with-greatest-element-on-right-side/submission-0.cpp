class Solution 
{
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        for(unsigned int i = 0; i < arr.size(); ++i)
        {
            int rightMax = -1;
            for ( unsigned int j = i + 1; j < arr.size(); ++j)
            {
                if(arr[j] > rightMax)
                {
                    rightMax = arr[j];
                }
            }

            arr[i] = rightMax;
        }   
        return arr;
    }
};