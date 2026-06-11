#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;



void solve(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    rep(i, 0, n){
        if(a[a[i]-1] == i+1) ans++;
    }

    ans /= 2;
    cout << ans << "\n";
}


int main() {
    solve();
}
