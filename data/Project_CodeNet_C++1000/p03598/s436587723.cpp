#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 0;
    rep(i, N) {
        int x;
        cin >> x;
        ans += min(x*2,(K-x)*2);
    }
    cout << ans << endl;
}
