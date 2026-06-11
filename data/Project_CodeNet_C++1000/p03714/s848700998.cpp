#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{

    // I/O
    int N;
    cin >> N;
    vector<long long> a(3 * N);
    for (int i = 0; i < 3 * N; i++)
        cin >> a[i];

    // 累積和を取る
    vector<long long> S(2 * N + 1, 0);
    priority_queue<long long, vector<long long>, greater<long long>> qs;
    for (int i = 0; i < N; i++)
    {
        S[i + 1] = S[i] + a[i];
        qs.push(a[i]);
    }
    for (int i = N; i < 2 * N; i++)
    {
        long long e1 = qs.top();
        if (a[i] > e1)
        {
            S[i + 1] = S[i] - e1 + a[i];
            qs.pop();
            qs.push(a[i]);
        }
        else
        {
            S[i + 1] = S[i];
        }
    }

    vector<long long> T(2 * N + 1, 0);
    priority_queue<long long> qt;
    for (int i = 0; i < N; i++)
    {
        T[i + 1] = T[i] + a[3 * N - 1 - i];
        qt.push(a[3 * N - 1 - i]);
    }
    for (int i = N; i < 2 * N; i++)
    {
        long long e2 = qt.top();
        if (a[3 * N - 1 - i] < e2)
        {
            T[i + 1] = T[i] - e2 + a[3 * N - 1 - i];
            qt.pop();
            qt.push(a[3 * N - 1 - i]);
        }
        else
        {
            T[i + 1] = T[i];
        }
    }

    long long ans = -(1LL << 60);
    for (int i = N; i <= 2 * N; i++)
    {
        ans = max(ans, S[i] - T[3 * N - i]);
    }
    cout << ans << endl;

    return 0;
}