class Solution 
{
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {

        int numSize = nums.size();
        int concatedArraySize = nums.size() * 2;
        std::vector<int> result(concatedArraySize);
        
        for(unsigned int i = 0; i < concatedArraySize ; ++i)
        {
            result[i] = nums[i % numSize];
        }
        
        return result;
    }
};