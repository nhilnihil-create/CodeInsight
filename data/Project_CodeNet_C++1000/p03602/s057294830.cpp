#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");
#define pv(v, n) REP(ii, n) { cout << v[ii]; delim(ii, n); }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 300;
int n;
vii dist(maxn, vi(maxn));
vii init_dist(maxn, vi(maxn));
vii flag(maxn, vi(maxn));

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void warshall_floyd() {
    REP(i, n) {
        REP(j, n) {
            REP(k, n) {
                if (dist[j][i] == inf || dist[i][k] == inf) continue;
                // min(inf, inf + (N<0)) should be inf but not
                if (dist[j][k] >= dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    if (j != i && i != k) flag[j][k] = 1;
                }
            }
        }
    }
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n;
    REP(i, n) {
        REP(j, n) {
            cin >> dist[i][j];
            init_dist[i][j] = dist[i][j];
        }
    }
    
    warshall_floyd();

    int ret = 0;
    REP(i, n) {
        REP(j, n) {
            if (init_dist[i][j] != dist[i][j]) {
                ret = -2;
                break;
            }
            ret += (1-flag[i][j])*init_dist[i][j];
        }
        if (ret == -2) break;
    }
    ret /= 2;
    
    cout << std::fixed << std::setprecision(10) << ret << "\n";
}