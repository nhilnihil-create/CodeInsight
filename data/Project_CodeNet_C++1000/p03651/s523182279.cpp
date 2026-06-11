#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int GCD(int x, int y) {if (x % y == 0) return y; return GCD(y, x % y);}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    int G = A[0];
    REP(i, N) G = GCD(G, A[i]);
    int M = 0;
    rep(i, N) M = max(M, A[i]);
    cout << (K % G || M < K ? "IMPOSSIBLE\n" : "POSSIBLE\n");
    return 0;
}
