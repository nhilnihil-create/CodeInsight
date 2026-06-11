#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// macro-----------------------------------------------------------------------------------------
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll inf = 100100100100000;
const ll mod = 1000000007;

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

struct edge {
    int from, to, cost;
};
signed main() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, -c};
    }

    bool isnc = false;
    vector<ll> dist(n, inf);
    dist[0] = 0;

    rep(i, 0, n) {
        rep(j, 0, m) {
            int frm = edges[j].from, to = edges[j].to, cost = edges[j].cost;
            if (dist[frm] != inf && dist[to] > dist[frm] + cost) {
                dist[to] = dist[frm] + cost;
                if (i == n - 1 && to == n - 1)
                    isnc = true;
            }
        }
    }

    if (isnc)
        cout << "inf\n";
    else
        cout << -dist.back() << "\n";
}
