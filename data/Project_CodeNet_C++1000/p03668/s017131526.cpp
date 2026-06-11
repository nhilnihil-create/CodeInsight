#include <bits/stdc++.h>
using namespace std;

#define maxn 100002
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define REPD(i, r) for (int i=(int)r-1; i>=0; --i)
#define fi first
#define se second
#define mk make_pair
#define nil NULL
#define y0 y902
#define y1 y232
#define x0 x92
#define x1 x899
#define next asdfa
#define sz size
#define Debug(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<db, db> dd;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n;
vector<int> a[maxn];

int grundy(int u, int par) {
    int res = 0;
    REP(i, a[u].sz()) {
        int v = a[u][i];
        if (v==par) continue;
        res ^= (grundy(v, u)+1);
    }
    return res;
}

int main() {
    //freopen("treegame.inp", "r", stdin);
    //freopen("", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &n);
    FOR(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    if (grundy(1, 0)==0) printf("Bob");
    else printf("Alice");
}

