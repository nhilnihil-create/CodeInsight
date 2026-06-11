#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using lint = long long;
const lint INF = 1e18;

int N, K;
vector<lint> a, asum, bsum;

int main() {
    cin >> N >> K;
    a.resize(N + 1);
    asum.resize(N + 1);
    bsum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    asum[0] = bsum[0] = 0;
    for (int i = 1; i <= N; i++) {
        asum[i] = asum[i - 1] + a[i];
        bsum[i] = bsum[i - 1] + max((lint)0, a[i]);
    }

    lint ans = -INF;
    for (int i = K; i <= N; i++) {
        int left = i - K, right = i;
        lint cand = max((lint)0, asum[right] - asum[left])
                + bsum[N] - bsum[right] + bsum[left];
        ans = max(ans, cand);
    }

    cout << ans << endl;
    return 0;
}