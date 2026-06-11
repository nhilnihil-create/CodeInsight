#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)

int main() {
    ll n;
    while (cin >> n) {
        vector<int> tail(100);
        iota(all(tail), 1);
        vector<int> head;
        int i = 1;
        while ((1LL << i) - 1 <= n) {
            // dump(i);
            head.push_back(i);
            ++i;
        }
        --i;
        n -= (1LL << i) - 1;
        // dump(n);
        int k = 50;
        for (int i = head.size() - 1; i >= 0; --i) {
            if (n >> i & 1) {
                head.insert(head.begin() + i, k);
                ++k;
            }
        }
        cout << head.size() + tail.size() << endl;
        for (auto &c : head) cout << c << ' ';
        for (auto &c : tail) cout << c << ' ';
        cout << endl;
    }
}
