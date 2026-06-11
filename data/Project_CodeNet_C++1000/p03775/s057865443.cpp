#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int digitsum(ll x){
    return (int)to_string(x).size();
}

int main(){
    ll n;
    cin >> n;
    int ans = 10;

    for(int i = 1; i <= 100010; i++){
        if (n%i != 0) continue;
        ans = min(ans, max(digitsum(n/i), digitsum(i)));
    }
    cout << ans << endl;
    return 0;
}
