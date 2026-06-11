#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

bool used[SIZE][12];
ll c[SIZE][12];
bool u[SIZE];

vector<vector<ll>> gr;

void upd(int v, int dist, int col) {
    if (used[v][dist]) return;

    if (!u[v]) c[v][0] = col;
    used[v][dist] = 1;
    u[v] = 1;
    for (auto to : gr[v]) {
        if (dist != 0) upd(to, dist - 1, col);
    }
}

int main()
{
    fastInp;
    
    ll n, m, q;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    cin >> q;

    vector<tuple<ll, ll, ll>> qs;
    while (q--) {
        ll u, d, c;
        cin >> u >> d >> c;
        u--;
        qs.push_back({u, d, c});
    }

    reverse(qs.begin(), qs.end());

    for (int i = 0; i < qs.size(); i++) {
        upd(get<0>(qs[i]), get<1>(qs[i]), get<2>(qs[i]));
    }

    for (int i = 0; i < n; i++) {
        cout << c[i][0] << "\n";
    }

    return 0;
}