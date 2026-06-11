#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;
ll d[210][210];

void warshall_floyd(int n) {
    for(int k = 0; k < n; k++) {          // 経由する頂点
        for(int i = 0; i < n; i++) {      // 始点
            for(int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    for(int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(), r.end());
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        d[A][B] = C;
        d[B][A] = C;
    }
    warshall_floyd(N);
    ll ans = inf;
    do {
        ll tmp = 0;
        for(int i = 1; i < R; i++) {
            tmp += d[r[i - 1]][r[i]];
        }
        ans = min(ans, tmp);
    } while(next_permutation(r.begin(), r.end()));

    cout << ans << "\n";
    return 0;
}