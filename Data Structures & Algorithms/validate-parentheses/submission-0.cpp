class Solution {
public:
    bool isValid(string s) 
    {
        vector<char> stack;
        map<char, char> closeToOpen = 
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for(unsigned int i = 0; i < s.length(); ++i)
        {
            
            char c = s[i];
            if(closeToOpen.find(c) != closeToOpen.end())
            {
                if(!stack.empty() && stack.back() == closeToOpen[c])
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push_back(c);
            }
        }

        return stack.empty();
    }
};
