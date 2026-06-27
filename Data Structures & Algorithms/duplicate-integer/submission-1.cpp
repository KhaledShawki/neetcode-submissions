class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numSet;
        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if(numSet.find(num) != numSet.end())
            {
                return true;
            }
            numSet.insert(num);
        }    

        return false;
    }
};