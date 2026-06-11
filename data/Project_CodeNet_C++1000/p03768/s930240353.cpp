#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n, m;
int a[100100], b[100100];
int q;
int V[100100], D[100100], C[100100];

vector<int> G[100100];

int color[100100];
int dist[100100];

void dfs(int v, int d, int c) {
    if (d < dist[v] || (d == dist[v] && d > 0))
        return;
    if (color[v] == 0) {
        color[v] = c;
    }
    if (d == 0)
        return;

    dist[v] = d;
    for (int u : G[v]) {
        dfs(u, d-1, c);
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    
    for (int i = q-1; i >=0; i--) {
        dfs(V[i], D[i], C[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << color[i] << endl;
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> V[i] >> D[i] >> C[i];
        V[i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
