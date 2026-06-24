class Solution 
{
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> s;
        for(string op : operations)
        {

            if(op == "+")
            {
                int resultToPush;
                int top = s.top();
                s.pop();
                resultToPush = top + s.top();
                s.push(top);
                s.push(resultToPush);
            }
            else if( op == "D")
            {
                s.push( 2 * s.top()); 
            }
            else if(op == "C")
            {
                s.pop();
            }
            else 
            {
                s.push(std::stoi( op ));
            }
        }

        int sum = 0;
        while( !s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};