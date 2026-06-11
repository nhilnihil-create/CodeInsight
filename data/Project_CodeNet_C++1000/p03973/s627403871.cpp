#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    ll result = 0;
    int M = 0;
    REP(i, N) {
        int q = (A[i] - 1) / (M + 1);
        if (q) {
            A[i] -= q * (M + 1);
            if (M > 0 && A[i] > M) {
                A[i] = M;
            }
        }
        result += q;
        M = max(M, A[i]);
    }
    cout << result << endl;

    return 0;
}