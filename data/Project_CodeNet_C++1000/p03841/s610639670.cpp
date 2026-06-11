#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> res(N * N, 0), x(N * N);
    vector<P> a, b;
    for (int i = 1; i <= N; i++)
    {
        cin >> x[i];
        x[i]--;
        a.push_back(P(x[i], i));
        b.push_back(P(x[i], i));
        res[x[i]] = i;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        // q を q - 1 個
        int q = a[i].second;
        for (int j = 0; j < q - 1; j++)
        {
            while (res[idx])
            {
                idx++;
            }
            res[idx] = q;
            idx++;
        }
    }
    idx = N * N - 1;
    for (int i = 0; i < N; i++)
    {
        // q を N - q 個
        int q = b[i].second;
        for (int j = 0; j < N - q; j++)
        {
            while (res[idx])
            {
                idx--;
            }
            res[idx] = q;
            idx--;
        }
    }
    bool f = true;
    // 1 <= i <= N に対し, x_i までに i が i 個
    vector<int> sum(N + 1, 0);
    idx = 0;
    for (int i = 0; i < N; i++)
    {
        int p = a[i].first, q = a[i].second;
        while (idx <= p)
        {
            sum[res[idx]]++;
            idx++;
        }
        if (sum[q] != q)
            f = false;
    }
    if (!f)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N * N; i++)
    {
        if (i == 0)
            cout << res[i];
        else
            cout << " " << res[i];
    }
    cout << endl;
}
