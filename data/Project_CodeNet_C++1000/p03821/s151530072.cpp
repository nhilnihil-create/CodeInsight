#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        A[i] += ans;
        long long r = A[i] % B[i];
        if (r == 0) continue;
        ans += B[i] - r;
    }

    cout << ans << endl;
}