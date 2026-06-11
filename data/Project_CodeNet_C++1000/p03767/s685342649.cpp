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

    ll m = 3 * n;
    vector<ll> arr(m);
    for (auto &i : arr)
        cin >> i;

    ll res = 0;
    sort(arr.rbegin(), arr.rend());
    for (ll i = 0, j = 1; i < n; i++, j += 2)
        res += arr[j];

    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll test_cnt = 1, case_no = 1;
    // cin >> test_cnt;
    while (case_no <= test_cnt)
        solve(case_no++);

    return 0;
}