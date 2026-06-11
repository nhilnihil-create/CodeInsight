#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n, l; cin >> n >> l;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    bool check = false;
    ll ans;
    rep(i,n-1) if(a[i]+a[i+1] >= l) { check = true; ans = i; break; }
    if(!check){ cout << "Impossible" << endl; return 0; }

    cout << "Possible" << endl;
    loop(i,0,ans) cout << i+1 << endl;
    loop(i,1,n-ans) cout << n-i << endl;
    return 0;
}

