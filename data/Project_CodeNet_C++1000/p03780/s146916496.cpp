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

ll a[5050];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    ll t = 0, cnt = 0, ans = n;
    
    rrep(i, n){
        if (t + a[i] < k) t += a[i];
        else ans = i;
    }

    cout << ans << endl;
    return 0;
}
