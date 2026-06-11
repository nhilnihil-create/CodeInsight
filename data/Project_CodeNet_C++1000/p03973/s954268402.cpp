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

// ref : https://kmjp.hatenablog.jp/entry/2016/10/10/0930

ll a[100010];
int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    int p = 0;
    ll ans = 0;

    rep(i, n){
        if (i == 0){
            ans += a[i] - 1;
            p = 1;
        }
        else if (a[i] == p + 1){
            p++;
        }
        else {
            ans += (a[i] - 1) / (p + 1);
        }
    }

    cout << ans << endl;
    return 0;
}
