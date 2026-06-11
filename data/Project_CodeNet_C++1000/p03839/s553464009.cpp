#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    vector<long long> v(n+1, 0);
    for(int i = 0; i < n; ++i) v.at(i+1) = v.at(i) + a.at(i);
    vector<long long> w(n+1, 0);
    for(int i = 0; i < n; ++i) w.at(i+1) = w.at(i) + max(a.at(i), 0);

    long long ans = -INF;
    for(int i = 0; i+k <= n; ++i) {
        long long tmp = w.at(n);
        tmp += max(v.at(i+k) - v.at(i), (long long)0);
        tmp -= w.at(i+k) - w.at(i);
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}