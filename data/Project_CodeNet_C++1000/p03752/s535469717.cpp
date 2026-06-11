#include "bits/stdc++.h"

using namespace std;

const long long INF = 1000000000000000000LL;

void Main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> a(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long ans = INF;
    for (int b = 0; b < (1 << N); ++b) {
        if (__builtin_popcount(b) < K) {
            continue;
        }
        long long maxSoFar = 0;
        long long tempAns = 0;
        for (int i = 0; i < N; ++i) {
            if (b >> i & 1) {
                if (a[i] <= maxSoFar) {
                    tempAns += maxSoFar - a[i] + 1;
                    ++maxSoFar;
                }
                else {
                    maxSoFar = a[i];
                }
            }
            else {
                maxSoFar = max(maxSoFar, a[i]);
            }
        }
        ans = min(ans, tempAns);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
