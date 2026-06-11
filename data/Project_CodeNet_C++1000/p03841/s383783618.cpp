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

int main() {
    ll n;
    cin >> n;
    vi x(n);
    vector<pii> xs;
    xs.reserve(n * n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
        x[i]--;
        xs.emplace_back(x[i], i + 1);
    }
    sort(xs.begin(), xs.end());
    vi ret(n * n, -1);
    vi touse;
    ll idx = 0;
    for (ll i = 0; i < n; ++i) {
        ret[xs[i].first] = xs[i].second;
        for (ll j = 0; j < xs[i].second - 1; ++j) {
            while (ret[idx] != -1)
                idx++;
            ret[idx] = xs[i].second;
        }
        for (int j = 0; j < n - xs[i].second; ++j) {
            touse.push_back(xs[i].second);
        }
    }
    idx = 0;
    for (auto &u : touse) {
        while (ret[idx] != -1)
            idx++;
        ret[idx] = u;
    }

    vi cnt(n + 1, 0);
    for (ll i = 0; i < n * n; ++i) {
        cnt[ret[i]]++;
        if (ret[i] == cnt[ret[i]]) {
            if (x[ret[i] - 1] != i) {
                cout << "No"
                     << "\n";
                return 0;
            }
        }
    }
    cout << "Yes"
         << "\n";
    print(ret);
    return 0;
}