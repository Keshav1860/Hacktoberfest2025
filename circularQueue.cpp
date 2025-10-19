class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        cnt = 0;
        sz = k;
        headIdx = 0;
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;
        q[(headIdx + cnt) % sz] = value;
        cnt++;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty()) return false;
        headIdx = (headIdx +1)%sz;
        cnt--;
        return true;
    }
    
    int Front() 
    {
        if(isEmpty()) return -1;
        return q[headIdx];    
    }
    
    int Rear() 
    {
        if(isEmpty()) return -1;
        return q[(headIdx + cnt - 1) % sz];
    }
    
    bool isEmpty() 
    {
        // no element in the queue
        return cnt == 0;
    }
    
    bool isFull() 
    {
        // return true if the count is equal to the queue size
        // else return false
        return cnt == sz;   
    }
private:
    int cnt, sz, headIdx;
    vector<int>q;
};
