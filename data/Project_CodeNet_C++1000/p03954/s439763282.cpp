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
const int N = 2e5 + 7;
int n, a[N];
bool aa[N];
bool get(int m) {
    for (int i = 0; i < 2 * n - 1; ++i) aa[i] = a[i] >= m;
    ii ans = {2 * N, -1};
    for (int i = n - 1; i; --i) {
        if (aa[i - 1] == aa[i]) ans = min(ans, mp(n - 1 - i, (int)aa[i]));
    }   
    for (int i = n - 1; i + 1 < 2 * n - 1; ++i) {
        if (aa[i + 1] == aa[i]) ans = min(ans, mp(i - n + 1, (int)aa[i]));
    }   
    if (ans.s != -1) return ans.s;
    return aa[n - 1] ^ ((n - 1) & 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < 2 * n - 1; ++i) cin >> a[i];
    int l = 0, r = 2 * N;    
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (get(m)) l = m;
        else r = m;
    }   
    cout << l << '\n';
}