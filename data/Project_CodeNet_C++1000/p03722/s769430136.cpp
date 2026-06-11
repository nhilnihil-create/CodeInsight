#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

struct edge {ll from, to, cost;};
edge es[2000];
ll d[1000];
ll N, M;

int main() {
    cin >> N >> M;
    rep(i,M) {
        ll a, b, c; cin >> a >> b >> c;
        es[i] = {--a, --b, c};
    }

    rep(i,N) d[i] = INT64_MIN;
    d[0] = 0;
    rep(i,N) {
        rep(j, M) {
            edge e = es[j];
            if (d[e.from] != INT64_MIN && d[e.to] < d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == N - 1 && e.to == N - 1) {
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    }
    cout << d[N - 1] << endl;
}
