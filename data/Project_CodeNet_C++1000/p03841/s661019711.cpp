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
const int N = 501;
int ans[N * N];
ii a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif         
    for (int i = 0; i < N * N; ++i) ans[i] = -1;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f; a[i].s = i;
        --a[i].f; ans[a[i].f] = i + 1;
    }   
    sort(a, a + n);
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].s; ++j) {
            while (ans[ptr] != -1) ++ptr;
            if (ptr > a[i].f) {
                cout << "No\n";
                exit(0);
            }
            ans[ptr] = a[i].s + 1;
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - a[i].s - 1; ++j) {
            while (ans[ptr] != -1) ++ptr;
            if (ptr < a[i].f) {
                cout << "No\n";
                exit(0);
            }
            ans[ptr] = a[i].s + 1;
        }   
    }   
    cout << "Yes\n";
    for (int i = 0; i < n * n; ++i) cout << ans[i] << ' '; cout << '\n';    
}