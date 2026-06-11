#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    map<int, long long> m;
    rep(i, n) {
        cin >> a[i] >> b[i];
        m[a[i]] += b[i];
    }
    long long cnt = 0;
    for (auto x : m) {
        cnt += x.second;
        if (cnt >= k) {
            cout << x.first << endl;
            break;
        }
    }
}
