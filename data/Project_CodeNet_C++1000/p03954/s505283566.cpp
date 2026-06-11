#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    N = 2 * N - 1;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ans = 1;
    for (int lo = 2, hi = N; lo <= hi; ) {
        int mi = (lo + hi) / 2;
        auto seq = [&](int i) { return a[i] >= mi; };

        int mid = N / 2, l = mid, r = mid;
        while (l > 0 && seq(l - 1) != seq(l))
            l--;
        while (r + 1 < N && seq(r + 1) != seq(r))
            r++;

        int res;
        if (l == 0 && r == N - 1) res = seq(0);
        else if (l == 0) res = seq(r);
        else if (r == N - 1) res = seq(l);
        else res = mid - l < r - mid ? seq(l) : seq(r);

        if (res) { ans = mi; lo = mi + 1; }
        else hi = mi - 1;
    }

    cout << ans << endl;

    return 0;
}

