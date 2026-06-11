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
    ll d = 10000000000;
    cout << "? " << d << endl;
    string ans;
    cin >> ans;
    if (ans == "Y") {
        while (d > 0) {
            cout << "? " << d - 1 << endl;
            cin >> ans;
            if (ans == "N")
                break;
            d /= 10;
            if (d == 1)
                break;
        }
        cout << "! " << d << "\n";
    } else {
        while (true) {
            d /= 10;
            cout << "? " << d << endl;
            cin >> ans;
            if (ans == "Y")
                break;
        }
        ll ok      = d * 10;
        ll ng      = d;
        auto check = [&](ll m) {
            cout << "? " << m << endl;
            cin >> ans;
            return ans == "Y";
        };
        while (ng + 1 != ok) {
            ll mid = (ok + ng) / 2 * 10;
            if (check(mid))
                ok = mid / 10;
            else
                ng = mid / 10;
        }
        cout << "! " << ok << "\n";
    }
    return 0;
}