#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int now = 0;
    int ans = 0;
    for (auto e : S) {
        if (e == 'I') ++now;
        else
            --now;
        ans = max(ans, now);
    }
    cout << ans << '\n';
}
