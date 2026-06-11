#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    
    long long ans = 1e18;
    rep(bit, (1 << N)) {
        vector<int> S;
        rep(i, N) {
            if (bit & (1 << i)) S.push_back(i);
        }
        
        long long MAX = 0;
        long long cost = 0;
        vector<long long> B = A;
        for (int x : S) {
            if (B[x] > MAX) {
                MAX = B[x];
                continue;
            }
            cost += MAX - B[x] + 1;
            MAX += 1;
            B[x] = MAX;
        }
        
        MAX = 0;
        int cnt = 0;
        rep(i, N) {
            if (B[i] > MAX) {
                ++cnt;
                MAX = B[i];
            }
        }
        if (cnt >= K) ans = min(ans, cost);
    }
    
    cout << ans << endl;
    return 0;
}
