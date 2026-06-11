#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    rep(i, n) {
        int a;
        cin >> a;
        cnt += (a % 2);
    }

    cnt % 2 ? cout << "NO" : cout << "YES";
    cout << endl;

    return 0;
}