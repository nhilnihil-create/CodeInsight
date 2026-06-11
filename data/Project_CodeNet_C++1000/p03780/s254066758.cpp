#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

int N, K;
ll a[5001];
ll asum;
bool dp[5001];

bool isNoNeed(int x) {
    if (asum < K) {
        return true;
    }
    fill(dp, dp + K, false);
    dp[0] = true;
    if (K - a[x] <= 0) {
        return false;
    }
    for (int i = 0; i < N; i++) {
        if (i == x) continue;
        for (int j = K - 1; j >= a[i]; j--) {
            dp[j] = dp[j] || dp[j - a[i]];
            if (dp[j] && K - a[x] <= j) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> K;
    asum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        asum += a[i];
    }
    sort(a, a + N);

    //upper_bound [L, R) ans = L
    int L = -1;
    int R = N;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (isNoNeed(M)) {
            L = M;
        } else {
            R = M;
        }
    }

    cout << L + 1 << endl;

    return 0;
}