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

ll a[100010];  
ll d[100010];  

int main(){
    ll n;
    cin >> n;
    ll tot = 0;
    rep(i, n) {
        cin >> a[i];
        tot += a[i];
    }
    if (tot % (n*(n+1)/2) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    ll k = tot / (n*(n+1)/2);

    rep(i, n-1) {
        d[i] = a[i+1] - a[i];
        d[i] -= k;
    }
    d[n-1] = a[0] - a[n-1];
    d[n-1] -= k;

    bool f = 1;
    ll tmp = k;
    rep(i, n) f &= (abs(d[i])%n == 0), tmp -= abs(d[i])/n;
    f &= (tmp == 0);


    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
