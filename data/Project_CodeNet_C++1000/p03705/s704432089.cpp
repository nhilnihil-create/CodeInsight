#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = B * (N - 2) - A * (N - 2) + 1;
    if ((A != B && N == 1) || A > B) ans = 0;
    cout << ans << endl;
}