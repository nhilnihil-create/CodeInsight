#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

int main() {
    int n, m;
    cin(n); cin(m);

    struct Edge {
        int from, to;
        ll cost;
    };

    vector<Edge> edges(m);
    rep2(i, m) {
        int from, to;
        ll cost;
        cin(from); cin(to); cin(cost);

        --from; --to;

        edges[i] = { from, to, cost };
    }

    vector<ll> s(n, LLONG_MIN);
    s[0] = 0;

    rep2(i, m) {
        Edge e = edges[i];

        if (s[e.from] != LLONG_MIN) {
            if (s[e.from] + e.cost > s[e.to]) s[e.to] = s[e.from] + e.cost;
        }
    }

    ll first = s[n - 1];

    rep2(i, m) {
        Edge e = edges[i];

        if (s[e.from] != LLONG_MIN) {
            if (s[e.from] + e.cost > s[e.to]) s[e.to] = s[e.from] + e.cost;
        }
    }

    if (first == s[n - 1]) {
        print(first);
    } else {
        print("inf");
    }

    return 0;
}