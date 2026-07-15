class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1; 
        int right = 0;
        for(int& p : piles)
        {
            right = max(right, p);
        }


        int result = right;

        while (left <= right)
        {
            int k = (left + right) / 2;

            int hours = 0;

            for(int& p : piles)
            {
                hours +=  (p + k - 1) / k;
            }

            if(hours <= h)
            {
                result = min(result, k);
                right = k -1;
            }
            else
            {
                left = k + 1;
            }
          
        }

        return result; 
    }
};
