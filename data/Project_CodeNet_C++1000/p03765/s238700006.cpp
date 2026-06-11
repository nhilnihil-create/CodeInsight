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
const int inf = 12e8;
const int mod = 1e9 + 7,
N = 2e6 + 11;

string s, t;
int n, m, q, cnt[2][N];
int sum(int l, int r, int tp) {
    return cnt[tp][r] - cnt[tp][l - 1];
}
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    reads(s);
    reads(t);
    n = s.size();
    s = '#' + s;
    m = t.size();
    t = '#' + t;
    for (int i = 1; i <= n; i++)
        cnt[0][i] = cnt[0][i - 1] + (s[i] == 'A' ? 1 : -1);
    for (int i = 1; i <= m; i++)
        cnt[1][i] = cnt[1][i - 1] + (t[i] == 'A' ? 1 : -1);
    read(q);
    while (q--) {
        int l, r, u, v;
        read(l);
        read(r);
        read(u);
        read(v);
        if ((sum(l, r, 0) - sum(u, v, 1)) % 3)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
