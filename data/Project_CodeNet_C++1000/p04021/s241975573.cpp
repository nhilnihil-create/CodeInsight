#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < int(n); i++)
#define all(in) in.begin(),in.end()

using ll = long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n){ cin >> a[i]; b[i] = a[i]; }
    sort(all(b));
    ll count = 0;
    rep(i,n){
        ll k = lower_bound(all(b),a[i]) - b.begin();
        if((k-i)%2 != 0) count++;
    }
    cout << count/2 << endl;
}