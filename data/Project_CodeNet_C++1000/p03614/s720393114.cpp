#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define all(v) v.begin(), v.end()
#define reps(__i, a, b) for (int __i = a; i < b; i++)
#define rep(__i, n) reps(__i, 0, n)

const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;

signed main()
{
    int n;
    int p[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = i; j <= n; j++)
        {
            if (p[j] != j)
            {
                i = j;
                break;
            }
            else
            {
                // cout << "=" << j << endl;
                i = j;
                tmp++;
            }
        }
        if (tmp != 0)
            v.push_back(tmp);
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << endl;
        sum += max(1LL, (v[i] + 1) / 2);
    }
    cout << sum << endl;
}