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
const int N = 301;
int ptr[N], a[N][N], n, m, cnt[N];
bool ban[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    int ans = N;
    for (int t = 0; t < m; ++t) {
        for (int i = 0; i < N; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) ++cnt[a[i][ptr[i]]];
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            if (cnt[i] > cnt[mx]) mx = i;
        }   
        ans = min(ans, cnt[mx]);
        ban[mx] = 1;
        for (int i = 0; i < n; ++i) {
            while (ptr[i] < m && ban[a[i][ptr[i]]]) ++ptr[i];
        }
    }   
    cout << ans << '\n';
}   
