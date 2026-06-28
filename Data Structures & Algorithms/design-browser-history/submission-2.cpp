class BrowserHistory 
{
public:
    BrowserHistory(string homepage) 
        : m_index(0)
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
    }
    
    string back(int steps) 
    {
        m_index = std::max(m_index - steps, 0);
        return m_history[m_index];
    }
    
    string forward(int steps) 
    {
        m_index = std::min(m_index + steps, static_cast<int>(m_history.size()) - 1);
        return m_history[m_index];
    }

private:
    int m_index;
    vector<string> m_history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */