class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> ans;
        for(unsigned int x = 0; x < 2; ++x)
        {
            for(unsigned int i = 0; i < nums.size(); ++i)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};