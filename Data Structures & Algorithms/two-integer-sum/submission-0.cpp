class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numToIndex;

        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int diff = target - num;

            if(numToIndex.find(diff) != numToIndex.end())
            {
                return {numToIndex[diff], static_cast<int>(i)};
            }
            numToIndex[num] = i;
        }    

        return {};
    }
};
