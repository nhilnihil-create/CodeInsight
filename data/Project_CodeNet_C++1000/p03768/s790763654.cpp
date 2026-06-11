#include"bits/stdc++.h"
using namespace std;
using ll = long long;

vector<vector<ll>> connect;
vector<vector<ll>> color;

void update(ll v, ll d, ll i) {
    if (color[v][d] != 0) {
        return;
    }

    color[v][d] = i;

    if (d == 0) {
        return;
    }

    update(v, d - 1, i);
    for (auto next : connect[v]) {
        update(next, d - 1, i);
    }
}

int main() {
    ll N, M;
    cin >> N >> M;

    connect.resize(N);

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    ll Q;
    cin >> Q;

    vector<ll> v(Q), d(Q), c(Q);
    for (ll i = 0; i < Q; i++) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    color.assign(N, vector<ll>(11, 0));

    for (ll i = Q - 1; i >= 0; i--) {
        update(v[i], d[i], c[i]);
    }

    for (ll i = 0; i < N; i++) {
        cout << color[i][0] << endl;
    }
}