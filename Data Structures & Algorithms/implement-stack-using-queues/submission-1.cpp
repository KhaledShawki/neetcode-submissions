class MyStack 
{
public:
    MyStack() 
    {
    }
    
    void push(int x) 
    {
        m_queue.push(x);
        
        int rotation = m_queue.size() - 1;
        while(rotation > 0)
        {
            m_queue.push(m_queue.front());
            m_queue.pop();
            rotation--;
        }
    }
    
    int pop() 
    {
        int back = m_queue.front();
        m_queue.pop();
        return back;
    }
    
    int top() 
    {
        return m_queue.front();
    }
    
    bool empty() 
    {
        return m_queue.empty();
    }

private:
    std::queue<int> m_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */