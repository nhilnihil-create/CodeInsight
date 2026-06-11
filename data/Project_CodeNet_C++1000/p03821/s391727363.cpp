#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }   
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        a[i] += ans;
        int w = (a[i] + b[i] - 1) / b[i] * b[i] - a[i];
        ans += w;
    }   
    cout << ans << endl;
}