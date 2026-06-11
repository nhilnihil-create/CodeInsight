#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll lim = 1e5;
    vector<ll> d(lim,0);
    rep(i, n){
        ll x; cin >> x;
        d[x]++ ;
    }
    ll ans = 0;
    rep(i,lim){
        ans = max(ans, d[i]+d[i+1]+d[i+2]);
    }
    cout << ans << endl;

}