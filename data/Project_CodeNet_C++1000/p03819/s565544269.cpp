#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
 
using namespace std;
 
const int N = int(3e5) + 7;
const int mod = int(1e9) + 7;
typedef pair<int, int> pii;
 
int n, m, res, l[N], r[N], t[N], remain;
vector<int> dis[N];
 
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
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        dis[r[i] - l[i] + 1].pb(i);
    }
    remain = n;
    for(int i = 1; i <= m; ++i) {
       for(int j: dis[i - 1]) Update(l[j], 1), Update(r[j] + 1, -1);
       remain -= int(dis[i - 1].size()); res = remain;
       if(i != 1) for(int j = i; j <= m; j += i) res += Get(j);
       cout << res << '\n';
    }
}