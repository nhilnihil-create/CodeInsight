#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<long long> c(100001);
    rep(i, n) {
        cin >> a[i] >> b[i];
        c[a[i]] += b[i];
    }
    long long cnt = 0;
    rep(i, 100001) {
        cnt += c[i];
        if (cnt >= k) {
            cout << i << endl;
            break;
        }
    }
}