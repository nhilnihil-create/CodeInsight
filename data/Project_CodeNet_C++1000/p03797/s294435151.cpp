#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    if(2*n > m){
        cout << m/2 << endl;
    }else{
        ll ans = n;
        m -= 2*n;
        ans += m/4;
        cout << ans << endl;
    }

    return 0;
}