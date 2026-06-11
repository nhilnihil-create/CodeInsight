#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    long long n, m = 1LL << 40;
    cin >> n; ++n;
    while (n < m)
    m >>= 1;
    deque<int> que;
    // que.push_back(1);
    m >>= 1;
    int i = 0;
    while (m)
    {
        que.push_back(++i);
        if (n & m)
            que.push_front(++i);
        else
        ;
            // que.push_front(++i);
        m >>= 1;
    }
    cout << 2 * i << endl;
    for (auto i : que)
    cout << i << ' ';
    for (int j = 1; j <= i; ++j)
    cout << j << ' ';
    cout << endl;
    return 0;
}