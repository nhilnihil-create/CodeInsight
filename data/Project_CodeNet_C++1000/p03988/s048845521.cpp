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
void ban() {
    cout << "Impossible" << endl;
    exit(0);
}
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
    map <int, int> cnt;
    int diam = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        diam = max(diam, a[i]);
        ++cnt[a[i]];
    }
    int mn = 1e18;
    for (int e : a) 
        mn = min(mn, e);

    if (diam % 2 == 0) {
        if (mn != diam/2)
            ban();
        if (cnt[mn] != 1)
            ban();
    }
    else {
        if (mn != (diam+1)/2)
            ban();
        if (cnt[mn] != 2)
            ban();
    }   
    
    for (int i = mn + 1; i <= diam; ++i) {
        if (cnt[i] < 2) 
            ban();
    }   
    cout << "Possible" << endl;
}