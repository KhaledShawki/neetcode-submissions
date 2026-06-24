class Solution
{
public:
    int calPoints(vector<string>& operations)
    {
        vector<int> scores;
        scores.reserve(operations.size());

        int sum = 0;

        for (const string& op : operations)
        {
            if (op == "+")
            {
                int score = scores[scores.size() - 1] + scores[scores.size() - 2];
                scores.push_back(score);
                sum += score;
            }
            else if (op == "D")
            {
                int score = scores.back() * 2;
                scores.push_back(score);
                sum += score;
            }
            else if (op == "C")
            {
                sum -= scores.back();
                scores.pop_back();
            }
            else
            {
                int score = stoi(op);
                scores.push_back(score);
                sum += score;
            }
        }

        return sum;
    }
};