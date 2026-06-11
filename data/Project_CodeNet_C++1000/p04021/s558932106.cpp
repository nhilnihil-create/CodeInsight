#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }
    map<ll, ll> v2i;
    REP(i, n){
        v2i[a.at(i)] = i;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(ll i = 0; i < a.size(); i += 2){
        ans += (v2i.at(a.at(i)) % 2 != 0);
    }
    cout << ans << endl;
    return 0;
}
