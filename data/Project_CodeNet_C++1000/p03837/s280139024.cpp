#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

ll INF = 1e15;

vector<vector<ll>> WF_init(int v) {
    vector<vector<ll>> ret;
    for (int i = 0; i < v; i++) {
        vector<ll> tmp;
        for (int j = 0; j < v; j++) tmp.push_back(INF * (i != j));
        ret.push_back(tmp);
    }
    return ret;
}

vector<vector<ll>> warshall_floyd(vector<vector<ll>> G) {
    int v = G.size();
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return G;
}

int main() {
    int n, m, inf = 1e4;
    cin >> n >> m;
    vector<vector<ll>> G(n);
    for (int i = 0; i < n; i++) {
        vector<ll> H(n, inf);
        G[i] = H;
        G[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;  b--;
        G[a][b] = c;
        G[b][a] = c;
    }

    vector<vector<ll>> X = warshall_floyd(G);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += (G[i][j] != inf && G[i][j] > X[i][j]);
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << G[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << X[i][j];
        }
        cout << endl;
    }*/

    cout << ans / 2 << endl;
}
