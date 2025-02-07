
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        if (i >= k - 1)
        {
            if (!dq.empty())
            {
                result.push_back(arr[dq.front()]);
                if (dq.front() <= i - k + 1)
                {
                    dq.pop_front();
                }
            }
            else
            {
                result.push_back(0);
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> result = firstNegativeInWindow(arr, k);

    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}
