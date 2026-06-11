#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    vector<int> b = a;
    REP(i, n) {
        if (b[i] > x) b[i] = x;
    }

    REP(i, n-1) {
        if (b[i] + b[i+1] > x) {
            int tmp = (b[i]+b[i+1]) - x;
            if (b[i+1] > tmp) b[i+1] -= tmp;
            else {
                b[i] -= tmp - b[i+1];
                b[i+1] = 0;
            }
        }
    }

    ll ans = 0;
    REP(i, n) {
        ans += a[i] - b[i];
    }

    cout << ans << endl;
    

    return 0;
}