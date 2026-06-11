#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 3, INF = 1e9 * 100;
vector<vector<ll>> gr;

bool used[SIZE];
vector<ll> vec, ret;

ll dfs(int v) {
    used[v] = 1;

    ll cnt = 0, s = 0;
    vector<ll> vals;
    if (gr[v].size() == 1) {
        ret[v] = vec[v];
        return vec[v];
    }
    for (auto to : gr[v]) {
        if (!used[to]) {
            ll vl = dfs(to);
            if (vl == INF) {
                ret[v] = INF;
                return INF;
            }
            vals.push_back(vl);
            s += vl;
            cnt++;
        }
    }

    sort(vals.rbegin(), vals.rend());
    if (s < vec[v]) {
        ret[v] = INF;
        return INF;
    }
    ll mn = 0;
    if (vals[0] <= (s - vals[0])) {
        mn = s / 2 + (s % 2);
    }
    else {
        ll lft = vals[0] - (s - vals[0]);
        mn = (s - vals[0]) + lft;
    }

    
    if (mn > vec[v]) {
        ret[v] = INF;
        return INF;
    }

    ll dif = s - vec[v];
    ll needed = s - dif * 2;

    ret[v] = needed;
    return needed;
}
int main() {
    fastInp;
    ll n;
    cin >> n;
    ret.resize(n);

    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    gr.resize(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    if (n == 2) {
        if (vec[0] == vec[1]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (gr[i].size() != 1) {
            if (dfs(i) == 0) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
            break;
        }
    }

    return 0;
}
