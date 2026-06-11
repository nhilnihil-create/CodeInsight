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

int n, num[N];
ll res[N], sum[N];
vector <int> ds;
struct stc{
    ll v;
    int id;
} a[N];
bool cmp(stc a, stc b) {
    if (a.v == b.v)
        return a.id > b.id;
    return a.v < b.v;
}
void Add(int p, int val) {
    for (; p > 0; p -= (p & -p))
        num[p] += val;
}
int Num(int p) {
    int ans = 0;
    for (; p <= n; p += (p & -p))
        ans += num[p];
    return ans;
}
void Inc(int p, ll val) {
    for (; p > 0; p -= (p & -p))
        sum[p] += val;
}
ll Sum(int p) {
    ll ans = 0;
    for (; p <= n; p += (p & -p))
        ans += sum[p];
    return ans;
}
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i].v);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    ll last = 0;
    for (int i = 1; i <= n; i++) {
        a[i].v -= last;
        ds.push_back(i);
        Add(a[i].id, 1);
        Inc(a[i].id, a[i].v);
        if (Num(1) - Num(a[i].id) == a[i].id - 1) {
            last = a[i].v + last;
            res[a[i].id] += a[i].v * (n - a[i].id - Num(a[i].id + 1)) + Sum(a[i].id);
            for (auto j: ds)
                Inc(a[j].id, -a[j].v);
            ds.clear();
        }
    }
    for (int i = 1; i <= n; i++)
        writeln(res[i]);
}

