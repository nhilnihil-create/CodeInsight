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
    vector<int> A(N), B(N), C(M), D(M);
    rep(i, N) { cin >> A[i] >> B[i]; }
    rep(i, M) { cin >> C[i] >> D[i]; }
    vector<int> res(N);
    rep(i, N) {
        int mi = INF;
        for(int j = M - 1; j >= 0; j--) {
            if(abs(A[i] - C[j]) + abs(B[i] - D[j]) <= mi) {
                mi = abs(A[i] - C[j]) + abs(B[i] - D[j]);
                res[i] = j + 1;
            }
        }
    }
    rep(i, N) cout << res[i] << endl;
    return 0;
}