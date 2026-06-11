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
    int n;
    cin >> n;
    vi a(n);
    map<int, int> cnt;
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        chmax(maxi, a[i]);
        cnt[a[i]]++;
    }
    int nmin = (maxi % 2 == 0 ? maxi / 2 : maxi / 2 + 1);
    for (int i = maxi; i >= nmin; --i) {
        if (i == nmin && maxi % 2 == 0) {
            if (cnt[i] < 1) {
                cout << "Impossible"
                     << "\n";
                return 0;
            } else {
                cnt[i] -= 1;
            }
        } else {
            if (cnt[i] < 2) {
                cout << "Impossible"
                     << "\n";
                return 0;
            } else {
                cnt[i] -= 2;
            }
        }
    }
    while (true) {
        int cmax = -1;
        for (auto it = cnt.rbegin(); it != cnt.rend(); it = next(it)) {
            if (it->second != 0) {
                cmax = it->first;
                break;
            }
        }
        if (cmax == -1)
            break;
        if (cmax <= nmin || cmax > maxi) {
            cout << "Impossible"
                 << "\n";
            return 0;
        }
        for (int i = cmax; i > nmin; --i) {
            if (cnt[i] < 1) {
                continue;
            } else {
                cnt[i]--;
            }
        }
    }
    cout << "Possible"
         << "\n";
    return 0;
}