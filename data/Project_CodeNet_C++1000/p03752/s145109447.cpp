#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    long long ans = 1e12;
    if (K == 1)
    {
        cout << "0" << endl;
        return 0;
    }
    for (int bit = 0; bit < (1 << N - 1); bit++)
    {
        vector<long long> tmp = a;
        long long cost = 0;
        vector<int> v;
        for (int i = 0; i < N - 1; i++)
        {
            if (bit & (1 << i))
            {
                v.push_back(i + 1);
            }
        }
        if (v.size() >= K - 1)
        {
            for (int i = 0; i < v.size(); i++)
            {
                long long max_h = 0;
                for (int j = 0; j < v[i]; j++)
                {
                    max_h = max(max_h, tmp[j]);
                }
                cost += max(0LL, max_h - tmp[v[i]] + 1);
                tmp[v[i]] += max(0LL, max_h - tmp[v[i]] + 1);
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}