#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    
    long long ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        A[i] += ans;
        ans += (A[i] + B[i] - 1) / B[i] * B[i] - A[i];
    }
    cout << ans << endl;
    return 0;
}
