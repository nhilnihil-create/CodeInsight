#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    deque<int> b;

    rep(i, n) {
        if (i % 2 == 0) {
            b.push_back(a[i]);
        }
        else {
            b.push_front(a[i]);
        }
    }

    if (n % 2 == 0) {
        rep(i, n) {
            if (i != 0) cout << " ";
            cout << b[i];
        }
        cout << endl;
    }
    else {
        rep(i, n) {
            if (i != 0) cout << " ";
            cout << b[n-1-i];
        }
        cout << endl;
    }
    return 0;
}