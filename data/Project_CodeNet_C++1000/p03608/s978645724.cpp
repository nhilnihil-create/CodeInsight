#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const ll MAX_N = 210;

ll d[MAX_N][MAX_N];
ll N;
void warshall_floyd() {
    for(ll k = 0; k < N; k++) {
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    ll i, j, k;
    ll M, R;
    cin >> N >> M >> R;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }
    vll r(R);
    for(auto &e : r)
        cin >> e;
    for(i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        d[a - 1][b - 1] = c;
        d[b - 1][a - 1] = c;
    }
    warshall_floyd();
    ll ans = INF;
    sort(r.begin(), r.end());
    do {
        ll dist = 0;
        for(i = 0; i < R - 1; i++) {
            dist += d[r[i] - 1][r[i + 1] - 1];
        }
        ans = min(ans, dist);
    } while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;

    return 0;
}
