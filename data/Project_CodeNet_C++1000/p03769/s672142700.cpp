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
vector <int> get(int n) {
    if (n == 1) return {};
    if (n & 1) {
        auto t = get(n - 1);
        t.insert(t.begin(), (int)t.size() + 1);
        return t;
    }   
    else {
        auto t = get(n >> 1);
        t.app((int)t.size() + 1);
        return t;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> ans = get(n + 1);
    cout << ans.size() * 2 << '\n';
    for (int e : ans) cout << e << ' ';
    for (int i = 1; i <= ans.size(); ++i) cout << i << ' ';
    cout << '\n';
}