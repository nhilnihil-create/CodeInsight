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
    int n, k;
    cin >> n >> k;

    vector <int> pref(n + 1), pos_pref(n + 1), pos_post(n + 1);
    vector <int> a(n);
    for (int i = 0; i < n;++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
        pos_pref[i + 1] = pos_pref[i] + max(0ll, a[i]);
    }                                        
    for (int i = n - 1; i >= 0; --i)
        pos_post[i] = pos_post[i + 1] + max(0ll, a[i]);
    int ans = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
        ans = max(ans, pos_pref[i] + pos_post[i + k] + max(0ll, pref[i + k] - pref[i]));
    }   
    cout << ans << endl;
}