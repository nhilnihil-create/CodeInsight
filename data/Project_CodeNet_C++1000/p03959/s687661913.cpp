/*#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
 
typedef long long ll;
const ll INF = LLONG_MAX - 100;
const ll mod = 1e9 + 7;
const int MAX_N = 5e5 + 5;
int dx[] = { -1LL,0,1LL,0 }, dy[] = { 0,1LL,0,-1LL };
vector<ll> prime;
 
ll inv[MAX_N], fac[MAX_N];
 
template <class T = ll> T in() { T x; cin >> x; return (x); }
inline ll GCD(ll a, ll b) { ll c; while (b != 0) { c = a % b; a = b; b = c; }return a; }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll POW(ll a, ll b) { ll c = 1LL; while (b > 0) { if (b & 1LL) { c = a * c%mod; }a = a * a%mod; b >>= 1LL; }return c; }
inline void _nCr() { fac[0] = 1LL; for (int i = 1LL; i < MAX_N; i++) { fac[i] = fac[i - 1LL] * i%mod; }for (int i = 0; i < MAX_N; i++) { inv[i] = POW(fac[i], mod - 2); } }
inline ll nCr(ll n, ll r) { return (fac[n] * inv[r] % mod)*inv[n - r] % mod; }
inline void PRI(ll n) { bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) { a[i] = 1LL; }for (int i = 2; i < n + 1LL; i++) { if (a[i]) { prime.pb(i); ll b = i; while (b <= n) { a[b] = 0; b += i; } } } }
 
typedef pair<int, pair<int, int>> edge;
 
class UnionFind {
private:
    vector<int> par;
public:
    vector<int> hen;
    UnionFind(int N) { par = vector<int>(N, -1LL); hen = vector<int>(N,0);}
    int find(int x);
    ll size(int x);
    void unite(int x, int y);
    bool same(int x, int y);
};

 
 
 
//----UnionFind-------------------------------
int UnionFind::find(int x) {
    if (par[x] < 0) return x;
    else return par[x] = find(par[x]);
}
 
ll UnionFind::size(int x) {
    return -par[find(x)];
}
 
void UnionFind::unite(int x, int y) {
    x = find(x);
    y = find(y);
    //大きい方に小さい方をくっ付ける
    if (size(x) < size(y)) swap(x, y);
    if (x == y) hen[x]++;
    else hen[x] += hen[y]+1;
    if (x == y) return;
    par[x] += par[y];
    par[y] = x;
}
 
bool UnionFind::same(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
}

signed main() {
    int n; cin >> n;
    int t[n], a[n];
    REP (i,n) cin >> t[i];
    REP (i,n) cin >> a[i];
    pair<int,int> mami[n];
    mami[0].first = mami[0].second = t[0];
    FOR (i,1,n) {
        if (t[i] < t[i-1]) {cout << 0 << endl; return 0;}
        else if (t[i] == t[i-1]) {
            mami[i].first = t[i]; mami[i].second = 1;
        } else {
            mami[i].first = mami[i].second = t[i];
        }
    }
    if (a[n-1] < mami[n-1].second || mami[n-1].first < a[n-1]) {cout << 0 << endl; return 0;}
    mami[n-1].first = mami[n-1].second = a[n-1];
    FOR (i,1,n) {
        if (a[n-i-1] < a[n-i]) {cout << 0 << endl; return 0;}
        else if (a[n-i-1] == a[n-i]) {
            mami[n-i-1].first = min(mami[n-i-1].first,a[n-i-1]);
            mami[n-i-1].second = max(mami[n-i-1].second,1ll);
        } else {
            if (mami[n-i-1].second <= a[n-i-1] && a[n-i-1] <= mami[n-i-1].first) mami[n-i-1].first = mami[n-i-1].second = a[n-i-1];
            else {cout << 0 << endl; return 0;}
        }
    }
    int ans = 1;
    REP (i,n) {
        int mul = mami[i].first - mami[i].second;
        if (mami[i].first < mami[i].second) {cout << 0 << endl; return 0;}
        ans *= mami[i].first - mami[i].second + 1;
        ans %= mod;
    }
    cout << ans << endl;
}
