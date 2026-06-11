#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    string a;
    cin >> a;
    ll n = a.size();
    map<ll, ll> x;

    rep(i, 0, a.size()){
        x[a[i]]++;
    }

    ll ans = n * (n - 1) / 2.0 + 1;
    fore(t, x){
        ll tmp = t.second * (t.second - 1) / 2;
        ans -= tmp;
    }

    cout << ans << endl;
    return 0;
}
