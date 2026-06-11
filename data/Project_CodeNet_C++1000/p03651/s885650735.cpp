#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

bool solve(int N, int K, vector<int>& A) {
    sort(A.begin(), A.end());
    int GCD = A[0];
    rep(i,N) GCD = gcd(GCD, A[i]);
    return (K % GCD == 0);
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    int ma = 0;
    rep(i,N) {
        cin >> A.at(i);
        if (ma < A[i]) ma = A[i];
        if (K == A[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    if (K > ma) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    bool possible = solve(N, K, A);
    if (possible) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
