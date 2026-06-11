#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> A[i][j];
    set<int> se;
    for(int i = 1; i <= M; i++) {
        se.insert(i);
    }
    int res = INF;
    vector<int> cur(N, 0);
    rep(i, M) {
        vector<int> cnt(M);
        rep(j, N) { cnt[A[j][cur[j]] - 1]++; }
        int tmp = 0;
        int most = 0;
        rep(j, M) {
            if(tmp < cnt[j]) {
                most = j;
                tmp = cnt[j];
            }
        }
        res = min(res, tmp);
        se.erase(most + 1);
        rep(j, N) {
            if(se.empty())
                break;
            while(!se.count(A[j][cur[j]]))
                cur[j]++;
        }
    }
    cout << res << endl;

    return 0;
}