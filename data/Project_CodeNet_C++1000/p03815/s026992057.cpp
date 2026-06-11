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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll x;
    cin >> x;

    ll res;
    if (x % 11 > 6) {
        res = 2* (x / 11) + 2;
    }
    else if (x % 11 == 0){
        res = 2 * (x / 11);
    }
    else {
        res = 2 * (x / 11) + 1;
    }

    cout << res << endl;

    return 0;
}