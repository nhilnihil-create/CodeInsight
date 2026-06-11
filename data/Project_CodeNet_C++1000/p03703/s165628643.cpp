#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e5 + 10;
const int oo = 1e18;
const int mod = 1e9 + 7;

int n, k;
int a[N], BIT[N];
map<int, int> mp;

void upd(int pos, int val)  {
    for(int i = pos; i < N; i += (i & (-i)))
        BIT[i] += val;
}
int get(int pos)    {
    int res = 0;
    for(int i = pos; i > 0; i -= (i & (-i)))
        res += BIT[i];
    return res;
}

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);

    cin >> n >> k;
    vector<int> tmp; tmp.pb(0);
    FOR(i, 1, n) cin >> a[i], a[i] = (a[i] - k + a[i - 1]), tmp.pb(a[i]);
    sort(tmp.begin(), tmp.end());
    int cnt = 0;
    FOR(i, 0, tmp.size() - 1) if(i == tmp.size() - 1 || tmp[i] < tmp[i + 1])
        mp[ tmp[i] ] = ++cnt;

    int ans = 0; upd(mp[0], 1);
    FOR(i, 1, n)    {
        ans += get(mp[ a[i] ]);
        upd(mp[a[i]], 1);
    }

    return cout << ans, 0;
}
