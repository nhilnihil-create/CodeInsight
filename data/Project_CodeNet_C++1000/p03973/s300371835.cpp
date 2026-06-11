#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n;
ll a[1 << 18];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}


void solve() {
    ll ans = a[0] - 1;
    ll mask = 2;
    for (int i = 1; i < n; i++) {
        if (a[i] == mask) mask++;
        else ans += (a[i] - 1) / mask;
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
