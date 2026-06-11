#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long ans[n+1], sum[n+1];
    ans[0] = 1, sum[0] = 1;
    ans[1] = n, sum[1] = n + 1;
    const int M = 1000000007;
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i-1];      // 1, 1
        if (i >= 3) ans[i] += sum[i-3]; // k, 1; k < i
        if (i >= 2) ans[i] += (long long)(i - 2) * (n - 1); // k, l; k < i, l > 1
        ans[i] += (long long)(n - i + 1) * n; // k, l; k >= i
        ans[i] %= M;
        sum[i] = (sum[i-1] + ans[i]) % M;
    }
    cout << ans[n] << endl;
}
