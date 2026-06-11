#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int n, k; cin >> n >> k;
    int A[n], B[n];
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) if ((A[i] | k) == k) ans += B[i];
    for (int e = 1; e <= k; e *= 2) {
        if ((e & k) == 0) continue;
        int target = (k - e) | (e - 1);
        long long sum = 0;
        for (int i = 0; i < n; i++) if ((A[i] | target) == target) sum += B[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
