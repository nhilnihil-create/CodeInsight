//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = k;
    rep(i, n-1) {
        ans *= (k-1);
    }

    cout << ans << endl;
}