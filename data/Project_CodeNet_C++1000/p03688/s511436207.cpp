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
    vector <int> a(n);
    const int INF = 1e18 + 7;
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }   
    if (mn < mx - 1) {
        cout << "No" << endl;
        return 0;
    }   

    if (mn == mx) {

        if (mn == n - 1) {
            cout << "Yes" << endl;
            exit(0);
        }   

        if (mn * 2 > n) {
            cout << "No" << endl;
        }   
        else {
            cout << "Yes" << endl;
        }   
        return 0;
    }

    int cnt_mx = 0;
    for (int i = 0; i < n; ++i)
        cnt_mx += a[i] == mx;

    int cnt_mn = 0;
    for (int i = 0; i < n; ++i)
        cnt_mn += a[i] == mn;
    
    if (cnt_mn >= mx) {
        cout << "No" << endl;
        return 0;
    }   

    int r = mx - cnt_mn;
    if (r * 2 > cnt_mx) {
        cout << "No" << endl;
        return 0;
    }   

    cout << "Yes" << endl;
}