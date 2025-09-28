#include <stdio.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, count, size;
public:
    MyCircularQueue(int k) {
        size = k;
        q.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

// Example usage
int main() {
    MyCircularQueue cq(3);
    cout << cq.enQueue(1) << endl; // true
    cout << cq.enQueue(2) << endl; // true
    cout << cq.enQueue(3) << endl; // true
    cout << cq.enQueue(4) << endl; // false
    cout << cq.Rear() << endl;     // 3
    cout << cq.isFull() << endl;   // true
    cout << cq.deQueue() << endl;  // true
    cout << cq.enQueue(4) << endl; // true
    cout << cq.Rear() << endl;     // 4
    return 0;
}
