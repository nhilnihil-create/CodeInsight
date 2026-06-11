#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N, M; cin >> N >> M;
    vector<bool> valid1(N + 1);
    vector<bool> validN(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == 1) valid1[b] = 1;
        if (b == N) validN[a] = 1;
    }

    for (int i = 2; i <= N - 1; i++) {
        if (valid1[i] && validN[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}