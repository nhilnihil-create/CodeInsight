#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int A, B, X;

    cin >> A >> B >> X;

    int ans;
    if (A == 0) {
        ans = (B / X) + 1;
    } else {
        ans = (B / X) - (A-1) / X;
    }
    cout << ans << endl;

}
