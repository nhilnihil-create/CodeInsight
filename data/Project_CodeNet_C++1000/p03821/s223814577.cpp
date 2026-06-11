#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << ": " << a << '\n'
#define endl '\n'

typedef long long ll;
const ll maxn = 200010;

void solve(ll case_no)
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    ll res = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        a[i] += res;
        if (a[i] % b[i])
            res += b[i] - a[i] % b[i];
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll test_cnt = 1, case_no = 1;
    // cin >> test_cnt;
    while (case_no <= test_cnt)
        solve(case_no++);

    return 0;
}