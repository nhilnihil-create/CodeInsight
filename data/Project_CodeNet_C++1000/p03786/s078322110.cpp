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
    vector <int> a(n), pref(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    sort(all(a));
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    int p = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        p += a[i];
        int cur = p;
        int r = i;       
        while (1) {
            int cant = upper_bound(all(a), 2 * cur) - a.begin();
            if (cant == r + 1) {
                break;
            }   
            cur += pref[cant] - pref[r + 1];
            r = cant - 1;
        }

        //cout << i << ' ' << r << endl;

        ans += r == n - 1;
    }   
    cout << ans << endl;
}