#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[2005];
ll dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n, x;
    cin >> n >> x;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    ll mn = 1000000000000000000LL;
    for(ll k=0; k<=n-1; k++){
        ll sum = 0;
        for(int i=1; i<=n; i++){
            if(k == 0) dp[k][i] = niz[i];
            else dp[k][i] = min(niz[i], dp[k-1][i-1]);
            sum += dp[k][i];
        }
        dp[k][0] = dp[k][n];
        mn = min(mn, sum+k*x);
    }
    cout << mn;
    return 0;
}
