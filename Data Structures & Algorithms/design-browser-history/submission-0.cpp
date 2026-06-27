class BrowserHistory 
{
public:
    BrowserHistory(string homepage) 
    {
       m_node = new Node(homepage);
    }
    
    void visit(string url) 
    {   
        Node* newNode = new Node(url);
        newNode->prev = m_node;
        m_node->next = newNode;
        m_node = newNode;
    }
    
    string back(int steps) 
    {
        while(steps > 0 && m_node->prev)
        {
            m_node = m_node->prev;
            steps--;
        }
        return m_node->val;
    }
    
    string forward(int steps) 
    {
        while(steps > 0 && m_node->next)
        {
            m_node = m_node->next;
            steps--;
        }
        return m_node->val;
    }

private:
    struct Node
    {
        string val;
        Node* next;
        Node* prev;

        Node(string v)
            : val(v)
            , next(nullptr)
            , prev(nullptr)
        {}
    };

    Node* m_node;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */