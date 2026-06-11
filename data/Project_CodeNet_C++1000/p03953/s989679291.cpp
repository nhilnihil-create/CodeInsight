#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, x[N], m, k, p[N], d[N], resp[N];
int ans[N];
void mult(int p[], int add[]) {
    for (int i = 1; i < n; ++i) ans[i] = p[add[i]];
    for (int i = 1; i < n; ++i) p[i] = ans[i];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];    
    for (int i = 1; i < n; ++i) d[i] = x[i + 1] - x[i];
    cin >> m >> k;
    for (int i = 1; i < n; ++i) p[i] = i;
    while (m--) {
        int i; cin >> i;
        swap(p[i - 1], p[i]);
    }   
    for (int i = 1; i < n; ++i) resp[i] = i;
    for (int pw = 0; (1ll << pw) <= k; ++pw) {
        if ((k >> pw) & 1) mult(resp, p);
        mult(p, p);
    }   
    mult(d, resp);
    ans[1] = x[1];
    for (int i = 1; i < n; ++i) {
        ans[i + 1] = ans[i] + d[i];
    }   
    for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}