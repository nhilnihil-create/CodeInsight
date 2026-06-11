#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> a(3 * N);
    for (long long &aa : a)
    {
        cin >> aa;
    }

    vector<long long> dp(3 * N, 0);
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long sum = 0;
    for (size_t i = 0; i < 2 * N; i++)
    {
        sum += a[i];
        q.push(a[i]);
        if (q.size() > N)
        {
            sum -= q.top();
            q.pop();
        }
        dp[i] = sum;
    }

    vector<long long> ep(3 * N, 0);
    priority_queue<long long> qq;
    sum = 0;
    for (size_t i = 0; i < 2 * N; i++)
    {
        size_t j = a.size() - i - 1;
        sum += a[j];
        qq.push(a[j]);
        if (qq.size() > N)
        {
            sum -= qq.top();
            qq.pop();
        }
        ep[j] = sum;
    }

    long long ans = LONG_LONG_MIN;
    for (int i = N; i <= 2 * N; i++)
    {
        ans = max(ans, dp[i - 1] - ep[i]);
    }
    cout << ans << endl;
}
