#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <memory.h>
#include <iomanip>
#include <cassert>
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
const ll MOD = 1000000007;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, a[maxn], pos[maxn];
ll fact[maxn];

ll POW(int n, int k) {
    if (k==0) return 1;
    ll tmp = POW(n, k/2);
    if (k%2==0) return tmp*tmp%MOD;
    return tmp*tmp%MOD*n%MOD;
}

ll C(int n, int k) {
    if (n<k) return 0;
    return fact[n]*POW(fact[k]*fact[n-k]%MOD, MOD-2)%MOD;
}

int main() {
    //freopen("11.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n+1) cin >> a[i];
    int x, y;
    FOR(i, 1, n+1) {
        if (pos[a[i]]!=0) {
            x = pos[a[i]];
            y = i;
            break;
        }
        pos[a[i]] = i;
    }
    fact[0] = 1;
    FOR(i, 1, n+1) fact[i] = (fact[i-1]*i)%MOD;
    //Debug(POW(24, 5));
    //Debug((POW(24, 11)%11));
    FOR(k, 1, n+1) {
        cout << (C(n+1, k) - C(x+n-y, k-1) + MOD*MOD)%MOD << '\n';
    }
}

