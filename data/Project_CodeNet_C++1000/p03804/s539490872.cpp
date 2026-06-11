#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, m) rep(j, m) cin >> b[i][j];
    rep(i, n - m + 1) rep(j, n - m + 1) {
        bool ok = true;
        rep(k, m) rep(l, m) {
            if (b[k][l] != a[i+k][j+l]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
