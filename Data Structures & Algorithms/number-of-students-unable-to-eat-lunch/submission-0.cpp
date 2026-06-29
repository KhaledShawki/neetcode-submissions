class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int result = students.size();

        std::unordered_map<int, int> count;

        for(int s : students)
        {
            if(count.find(s) == count.end())
            {
                count[s] = 0;
            }
            count[s]++;
        }

        for(int s : sandwiches)
        {
            if(count[s] > 0)
            {
                result--;
                count[s]--;
            }
            else
            {
                return result;
            }
        }

        return result;
    }
};