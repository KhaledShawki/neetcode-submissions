class MinStack 
{
public:
    MinStack() = default;
    
    void push(int val) 
    {  
        m_stack.push_back(val);
        m_mins.push_back(m_mins.empty() ? val : std::min(val, m_mins.back()));
    }
    
    void pop() 
    {
        m_stack.pop_back();
        m_mins.pop_back();
    }
    
    int top() 
    {
       return m_stack.back(); 
    }
    
    int getMin() 
    {
        return m_mins.back();
    }

private:
    std::vector<int> m_stack;
    std::vector<int> m_mins;
};