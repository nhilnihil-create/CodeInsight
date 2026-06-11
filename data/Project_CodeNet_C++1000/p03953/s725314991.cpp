#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define ret return
#define PB push_back
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define pll pair <long long ,  long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 3e5 + 30;
ll n , m , k , x[maxn] , per[maxn] , y[maxn] , ans[maxn];
bool mark[maxn];
vector <ll> edges[maxn] , cycle;

void dfs(int v) {
    mark[v] = true;
    cycle.PB(v);
    for (auto u : edges[v]) {
        if(!mark[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        per[i] = i;
        y[i] = x[i + 1] - x[i];
    }
    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        ll pos; cin >> pos;
        pos--;
        swap(per[pos] , per[pos - 1]);
    }
    for (int i = 0; i < n - 1; ++i) {
        edges[i].PB(per[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        if(!mark[i]) {
            dfs(i);
            ll sz = cycle.size();
            ll cnt = 0;
            for (auto u : cycle) {
                ans[u] = cycle[((k + cnt) % sz)];
                cnt++;
            }
            cycle.clear();
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << x[i] << ".0" << endl;
        x[i + 1] = y[ans[i]] + x[i];
    }
    cout << x[n - 1] << ".0" << endl;
}