
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int halfSize = q.size() / 2;
    queue<int> firstHalf;

    for (int i = 0; i < halfSize; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    interleaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
