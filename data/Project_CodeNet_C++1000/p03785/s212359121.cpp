#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(),t.end());

    ll cnt=0;
    ll pgr=0;
    while(pgr<n) {
        ll lim=t[pgr]+k;
        ll tmp=0;
        while(t[pgr+tmp]<=lim && tmp<c && pgr+tmp<n) tmp++;
        pgr+=tmp;
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}