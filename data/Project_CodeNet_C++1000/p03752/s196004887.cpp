#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long ans = 1LL << 60;
    for (int bit = 0; bit < 1 << N; ++bit) {
        int pre = A[0], num = 1;
        long long sum = 0;
        for (int i = 1; i < N; ++i) {
            if (bit >> i & 1) {
                num++;
                if (A[i] > pre) {
                    pre = A[i];
                } else {
                    sum += pre - A[i] + 1;
                    pre++;
                }
            } else {
                if (A[i] > pre) num++;
                pre = max(pre, A[i]);
            }
        }
        if (num >= K) ans = min(ans, sum);
    }
    cout << ans << endl;
}