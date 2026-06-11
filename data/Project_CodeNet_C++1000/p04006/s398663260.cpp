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
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    vector <int> cur = a;
    int ans = 1e18;
    for (int sh = 0; sh < n; ++sh) {
        int nn = sh * x;
        for (int i = 0; i < n; ++i) {
            cur[i] = min(cur[i], a[(i - sh + n) % n]);
            nn += cur[i];
        }   
        ans = min(ans, nn);
    }   
    cout << ans << endl;
}