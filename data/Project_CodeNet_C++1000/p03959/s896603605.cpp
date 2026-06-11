#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const ll MAX_N = ll(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

ll n, a[MAX_N], t[MAX_N], ans = 1;
bool f[2][MAX_N]{};  // 値がわかっているか

int main() {
    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> t[i];
    f[0][0] = true;
    f[1][n-1] = true;
    REP(i,n-1){
        if(a[i] < a[i+1]) f[0][i+1] = true;
    }
    REP(i,n-1){
        if(t[i] > t[i+1]) f[1][i] = true;
    }
    REP(i,n){
        if(f[0][i] && f[1][i]){
            if(a[i] != t[i]) ans = 0;
        }
        else if(f[0][i]){
            if(a[i] > t[i]) ans = 0;
        }
        else if(f[1][i]){
            if(a[i] < t[i]) ans = 0;
        }
        else {
            ans *= min(a[i], t[i]);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
