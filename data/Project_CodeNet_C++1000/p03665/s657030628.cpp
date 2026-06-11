#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

vector<vector<ll>> memo;
void init() {
    memo[0].push_back(1);
    memo[1].push_back(1);
    memo[1].push_back(1);
    for (int i = 2; i < memo.size(); i++) {
        memo[i].resize(i+1);
        memo[i][0] = 1;
        memo[i][i] = 1;
        for (int j = 1; j < i; j++) {
            memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
        }
    }
}


int main() {
    int N, P; cin >> N >> P;
    memo.assign(N+1, vector<ll>());
    init();
    vector<int> A(N);
    int even = 0, odd = 0;
    rep(i,N) {
        cin >> A.at(i);
        if (A[i] % 2 == 0) even++; else odd++;
    }
    ll res = 0;
    if (P) { // odd
        for (int i = 1; i <= odd; i += 2) {
            rep(j, even+1) {
                res += memo[even][j] * memo[odd][i];
            }
        }
    } else { // even
        rep(i, even + 1) {
            for (int j = 0; j <= odd; j += 2) {
                res += memo[even][i] * memo[odd][j];
            }
        }
    }
    cout << res << endl;
}
