#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int t[n];
    int sum = 0;
    rep(i, n) cin >> t[i];
    rep(i, n) sum += t[i];
    cin >> m;

    rep(i, m) {
        int p, x;
        cin >> p >> x;
        p--;

        int time = sum - t[p];
        cout << time + x << endl;
    }

    return 0;
}
