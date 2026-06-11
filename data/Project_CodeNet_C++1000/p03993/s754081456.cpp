#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        --a[i];
    }

    int ans = 0;
    rep(i, N) if (i == a[a[i]])++ ans;

    cout << ans / 2 << endl;

    return 0;
}