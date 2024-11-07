
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
    } else {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }
}

void reverseStack(stack<int> &st) {
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, x);
    }
}

int main() {
    stack<int> st;
    st.push(28);
    st.push(29);
    st.push(30);
    st.push(31);

    reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
