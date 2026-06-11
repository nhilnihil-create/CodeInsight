#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    ll x;
    cin >> N >> x;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll ans = INF, b[N];
    fill(b, b+N, INF);
    //魔法をi回書ける場合を考える
    rep(i, N){
        rep(j, N){
            b[j] = min(b[j], a[(j+N-i)%N]);
        }
        ll tmp = x*i;
        rep(j, N){
            tmp += b[j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}