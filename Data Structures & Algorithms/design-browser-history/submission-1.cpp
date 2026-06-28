class BrowserHistory 
{
public:
    BrowserHistory(string homepage) 
        : m_index(0)
        , m_length(1)
    {
        m_history.push_back(homepage);
    }
    
    void visit(string url) 
    {
        if(m_history.size() < m_index + 2)
        {
            m_history.push_back(url);
        }
        else
        {
            m_history[m_index + 1] = url;
        }

        m_index++;
        m_length = m_index + 1;
    }
    
    string back(int steps) 
    {
        m_index = std::max(m_index - steps, 0);
        return m_history[m_index];
    }
    
    string forward(int steps) 
    {
        m_index = std::min(m_index + steps, m_length - 1);
        return m_history[m_index];
    }

private:
    int m_index;
    int m_length;
    vector<string> m_history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */