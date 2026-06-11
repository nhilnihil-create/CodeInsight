#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    long long A[N], B[N];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        A[i] += ans;
        ans += (B[i] - A[i] % B[i]) % B[i];
    }
    cout << ans << endl;
}