#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

static const ll mod = 1e9+7;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string S[2];
    rep(i, 2) cin >> S[i];

    ll res = 1;
    int x = 0;
    int pre = -1;

    while(x < n) {
        if (S[0][x] == S[1][x]) {
            if (pre < 0) res = 3;
            else if (pre == 0) res *= 2;
            else res *= 1;
            ++x;
            pre = 0;
        }
        else {
            if (pre < 0) res = 6;
            else if (pre == 0) res *= 2;
            else res *= 3;
            x += 2;
            pre = 1;
        }
        res %= mod;
    }

    cout << res << endl;

    return 0;
}