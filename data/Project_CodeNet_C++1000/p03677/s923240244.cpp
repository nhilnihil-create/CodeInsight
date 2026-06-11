#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5) + 7;

struct BIT {
    ll t[N];
    BIT() {fill(t, t + N, 0);}
    void Update(int x, int val) {for(; x < N; x += (x & -x)) t[x] += val;}
    ll Get(int x) {ll res = 0; for(; x > 0; x -= (x & -x)) res += t[x]; return res;}
} bit1, bit2;
int n, m, a[N];
ll sum, cur, x, res;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sum = 0;
    for(int i = 2; i <= n; ++i) {
        x = a[i];
        if(x < a[i - 1]) x += m;
        sum += x - a[i - 1];
        bit2.Update(a[i - 1] + 1, -a[i - 1]);
        bit2.Update(x + 1, a[i - 1]);
        bit1.Update(a[i - 1] + 1, 1);
        bit1.Update(x + 1, -1);
    }
    res = sum;
    for(int i = 1; i <= m; ++i) {
        x = bit1.Get(i);
        cur = sum - (x * i + bit2.Get(i)) + x;
        x = bit1.Get(i + m);
        cur = cur - (x * (i + m) + bit2.Get(i + m)) + x;
        res = min(res, cur);
    }
    cout << res;
}
