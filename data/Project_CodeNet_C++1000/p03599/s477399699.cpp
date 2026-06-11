#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

bool dp[32][3010];

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    dp[0][0] = true;


    for (ll mode = 0; mode < 4; mode++) {
        for (ll w = 0; w <= F / 100; w++) {
            for (ll s = 0; s <= F; s++) {
                if (100 * w + s > F) continue;
                if (w * E < s) continue;
                if (mode == 0) {
                    if (w - A >= 0)
                        dp[w][s] |= dp[w - A][s];
                }
                else if (mode == 1) {
                    if (w - B >= 0)
                        dp[w][s] |= dp[w - B][s];
                }
                else if (mode == 2) {
                    if (s - C >= 0)
                        dp[w][s] |= dp[w][s - C];
                }
                else {
                    if (s - D >= 0)
                        dp[w][s] |= dp[w][s - D];
                }
            }
        }
    }

    ll w_ans, s_ans;
    double mx = -1.0;
    for (ll w = 0; w <= F / 100; w++) {
        for (ll s = 0; s <= F; s++) {
            if (dp[w][s] == true) {
                double c = (double)s * 100.0 / (w * 100 + s);
                if (c > mx) {
                    w_ans = w;
                    s_ans = s;
                    mx = c;
                }
            }
        }
    }

    cout << w_ans * 100 + s_ans << " " << s_ans << endl;

    return 0;
}