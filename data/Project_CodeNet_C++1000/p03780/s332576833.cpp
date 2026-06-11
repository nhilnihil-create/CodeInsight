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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&](ll mid) {
        if (a[mid] >= k)
            return false;
        bitset<5001> dp = 0;
        dp[0]           = 1;
        for (int i = 0; i < n; ++i) {
            if (i == mid)
                continue;
            if (a[i] <= 5000)
                dp |= dp << a[i];
        }
        bool ok = true;
        for (int i = max(0LL, k - a[mid]); i < k; ++i) {
            if (dp[i] == 1) {
                ok = false;
                break;
            }
        }
        return ok;
    };
    if (!check(0)) {
        cout << 0 << "\n";
        return 0;
    } else if (check(n - 1)) {
        cout << n << "\n";
        return 0;
    }
    ll ok = 0;
    ll ng = n - 1;
    while (abs(ok - ng) != 1) {
        ll mid = (ng + ok) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok + 1 << "\n";
    return 0;
}