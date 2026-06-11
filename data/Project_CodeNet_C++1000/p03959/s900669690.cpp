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

    int N;
    cin >> N;
    vector<int> T(N), A(N), maxh(N);
    vector<bool> dec(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
        maxh[i] = T[i];
        if (i == 0 || T[i - 1] < T[i])
            dec[i] = true;
    }

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    bool isok = true;
    for (int i = N - 1; i >= 0; --i) {
        if (dec[i] && maxh[i] > A[i]) {
            isok = false;
            break;
        }
        if (dec[i])
            continue;
        maxh[i] = min(maxh[i], A[i]);
        if (i == N - 1 || A[i] > A[i + 1]) {
            dec[i] = true;
            maxh[i] = A[i];
            if (maxh[i] > T[i]) {
                isok = false;
                break;
            }
        }
    }

    if (!isok) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for (int i = 0; i < N; ++i) {
        if (dec[i])
            continue;
        (ans *= maxh[i]) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
