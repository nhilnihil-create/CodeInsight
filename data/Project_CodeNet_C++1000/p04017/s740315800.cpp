#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
using matrix = vector<vector<uint>>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M = 0;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i)
        cin >> x[i];
    while (N >> M)
        M++;

    int L;
    cin >> L;

    vector<vector<ll>> nxt(M, vector<ll>(N, N - 1));
    for (int i = 0; i < N; ++i)
        nxt[0][i] = upper_bound(x.begin(), x.end(), x[i] + L) - x.begin() - 1;
    for (int i = 0; i + 1 < M; ++i)
        for (int j = 0; j < N; ++j)
            nxt[i + 1][j] = nxt[i][nxt[i][j]];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b, res = 0;
        cin >> a >> b;
        a--, b--;
        if (a == b) {
            cout << res << '\n';
            continue;
        }

        if (a > b)
            swap(a, b);

        for (int j = M - 1; j >= 0; --j) {
            if (nxt[j][a] < b) {
                a = nxt[j][a];
                res += (1 << j);
            }
        }
        cout << res + 1 << '\n';
    }

    return 0;
}
