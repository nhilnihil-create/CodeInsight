#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    vector<long long> sum(N + 1, 0);
    rep(i, N) sum[i + 1] = sum[i] + A[i];
    
    for (int i = N; i > 0; --i) {
        if (sum[i - 1] * 3 < sum[i]) {
            cout << N - i + 1 << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}
