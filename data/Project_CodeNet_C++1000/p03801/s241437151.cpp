#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define ld          long double
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
typedef pair<int, int> pii;

int a[N], n, Max;
ll res, sum;
set<int> s;
vector<int> v;

struct BIT {
   ll t[N];
   void Update(int x, int val) {for(; x > 0; x -= (x & -x)) t[x] += val;}
   ll Get(int x) {ll res = 0; for(x = max(x, 1); x < N; x += (x & -x)) res += t[x]; return res;}
} bit1, bit2;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], v.pb(a[i]);
    sort(v.begin(), v.end());
    for(int i = n; i >= 1; --i) {
        sum += a[i];
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        bit1.Update(a[i], 1); bit2.Update(a[i], v[a[i] - 1]);
    }
    for(int i = 1; i <= n; ++i) {
        if(Max >= a[i]) cout << "0\n";
        else {
            s.insert(a[i]); res = 0;
            auto p = s.lower_bound(a[i]);
            int x;
            if(p == s.begin()) x = 0;
            else p = prev(p), x = (*p);
            int upper = bit1.Get(a[i]);
            res += 1ll * v[a[i] - 1] * upper;
            res += bit2.Get(x + 1) - bit2.Get(a[i]);
            if(x) {
                res -= 1ll * (bit1.Get(x + 1) - bit1.Get(a[i])) * v[x - 1];
                res -= 1ll * v[x - 1] * upper;
            }
            cout << res << '\n';
            Max = a[i];
        }
        sum -= a[i]; bit1.Update(a[i], -1); bit2.Update(a[i], -v[a[i] - 1]);
    }
}
