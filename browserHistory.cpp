class BrowserHistory {
public:
class Node{
public:
    Node* prev;
    Node* next;
    string val;
    Node(string val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};
Node* head;
Node* tail;
Node* curr;
    BrowserHistory(string homepage) 
    {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;

        Node* h = new Node(homepage);
        head->next = h;
        h->prev = head;
        h->next = tail;
        tail->prev = h;
        curr = h;
    }
    
    void visit(string url) 
    {
        Node* t = new Node(url);
        curr->next = t;
        t->prev = curr;
        t->next = tail;
        tail->prev = t;
        curr = t;
    }
    
    string back(int steps) 
    {
        while(curr->prev != head && steps > 0)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) 
    {
        while(curr->next != tail && steps > 0)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};
