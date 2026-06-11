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
    ll n, l, t;
    cin >> n >> l >> t;
    vl x(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> w[i];
    }
    deque<ll> pos;
    for (int i = 1; i < n; ++i) {
        if (w[i] != w[0]) {
            if (w[0] == 1)
                pos.push_back(x[i] - x[0]);
            else
                pos.push_front(l - (x[i] - x[0]));
        }
    }
    deque<ll> p = pos;
    for (auto &v : pos) {
        p.push_back(v + l);
    }
    ll cnt = t / l * p.size();
    ll lft = t % l;
    for (auto &v : p) {
        if (v < lft * 2)
            cnt++;
    }

    ll idx = w[0] == 1 ? (cnt) % n : ((-cnt) % n + n) % n;
    vl ret;
    ll id = -1;
    for (int i = 0; i < n; ++i) {
        ll curr = x[i] + (w[i] == 1 ? t : (-t % l + l) % l);
        curr %= l;
        ret.push_back(curr);
        if (i == 0)
            id = curr;
    }
    sort(ret.begin(), ret.end());
    int posidx;
    if (w[0] == 1)
        posidx = lower_bound(ret.begin(), ret.end(), id) - ret.begin();
    else
        posidx = upper_bound(ret.begin(), ret.end(), id) - ret.begin() - 1;
    for (int i = 0; i < n; ++i) {
        ret.push_back(ret[i]);
    }
    vl r(n);
    for (int i = 0; i < n; ++i) {
        r[(idx + i) % n] = ret[(posidx + i) % n];
    }
    for (auto &rr : r) {
        cout << rr << "\n";
    }
    return 0;
}