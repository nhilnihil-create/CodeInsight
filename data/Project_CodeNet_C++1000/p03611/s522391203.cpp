#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

int main() {
    int N;
    int a[(int)1e+5] = {};
    int ans=0, buf;

    cin >> N;
    rep (i, N) {
        cin >> buf;
        a[buf]++;
    }

    int temp = a[0] + a[1] + a[2];
    ans = temp;
    rep(i, (int)1e+5-3) {
        temp = temp -a[i] + a[i+3];
        ans = max(ans, temp);
    }

    cout << ans << endl;
}
