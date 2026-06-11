#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

typedef long long ll;

template <class T>
T GetCeil(T a, T b) { T ans = a / b; if (a % b) ++ans; return ans; }

signed main()
{
    int n; cin >> n;
    vector<int> t(n),a(n); rep(i,n) cin >> t[i] >> a[i];

    ll lastT = t[0], lastA = a[0];

    if (n == 1) {cout << lastT + lastA << endl; return 0;}

    rep(i,n-1){
        ll timesT = GetCeil(lastT, (ll)(t[i+1]));
        ll timesA = GetCeil(lastA, (ll)(a[i+1]));
        ll times = max(timesT,timesA);
        lastT = t[i+1]*times;
        lastA = a[i+1]*times;
    }

    cout << lastT + lastA << endl;    

    return 0;
}
