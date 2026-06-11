#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0;
    for(int i = 0; i < k; i++)ans += a[i];
    cout << ans << '\n';
    return 0;
}
// Write Here
