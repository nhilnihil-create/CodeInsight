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

    int mi = 0;
    vec c(9, 0);
    rep(i, n) {
        if (a[i] >= 3200) {
            c[8]++;
        }
        else {
            c[a[i]/400]++;
        }
    }

    rep(i, 8) if (c[i] > 0) mi++;
    if (mi == 0) mi = 1;
    
    int mx = 0;
    rep(i, 8) if (c[i] > 0) mx++;
    mx += c[8];
    printf("%d %d\n", mi, mx);
    return 0;
}