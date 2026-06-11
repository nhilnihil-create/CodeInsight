#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <bitset>
#include <functional>

using namespace std;
using lint = long long;
using pii = pair<int, int>;
using vec = vector<int>;
using pq = priority_queue<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n); i > 0; i--)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); it++)
#define mp(x, y) make_pair((x), (y))
#define space " "

constexpr lint MOD = 1e9 + 7;
constexpr int INF = 1<<(int)29;
int A, B, C, F, H, I, J, K, L, M, N, P, Q, R, S, T, U, V, W, X, Y;
// lint A, B, C, F, H, I, J, K, L, M, N, P, Q, R, S, T, U, V, W, X, Y;
int ans = INF;
// string ans;
vector<vec> d;
vec r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> R;
    r.resize(R);
	rep(i, R) {
        cin >> r[i];
        r[i]--;
	}
    sort(all(r));

    d.assign(N, vec(N, INF));
    rep(i, M) {
        cin >> A >> B >> C;
        A--; B--;
        if (d[A][B] > C) {
            d[A][B] = d[B][A] = C;
        }
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
	
	do {
        int rst = 0;
        rep(i, R - 1) {
            rst += d[r[i]][r[i+1]];
        }
        ans = min(ans, rst);
    } while (next_permutation(all(r)));

	cout << ans << endl;
	return 0;
}