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
    int n;
    cin >> n;
    int n2 = 0;
    int n4 = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a % 4 == 0) ++n4;
        else if (a % 2 == 0) ++n2;
    }

    int odd = n - n4 - n2;
    if (n2 == 0) {
        if (odd <= n4 + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        if (odd <= n4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}