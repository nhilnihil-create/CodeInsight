#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    long long start; cin >> start;
    long long cur = 0;
    long long turn = 0;
    vector<long long> v(2*m+2, 0);
    vector<long long> plus(2*m+2, 0);
    for (int i = 1; i < n; i++) {
        long long p; cin >> p;
        p = (p + m - start) % m; 
        if (cur > p) {
            turn++; p += m;
        }
        v[cur+1] -= (cur+1);
        v[p+1] += (cur+1);
        plus[cur+1]++;
        plus[p+1]--;
        cur = p % m;
    }
    long long all = 0;
    for (int i = 0; i <= 2*m; i++) {
        v[i+1] += v[i];
        plus[i+1] += plus[i];
        all += plus[i];
    }
    for (int i = 0; i <= 2*m; i++) {
        plus[i] *= (long long) i;
        plus[i] += v[i];
        if (i >= m) plus[i%m] += plus[i];
    }
    long long ans = 1e18;
    for (int i = 0; i <= m; i++) {
        ans = min(ans, all-plus[i]);
    }
    cout << ans << endl;
}