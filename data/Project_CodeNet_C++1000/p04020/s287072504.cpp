#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n - 1){
        ans += a[i] / 2;
        if (a[i] % 2 == 1 && a[i+1] > 0){
            ans++;
            a[i+1]--;
        }
    }
    ans += a[n-1] / 2;
    cout << ans << endl;
    return 0;
}