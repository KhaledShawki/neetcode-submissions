class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int colors[3] {0,0,0};
        for(int num : nums)
        {
            colors[num]++;
        }

        int k = 0;
        for(int i = 0; i < sizeof(colors) / sizeof(int); ++i)
        {
            for(int j = 0; j < colors[i]; ++j)
            {
                nums[k++] = i;
            }
        }
    }
};