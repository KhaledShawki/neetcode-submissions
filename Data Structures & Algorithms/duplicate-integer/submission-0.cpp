class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_map<int, unsigned int> numToIndex;
        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if(numToIndex.find(num) != numToIndex.end())
            {
                return true;
            }
            numToIndex[num] = i;
        }    

        return false;
    }
};