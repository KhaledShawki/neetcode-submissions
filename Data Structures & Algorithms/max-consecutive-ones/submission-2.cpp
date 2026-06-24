class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int consecutive =0;
       int maxConsecutive = 0;
       for(unsigned int i = 0; i < nums.size(); ++i)
       {
            consecutive = nums[i] == 1 ? consecutive + 1 : 0;
            if(consecutive > maxConsecutive)
            {
                maxConsecutive = consecutive;
            } 
       } 
        return maxConsecutive;
    }
};