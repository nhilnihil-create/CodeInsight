#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {

    int N;
    cin >> N;
    vector<int> A(N * 2);
    rep(i, N * 2) cin >> A[i];

    sort(A.begin(), A.end());
    int ans = 0;
    rep(i, N)
        ans += A[i * 2];

    cout << ans << endl;

    return 0;
}