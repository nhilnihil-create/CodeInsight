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
const int C = 26;
int cnt[C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else                         
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s; cin >> s;
    for (char c : s) ++cnt[c - 'a'];
    int ans = 1;
    for (int i = 0; i < C; ++i) for (int j = i + 1; j < C; ++j) ans += cnt[i] * cnt[j];
    cout << ans << '\n';
}   