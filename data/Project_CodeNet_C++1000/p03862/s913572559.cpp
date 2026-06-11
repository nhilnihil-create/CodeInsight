#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int N, X;

    cin >> N >> X;

    vector<int> As(N);
    REP(i, N) {
        cin >> As.at(i);
    }

    // 見ながらキャンディーを食べていく
    int ans = 0;

    int prev = As.at(0);
    FORE(i, 1, N-1) {
        const int current = As.at(i);

        if ((current + prev) > X) {
            const int eaten = (current + prev - X);
            // cout << "eat at " << i << " " << eaten << endl;
            ans += eaten;

            if (current >= eaten) {
                prev = current - eaten;
            } else {
                // 次のprevは食べきったのでゼロ
                // 個数については以前のどこかで帳尻合わせられると思う
                prev = 0;
            }

            debug(i);
            debug(current);
            debug(eaten);
            debug(prev);
            hyphen();
        } else {
            prev = current;
        }
    }

    debug(ans);
    cout << ans << endl;
}
