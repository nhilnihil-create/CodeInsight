#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<ll> v(n+1), p(n+1);
    REP(i, n){
        ll a;
        cin >> a;
        v[i+1] = v[i] + a;
        p[i+1] = max(p[i], p[i] + a);
    }

    ll ans = 0;

    for(int i=1; i+k-1<=n; i++){
        ans = max(ans, p[n] - p[i+k-1] + p[i-1] + max(0LL, v[i+k-1] - v[i-1]));
    }

    cout << ans << endl;

    return 0;
}