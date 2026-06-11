#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for ( int i=0; i<n; i++ ) {
        cin >> v[i];
    }
    ll lb=0, ub=1e9;
    while ( ub-lb>1 ) {
        ll x=(lb+ub)/2;
        auto ok=[&] {
            ll cnt=0;
            for ( int i=0; i<n; i++ ) {
                cnt+=(max(0LL,v[i]-b*x)+a-b-1)/(a-b);
            }
            return cnt<=x;
        }();
        if ( ok ) {
            ub=x;
        } else {
            lb=x;
        }
    }   
    cout << ub << '\n';
    return 0;
}




 



