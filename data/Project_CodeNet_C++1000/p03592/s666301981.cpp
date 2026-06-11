#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "No";
    rep(i,n+1) {
        rep(j,m+1) {
            if (k == i*m + j*n - 2*i*j) ans = "Yes";
        }
    }
    cout << ans << endl;
}