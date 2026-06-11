// https://atcoder.jp/contests/abc062/tasks/arc074_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
const ll INFL = 1e18;

#define isvisiblechar(c) (0x21 <= (c) && (c) <= 0x7E)
#define cin scanner
#define cout printer
namespace {
class MaiScanner {
  public:
    template <typename T> void input_integer(T &var) {
        var = 0;
        T sign = 1;
        int cc = getchar_unlocked();
        for (; cc < '0' || '9' < cc; cc = getchar_unlocked())
            if (cc == '-')
                sign = -1;
        for (; '0' <= cc && cc <= '9'; cc = getchar_unlocked())
            var = (var << 3) + (var << 1) + cc - '0';
        var = var * sign;
    }
    inline int c() { return getchar_unlocked(); }
    inline MaiScanner &operator>>(int &var) {
        input_integer<int>(var);
        return *this;
    }
    inline MaiScanner &operator>>(long long &var) {
        input_integer<long long>(var);
        return *this;
    }
    inline MaiScanner &operator>>(string &var) {
        int cc = getchar_unlocked();
        for (; !isvisiblechar(cc); cc = getchar_unlocked())
            ;
        for (; isvisiblechar(cc); cc = getchar_unlocked())
            var.push_back(cc);
        return *this;
    }
    template <typename IT> void in(IT begin, IT end) {
        for (auto it = begin; it != end; ++it)
            *this >> *it;
    }
};
class MaiPrinter {
  public:
    template <typename T> void output_integer(T var) {
        if (var == 0) {
            putchar_unlocked('0');
            return;
        }
        if (var < 0)
            putchar_unlocked('-'), var = -var;
        char stack[32];
        int stack_p = 0;
        while (var)
            stack[stack_p++] = '0' + (var % 10), var /= 10;
        while (stack_p)
            putchar_unlocked(stack[--stack_p]);
    }
    inline MaiPrinter &operator<<(char c) {
        putchar_unlocked(c);
        return *this;
    }
    inline MaiPrinter &operator<<(int var) {
        output_integer<int>(var);
        return *this;
    }
    inline MaiPrinter &operator<<(long long var) {
        output_integer<long long>(var);
        return *this;
    }
    inline MaiPrinter &operator<<(char *str_p) {
        while (*str_p)
            putchar_unlocked(*(str_p++));
        return *this;
    }
    inline MaiPrinter &operator<<(const string &str) {
        const char *p = str.c_str();
        const char *l = p + str.size();
        while (p < l)
            putchar_unlocked(*p++);
        return *this;
    }
    template <typename IT> void join(IT begin, IT end, char sep = ' ') {
        for (bool b = 0; begin != end; ++begin, b = 1)
            b ? *this << sep << *begin : *this << *begin;
    }
};
} // namespace
MaiScanner scanner;
MaiPrinter printer;

int main() {
    int n;
    cin >> n;
    vector<int> v(n * 3);
    REP(i, n * 3) cin >> v[i];
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;
    ll sum1 = 0, sum2 = 0;
    REP(i, n) {
        q1.push(v[i]);
        q2.push(v[i + n * 2]);
        sum1 += v[i];
        sum2 += v[i + n * 2];
    }
    vector<ll> v1, v2;
    v1.push_back(sum1);
    v2.push_back(sum2);
    REP(i, n) {
        int t = q1.top();
        if (t < v[i + n]) {
            q1.pop();
            q1.push(v[i + n]);
            sum1 += v[i + n] - t;
        }
        v1.push_back(sum1);
    }
    REP(i, n) {
        int t = q2.top();
        if (t > v[2 * n - i - 1]) {
            q2.pop();
            q2.push(v[2 * n - i - 1]);
            sum2 += v[2 * n - i - 1] - t;
        }
        v2.push_back(sum2);
    }
    ll maxv = -INFL;
    ll minv = INFL;
    ll ans = -INFL;
    for (auto &x : v1) {
        maxv = max(maxv, x);
        x = maxv;
    }
    for (auto &x : v2) {
        minv = min(minv, x);
        x = minv;
    }
    REP(i, v1.size()) ans = max(ans, v1[i] - v2[v2.size() - 1 - i]);
    cout << ans << "\n";

    return 0;
}
