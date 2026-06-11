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
    int n, m;
    cin >> n >> m;
    vector<deque<int>> a(n, deque<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ret = 1000;
    map<int, int> cnt;
    set<int> to_remove;
    for (int i = 0; i < m; ++i) {
        cnt.clear();
        for (int j = 0; j < n; ++j) {
            cnt[a[j].front()]++;
        }
        int maxidx = -1;
        int maxi   = 0;
        for (auto &p : cnt) {
            if (p.second > maxi) {
                maxi   = p.second;
                maxidx = p.first;
            }
        }
        chmin(ret, maxi);
        to_remove.insert(maxidx);
        for (int j = 0; j < n; ++j) {
            while (to_remove.count(a[j].front()) == 1)
                a[j].pop_front();
        }
    }
    cout << ret << "\n";
    return 0;
}