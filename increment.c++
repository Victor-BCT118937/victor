#include <stdio.h>
using namespace std;

class CustomStack {
private:
    vector<int> stack;
    vector<int> inc;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if (stack.empty()) return -1;
        int i = stack.size() - 1;
        if (i > 0) inc[i-1] += inc[i];
        int res = stack[i] + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if (i >= 0) inc[i] += val;
    }
};


int main() {
    CustomStack st(5);
    st.push(1);
    st.push(2);
    cout << st.pop() << endl; 
    st.push(2);
    st.push(3);
    st.push(4);
    st.increment(5, 100);
    st.increment(2, 100);
    cout << st.pop() << endl; 
    cout << st.pop() << endl; 
    return 0;
}
