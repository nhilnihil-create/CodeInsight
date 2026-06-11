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
const ll inf = 1e9,
mod = 1e9 + 7,
N = 3e5 + 11;

int n, m, bit[N];
vector <ii> ds[N];
void update(int p, int val) {
    for (; p <= m; p += (p & -p))
        bit[p] += val;
}
int get(int p) {
    int ans = 0;
    for (; p > 0; p -= (p & -p))
        ans += bit[p];
    return ans;
}
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    read(m);
    for (int i = 1; i <= n; i++) {
        int l, r;
        read(l);
        read(r);
        ds[r - l + 1].push_back(ii(l, r));
    }
    for (int i = 1; i <= m; i++) {
        int ans = n;
        for (int j = i; j <= m; j += i)
            ans += get(j);
        writeln(ans);
        for (auto p: ds[i]) {
            update(p.fi, 1);
            update(p.se + 1, -1);
            n--;
        }
    }

}
