#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), acc(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    rep(i, 0, n) acc[i+1] = acc[i] + a[i];
    rep(i, 0, n+1) cerr << acc[i] << endl;
    ll ans = 1;
    for(ll i = n-1; i > 0; i--) {
        cerr << a[i] << " " << acc[i] << endl;
        if( a[i] <= 2 * (acc[i]) ) ans++; 
        else break;
    }
    cout << ans << endl;
    return 0;
}