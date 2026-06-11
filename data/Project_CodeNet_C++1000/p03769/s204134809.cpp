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

#define maxn
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

ll k;
vector<int> res;

vector<int> build(ll k, int t=1) {
    if (k==0) return {};
    if (k%2!=0) {
        vector<int> tmp = build(k/2, t+1);
        tmp.insert(tmp.begin()+tmp.sz()/2, t);
        tmp.push_back(t);
        return tmp;
    }
    else {
        vector<int> tmp = build(k-1, t+1);
        tmp.insert(tmp.begin(), t);
        tmp.push_back(t);
        return tmp;
    }
}

int main() {
    //freopen("goodstr.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    res = build(k);
    cout << res.sz() << '\n';
    REP(i, res.sz()) cout << res[i] << ' ';
}

