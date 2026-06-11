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
    int n, m;
    cin >> n >> m;
    map <int, int> d;
    for (int i = 0; i < 2 * m; ++i) {
        int x; cin >> x;
        ++d[x];
    }   
    string ans = "YES";
    for (auto e : d) {
        if (e.s % 2)
            ans = "NO";
    }    
    cout << ans << endl;
}   