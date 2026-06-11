#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 0;

    while (N >= 1 && M >= 2) {
        if (2 * N >= M) {
            ans += (M / 2);
            break;
        } else if (2 * N < M) {
            ans += N;
            M -= (N * 2);
            N = 0;
            
            N = (M / 2) - (M / 2) % 2;
            M/=2;
            M += (M / 2) % 2;
            N /= 2;
        }
    }
    cout << ans << '\n';
}
