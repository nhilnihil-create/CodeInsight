#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl
typedef long long ll;
const int N = 5e3 + 5;
int a[N];
bitset<N> dp;
int n, k;
ll sum;

bool check(int m) {
    if (a[m] >= k) return true;
    dp.reset();
    dp.set(0);
    for (int i=1; i<=n; ++i) if (i != m) {
        dp |= (dp << a[i]);
    }
    for (int i=k-a[m]; i<k; ++i) {
        if (dp[i]) return true;
    }
    return false;
}

int solve() {
    if (sum < k) return n;  //所有数之和小于k 
    sort(a+1, a+n+1);
    if (check(0)) return 0;
    int low = 1, high = n, ret = 0;
    while (low <= high) {
        int mid = low + high >> 1;
        if (check(mid)) high = mid-1;
        else { ret = mid; low = mid+1; }
    }
    return ret;
}

int main() {
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cout << solve() << '\n';
    return 0;
}
