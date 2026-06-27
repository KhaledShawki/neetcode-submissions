class MyLinkedList 
{
public:
    MyLinkedList() 
        : m_node(nullptr)
        , m_size(0)
    {}

    ~MyLinkedList()
    {
        if(m_node)
        {
            Node* node = m_node;
            do
            {
                Node* next = node->next;
                delete node;
                node = next;
            }
            while(node);
        }
         m_size = 0;;
    }
    
    int get(int index) 
    {
        if(index < 0 || index >= static_cast<int>(m_size))
        {
            return -1;
        }

        Node* node = m_node;
        for(unsigned int i = 0; i < index; ++i)
        {
            node = node->next;
        }

        return node->val;
    }
    
    void addAtHead(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = m_node;
        newNode->prev = nullptr;

        if(m_node)
        {
            m_node->prev = newNode;
        }

        m_node = newNode;
        m_size++;
    }
    
    void addAtTail(int val) 
    {
         if(m_size == 0)
        {
            m_node = new Node(val);
            m_size++;
            return;
        }

        Node* tail = m_node;
        while(tail->next)
        {
            tail = tail->next;
        }

        Node* newNode = new Node();
        newNode->val = val;
        newNode->prev = tail;
        newNode->next = nullptr;

        tail->next = newNode;

        m_size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index < 0 || index > static_cast<int>(m_size))
        {
            return;
        }

        if(index == 0)
        {
            addAtHead(val);
            return; 
        }

        if(index == m_size)
        {
            addAtTail(val);
            return;
        }

        Node* node = m_node;

        for(unsigned int i = 0; i < index; ++i)
        {
            node = node->next;
        }

        Node* newNode = new Node(val);
        newNode->next = node;
        newNode->prev = node->prev;

        if(node->prev)
        {
            node->prev->next = newNode;
        }

        node->prev = newNode;

        m_size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < 0 || index >= static_cast<int>(m_size))
        {
            return;
        }

        Node* node = m_node;
        for(unsigned int i = 0; i < index; ++i)
        {
            node = node->next;
        }

        if(node->prev)
        {
            node->prev->next = node->next;
        }
        else
        {
            m_node = node->next;
        }

        if(node->next)
        {
            node->next->prev = node->prev;
        } 

        delete node;
        m_size--;
    }

private:
    struct Node
    {
        int val;
        Node* next;
        Node* prev;

        Node(int v = 0) 
            : prev(nullptr)
            , next(nullptr)
            , val(v)
        {}
    };

    Node* m_node;
    unsigned int m_size; 
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */