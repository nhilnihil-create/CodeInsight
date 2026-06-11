#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;
    vector<long long> a(2 * n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }

    long long answer = a[0] * n + x * (n - 1);

    for (int c = 0; c < n; ++c)
    {
        long long cur = c * x;
        deque<int> s;

        for (int i = 0; i < 2 * n; ++i)
        {
            while (!s.empty() && a[s.back()] >= a[i])
            {
                s.pop_back();
            }

            s.push_back(i);

            if (s.front() == i - c - 1)
                s.pop_front();

            if (i >= n)
                cur += a[s.front()];
        }
        answer = min(answer, cur);
    }

    cout << answer << endl;

    return 0;
}