
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5001;
int n, k;
int a[N];
bool dp[N];

bool check(int x) {
    if (a[x] >= k) return true;
    memset(dp, 0, sizeof dp);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        if (i == x) continue;
        for (int j = k - 1; j > 0; --j) {
            if (j >= a[i] && dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }
    for (int i = k - a[x]; i < k; ++i) {
        if (dp[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k) {
        cout << n << endl;
        exit(0);
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (r - l) / 2 + l;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;

    return 0;
}

