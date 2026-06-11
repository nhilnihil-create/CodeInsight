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

ll a[100010], t[100010], m[100010];

void fail(){
    cout << 0 << endl;
    exit(0);
}

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];

    if (a[0] != t[n-1]) fail();

    m[0] = t[0];
    m[n-1] = a[n-1];

    rep(i, n-1) {
        if (t[i] < t[i+1]) {
            if (m[i+1] > 0 && m[i+1] != t[i+1]) fail();
            if (a[i+1] < t[i+1]) fail();
            m[i+1] = t[i+1];
        }
    }
    for(int i = n-1; i > 0; i--) {
        if (a[i] < a[i-1]) {
            if (m[i-1] > 0 && m[i-1] != a[i-1]) fail();
            if (a[i-1] > t[i-1]) fail();
            m[i-1] = a[i-1];
        }
    }


    ll ans = 1;

    rep(i, n){
        if (m[i] == 0){
            ans *= min(a[i], t[i]);
            ans %= MOD;
        }
    }

    cout << ans << endl;
    
    return 0;
}
