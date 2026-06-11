#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() cin.tie(0), ios::sync_with_stdio(false)

ll N, ans;

int main()
{
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll mi = 0;

    for (int i = 0; i < N; i++)
    {
        ll p = (a[i] - 1) / (mi + 1);
        ans += p;
        a[i] -= p * (mi + 1);

        if (p > 0)
        {
            a[i] = 1;
        }

        if (a[i] < mi + 2)
        {
            mi = max(mi, a[i]);
        }
    }

    cout << ans << endl;
}