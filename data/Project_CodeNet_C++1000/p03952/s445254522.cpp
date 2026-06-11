#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
namespace mydef {
const int INF = 1ll << 60;
const int MOD = 1e9 + 7;
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
bool dbg = false;
}  // namespace mydef
using namespace mydef;
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int, int>>
#define vvp vector<vector<pair<int, int>>>
#define pi pair<int, int>
//#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define asn ans
static struct IO {
    char tmp[1 << 10];
    // fast input routines
    char cur;
    //#define nextChar() (cur = getc_unlocked(stdin))
    //#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }
    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() {
        while (isBlank(nextChar()))
            ;
        return peekChar() != 0;
    }
    inline IO& operator>>(char& c) {
        c = nextChar();
        return *this;
    }
    inline IO& operator>>(char* buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar()))
                    *(buf++) = peekChar();
            }
            *(buf++) = 0;
        }
        return *this;
    }
    inline IO& operator>>(string& s) {
        if (skipBlanks()) {
            s.clear();
            s += peekChar();
            while (!isBlank(nextChar()))
                s += peekChar();
        }
        return *this;
    }
    inline IO& operator>>(double& d) {
        if ((*this) >> tmp)
            sscanf(tmp, "%lf", &d);
        return *this;
    }
#define defineInFor(intType)                         \
    inline IO& operator>>(intType& n) {              \
        if (skipBlanks()) {                          \
            int sign = +1;                           \
            if (peekChar() == '-') {                 \
                sign = -1;                           \
                n = nextChar() - '0';                \
            } else                                   \
                n = peekChar() - '0';                \
            while (!isBlank(nextChar())) {           \
                n += n + (n << 3) + peekChar() - 48; \
            }                                        \
            n *= sign;                               \
        }                                            \
        return *this;                                \
    }
    defineInFor(int)
        defineInFor(unsigned int)
        //        defineInFor(long long)
        // fast output routines
        //#define putChar(c) putc_unlocked((c), stdout)
        inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator<<(char c) {
        putChar(c);
        return *this;
    }
    inline IO& operator<<(const char* s) {
        while (*s)
            putChar(*s++);
        return *this;
    }
    inline IO& operator<<(const string& s) {
        for (int i = 0; i < (int)s.size(); ++i)
            putChar(s[i]);
        return *this;
    }
    char* toString(double d) {
        sprintf(tmp, "%lf%c", d, '\0');
        return tmp;
    }
    inline IO& operator<<(double d) { return (*this) << toString(d); }
#define defineOutFor(intType)                   \
    inline char* toString(intType n) {          \
        char* p = (tmp + 30);                   \
        if (n) {                                \
            bool isNeg = 0;                     \
            if (n < 0)                          \
                isNeg = 1, n = -n;              \
            while (n)                           \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg)                          \
                *--p = '-';                     \
        } else                                  \
            *--p = '0';                         \
        return p;                               \
    }                                           \
    inline IO& operator<<(intType n) { return (*this) << toString(n); }
    defineOutFor(int)
        defineOutFor(signed)
    //defineOutFor(long long)
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
//https://gist.github.com/sananth12/dc6e9c1e02563b1c5004
//when int is not defined as long long, erase some comments
//Don't forget to erase cin.tie(nullptr); and ios::sync_with_stdio(false);
int N, x, ans[201010];
int used[201011];

void solve() {
}

signed main() {

    cin >> N >> x;
    if (x == 1 || x == N * 2 - 1) {
        No();
        return 0;
    }
    Yes();
    if (N == 2) {
        cout << 1 << endl
             << 2 << endl
             << 3 << endl;
        return 0;
    }
    ans[N] = x;
    used[x] = 1;
    if (x >= N) {
        ans[N - 1] = N * 2 - 1;
        ans[N - 2] = 1;
        ans[N + 1] = 2;
        used[2 * N - 1] = 1;
        used[1] = 1;
        used[2] = 1;
    } else {
        ans[N - 1] = 1;
        ans[N - 2] = N * 2 - 1;
        ans[N + 1] = N * 2 - 2;
        used[N * 2 - 1] = 1;
        used[N * 2 - 2] = 1;
        used[1] = 1;
    }

    int now = 1;
    for (int i = 1; i <= N * 2 - 1; i++) {
        if (ans[i] == 0) {
            while (used[now])
                now++;
            used[now] = 1;
            ans[i] = now;
        }
    }

    for (int i = 1; i <= N * 2 - 1; i++)
        cout << ans[i] << endl;

    solve();
    return 0;
}
