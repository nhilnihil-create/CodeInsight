#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, l;
    cin >> n >> l;
    vec a(n);
    rep(i, n) cin >> a[i];

    int i = -1;
    rep(j, n-1) {
        if (a[j] + a[j+1] >= l) {
            i = j;
            break;
        }
    }
    if (i == -1) {
        cout << "Impossible" << endl;
        exit(0);
    }
    else {
        cout << "Possible" << endl;
    }

    rep(j, i) {
        cout << j + 1 << endl;
    }

    for (int j = n-2; j >= i; j--) {
        cout << j+1 << endl;
    }
    
    return 0;
}