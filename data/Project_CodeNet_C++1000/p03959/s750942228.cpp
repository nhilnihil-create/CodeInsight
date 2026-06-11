#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<int> T(N), A(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];

    vector<int> H(N);
    vector<bool> D(N, false);
    H[0] = T[0];
    D[0] = true;
    rep(i, N - 1) {
        if (T[i] < T[i + 1]) D[i + 1] = true;
        H[i + 1] = T[i + 1];
    }

    if (D[N - 1] && H[N - 1] != A[N - 1]) {
        puts("0");
        return 0;
    }

    D[N - 1] = true;
    H[N - 1] = A[N - 1];

    for (int i = N - 2; i >= 0; --i) {
        if (A[i] > A[i + 1] && D[i] && H[i] != A[i]) {
            puts("0");
            return 0;
        }
        if (A[i] > A[i + 1] && H[i] < A[i]) {
            puts("0");
            return 0;
        }
        if (A[i] > A[i + 1]) D[i] = true;
        H[i] = min(H[i], A[i]);
    }

    ll ans = 1;
    rep(i, N) {
        if (!D[i]) {
            ans *= H[i];
            ans %= MOD;
        }
    }

    cout << ans << endl;
}