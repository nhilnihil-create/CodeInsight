/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }

template <typename T> inline void write(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar(' ');}
template <typename T> inline void writeln(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar('\n');}
inline char readch() {char c; do c = getchar(); while (c == '\n' || c == ' '); return c;}
inline void reads(string &s) {char c; while((c=getchar())==' '||c =='\n'); s=c; while((c=getchar())!=' '&&c!='\n') s+=c;}
inline void getlines(string &s) {char c; while((c=getchar())=='\n'); s=c; while((c=getchar())!='\n') s+=c;}
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;

const ld pi = acos(-1);
const ll inf = 1e16;
const int mod = 1e9 + 7,
N = 1e6 + 11;

int n;
ll bit[N], s[N];
void Inc(ll &a, ll b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
void update(int p, ll val) {
    for (; p <= n; p += p & -p)
        Inc(bit[p], val);
}
ll get(int p) {
    ll ans = 0;
    for (; p > 0; p -= p & -p)
        Inc(ans, bit[p]);
    return ans;
}
int a[N];
void Try(int x) {
    if (x > n) {
        for (int i = 1; i <= n; i++)
            a[i + n] = a[n];
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= i + a[i]; j++)
                for (int k = j + 1; k <= i + a[i]; k++)
                    if (a[j] != a[k])
                        return;
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[x] = i;
        Try(x + 1);
    }
}
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    ll res = 1;
    s[0] = 1;
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1];
        Inc(s[i], get(i));
        res += s[i] * (n - 1) % mod * n % mod;
        update(i + 3, s[i]);
    }
    s[n] = s[n - 1];
    Inc(s[n], get(n));
    res += s[n] * (n - 1) % mod;
    cout << res % mod;
    #ifdef makacha
        freopen("m.ans", "w", stdout);
        if (n <= 9)
            Try(1);
    #endif // makacha
}
