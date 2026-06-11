#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto fail = [](){ cout << "NO\n"; exit(0); };

    int N;
    cin >> N;

    ll sum = N * (N + 1ll) / 2;
    ll tot = 0;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        tot += a[i];
    }

    if (tot % sum) fail();

    ll ops = tot / sum;
    ll did = 0;

    for (int i = 0; i < N; i++) {
        int diff = a[i] - a[i == N - 1 ? 0 : i + 1];
        if ((diff + ops) % N) fail();
        if ((diff + ops) < 0) fail();
        did += (diff + ops) / N;
    }

    if (ops != did) fail();

    cout << "YES\n";
    return 0;
}


