
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main()
{
    vector<int> arr = {4, 5, 2, 25};
    nextGreaterElement(arr);
    return 0;
}
