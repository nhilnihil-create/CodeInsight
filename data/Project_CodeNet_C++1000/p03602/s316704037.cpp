#include <algorithm>
#include <cmath>
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
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    vector<vector<int>> d(N, vector<int>(N));
    d = A;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int dist = INF;
            for(int k = 0; k < N; k++) {
                if(k == i || k == j)
                    continue;
                dist = min(dist, d[i][k] + d[k][j]);
            }
            if(A[i][j] < dist) {
                res += A[i][j];
            } else if(A[i][j] == dist) {
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}