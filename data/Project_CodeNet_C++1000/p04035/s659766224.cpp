#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    ll tmp = 0;
    int idx = -1;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        tmp += a[i];
        if (i >= 1) {
            if (i >= 2)
                tmp -= a[i - 2];
            if (tmp >= L) {
                idx = i;
                break;
            }
        }
    }

    cout << (~idx ? "Possible" : "Impossible") << '\n';
    if (~idx) {
        for (int i = 1; i < idx; ++i)
            cout << i << '\n';
        for (int i = N - 1; i > idx; --i)
            cout << i << '\n';
        cout << idx << '\n';
    }

    return 0;
}
