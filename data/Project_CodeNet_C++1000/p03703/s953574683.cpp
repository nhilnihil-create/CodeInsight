#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define x           first
#define y           second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5) + 7;
const int mod = int(1e9) + 7;

ll a[N], k, res;
vector<ll> v;
int t[N], n;

void Update(int x, int val) {for(; x < N; x += (x & -x)) t[x] += val;}
int Get(int x) {int res = 0; for(; x > 0; x -= (x & -x)) res += t[x]; return res;}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; a[i] -= k;
        a[i] += a[i - 1]; v.pb(a[i]);
    }
    v.pb(0); sort(v.begin(), v.end());
    Update(lower_bound(v.begin(), v.end(), 0) - v.begin() + 1, 1);
    for(int i = 1; i <= n; ++i) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        res += Get(a[i]);
        Update(a[i], 1);
    }
    cout << res;
}
