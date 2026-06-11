#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

// calculates nCk
struct CombinationD {
    vector<vector<ll>> fac;
    CombinationD(ll maxN) {
        fac.resize(maxN + 2, vector<ll>(maxN + 2, 0));
        fac[0][0] = 1;
        for (int i = 1; i <= maxN; ++i) {
            fac[i][0] = fac[i - 1][0];
            for (int j = 1; j <= i + 1; ++j) {
                fac[i][j] = (fac[i - 1][j] + fac[i - 1][j - 1]);
            }
        }
    }
    ll operator()(ll n, ll k) { return fac[n][k]; }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vl v(n);
    map<ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    cout << fixed << setprecision(10);
    sort(v.begin(), v.end(), greater<ll>());
    double mean = 0;
    ll curr    = -1;
    int idx     = -1;
    for (int i = 0; i < a; ++i) {
        mean += v[i];
        if (curr != v[i]) {
            curr = v[i];
            idx  = i;
        }
    }
    mean /= double(a);
    ll used = a - 1 - idx + 1;
    ll tot  = cnt[curr];
    CombinationD nCk(50);
    if (v[0] == v[a - 1]) {
        tot    = cnt[curr];
        ll num = 0;
        for (int i = a; i <= min(ll(b), tot); ++i) {
            num += nCk(tot, i);
        }
        cout << mean << "\n";
        cout << num << "\n";
        return 0;
    }
    ll num = nCk(tot, used);
    cout << mean << "\n";
    cout << num << "\n";
    return 0;
}