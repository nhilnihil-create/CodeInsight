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


ll t[100010];
int main(){
    ll n, c, k;
    cin >> n >> c >> k;
    rep(i, n) cin >> t[i];

    sort(t, t + n);

    ll cnt = 0;
    ll head = t[0];
    ll ans = 1;
    int i = 0;
    while(i < n){
        if (head + k >= t[i] && cnt < c){
            cnt++;
            i++;
        }
        else if (head + k < t[i] || cnt >= c){
            ans ++;
            cnt = 1;
            head = t[i];
            i++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
