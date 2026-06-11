#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 7;
const int N = 2e5 + 7;
int n;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    int ans = INF;
    int cur = 0;    
    for (int i = 0; i < n - 1; ++i) {
        cur += a[i];
        ans = min(ans, abs(cur - (sum - cur)));    
    }   
    cout<< ans << '\n';
}   