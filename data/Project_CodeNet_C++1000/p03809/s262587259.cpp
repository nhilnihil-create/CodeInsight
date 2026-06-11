// 基本テンプレート

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int N;
int A[100010], deg[100010];
vector<int> G[100010];
map<int, map<int, int> > m;

void dfs(int x, int par=-1) {
    int sum = 0, rec = -1;
    bool leaf = true;
    rep(i,0,G[x].size()) {
        int to = G[x][i];
        if(to == par) {
            rec = i;
            continue;
        }
        leaf = false;
        dfs(to, x);
        // printf("add: %lld -> %lld (cost: %lld)\n", x, to, m[to][x]);
        sum += m[to][x];
    }
    if(leaf) {
        int to = G[x][0];
        // printf("leaf: cur = %lld, to = %lld, cost = %lld\n", x, to, A[x]);
        m[x][to] = m[to][x] = A[x];
    }
    else if(rec != -1) {
        // printf("A[%lld] = %lld, sum = %lld\n", x, A[x], sum);
        int to = G[x][rec];
        // printf("etc: cur = %lld, to = %lld, cost = %lld\n", x, to, 2 * A[x] - sum);
        m[x][to] = m[to][x] = 2 * A[x] - sum;
    }
}

signed main() {
    cin >> N;
    rep(i,0,N) {
        cin >> A[i];
    }
    rep(i,0,N-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    dfs(0);

    bool ok = true;
    rep(i,0,N) {
        if(deg[i] == 1) {
            // leaf
            int to = G[i][0];
            // printf("leaf (%lld): cost = %lld, A = %lld\n", i, m[i][to], A[i]);
            if(m[i][to] != A[i]) ok = false;
        }
        else {
            int sum = 0;
            for(auto c : G[i]) sum += m[i][c];
            if(sum % 2 || sum / 2 != A[i]) ok = false;
            for(auto c : G[i]) {
                // printf("(%lld, %lld): sum = %lld, cost = %lld\n", i, c, sum, m[i][c]);
                if(m[i][c] < 0) ok = false;
                if(m[i][c] * 2 > sum) ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}