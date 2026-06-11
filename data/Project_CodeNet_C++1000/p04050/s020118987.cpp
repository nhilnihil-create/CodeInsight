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
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vi a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    if (sz(a) == 1) {
        cout << a[0] << "\n";

        if (a[0] > 1) {
            cout << "2\n" << a[0] - 1 << " 1\n";
        } else {
            cout << "1\n1\n";
        }
        return 0;
    }

    sort(all(a), [](int i, int j) {
        return (i&1) < (j&1);
    });

    if (sz(a) > 2 && (a[M - 3]&1)) {
        cout << "Impossible\n";
        return 0;
    }

    if (a.back()&1) {
        a.insert(a.begin(), a.back());
        a.pop_back();
    }

    for (int i = 0; i < M; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;

    vi b;
    if (a[0] > 1) b.push_back(a[0] - 1);
    for (int i = 1; i + 1 < M; i++)
        b.push_back(a[i]);
    b.push_back(a[M - 1] + 1);

    cout << sz(b) << "\n";
    for (int i = 0; i < sz(b); i++) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << "\n";

    return 0;
}

