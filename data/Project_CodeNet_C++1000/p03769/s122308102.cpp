#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set> 
#include<cmath>
#include <numeric>
#include <array>
using namespace std;
//long long p = 998244353;
long long p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
int max_kai = 300000;
vel kai(max_kai, 1);
vel inv_kai(max_kai, 1);
int rui(int a, int n, int mod) {
    if (n == 0) { return 1 % mod; }
    int x = rui(a, n / 2, mod);
    x *= x; x %= mod;
    if (n % 2 == 1) { x *= a; x %= mod; }
    return x;
}
vel pa;
vel siz;
int root(int x) {
    if (pa[x] == -1) { return x; }
    int ans = root(pa[x]); pa[x] = ans;
    return ans;
}
bool mar(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) { pa[x] = y; }
    return (x != y);
}
int gcd(int x, int y) {
    if (x < y) { return gcd(y, x); }
    if (y == 0) { return x; }
    return gcd(y, x % y);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
void make_kai() {
    rep(i, max_kai - 1) {
        kai[i+1] = kai[i] * (i+1); kai[i+1] %= p;
        inv_kai[i+1] = modinv(kai[i+1], p);
    }
}
int com(int n, int r) {
    if ((n < 0) || (r < 0) || (r > n)){return 0;}
    int ans = (kai[n] * inv_kai[r])%p;
    return (ans * inv_kai[n - r]) % p;
}
vel uni(vel x) {
    if (x.size() == 0) { return x; }
    sor(x);
    int n = x.size();
    vel ans(1, x[0]);
    for (int j = 1; j < n; j++) {
        if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
    }
    x = ans;
    return x;
}
void pr(vel& v) {
    int n = v.size();
    if (n != 0) {
        cout << v[0];
        rep(i, n - 1) {
            cout << " " << v[i + 1];
        }
        cout << endl;
    }
}
int inf = 100000;
vel dijk(V<V<pin>>& way, int st) {
    int n = way.size();
    vel dist(n, inf); dist[st] = 0;
    priority_queue<pin,vector<pin>,greater<pin>> pq;
    pq.push(mkp(0, st));
    veb is_checked(n, false);
    while (!pq.empty()) {
        pin x = pq.top(); pq.pop();
        int pot = x.second;
        if (!is_checked[pot]) {
            is_checked[pot] = true;
            for (auto y : way[pot]) {
                int nex_dist = x.first + y.second;
                int nex_pot = y.first;
                if (dist[nex_pot] > nex_dist) {
                    dist[nex_pot] = nex_dist;
                    pq.push(mkp(nex_dist, y.first));
                }
            }
        }
    }
    return dist;
}
void sol(int n, int now_min, int now_max,vel &v) {
    if (n == 1) {
        return;
    }
    if (n % 2 == 1) {
        v.push_back(now_max); now_max--;
    }
    v.push_back(now_min); now_min++;
    sol(n / 2, now_min, now_max, v);
}
signed main() {
    int n; cin >> n;
    n++;
    vel v;
    sol(n,0,99,v);
    vel w = v; sor(w);
    int sz = v.size();
    rep(i, sz) { v.push_back(w[i] + 1); v[i]++; }
    cout << sz * 2 << endl;
    pr(v);
    return 0;
}
