#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF (1<<18)



int main() {
    ll n;
    cin>>n;

    ll ans = 1;
    rep2(i,1,n+1){
        ans *= i;
        if(ans > 100000007) ans %= 1000000007;
    }

    cout << ans << endl;

    return 0;
}