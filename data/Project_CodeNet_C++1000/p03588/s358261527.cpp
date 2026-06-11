#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int minb = 1001001001;
    int ans = 0;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        if (minb > b) {
            minb = b;
            ans = a + b;
        }
    }
    cout << ans << endl;
}