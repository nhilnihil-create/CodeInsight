#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
//#define int long long

int N, K;
vector<vector<int>> tree;

void rec(int v, int p, int d, vector<int> &depth) {
    depth[v] = d;
    for(auto u : tree[v]) {
        if(u == p) continue;
        rec(u, v, d + 1, depth);
    }
}

void solve() {
    cin >> N >> K;
    tree.assign(N, vector<int>());
    rep(i, N - 1) {
        int a, b; cin >> a >> b; a --; b --;
        tree[a].push_back(b); tree[b].push_back(a);
    }
    vector<int> depth(N);
    int ans = N;
    if(K % 2 == 0) {
        rep(v, N) {
            rec(v, -1, 0, depth);
            int cnt = 0;
            rep(u, N) {
                if(depth[u] > K / 2) cnt ++;
            }
            ans = min(ans, cnt);
        }
    } else {
        rep(v, N) {
            for(auto u : tree[v]) {
                rec(u, v, 0, depth); rec(v, u, 0, depth);
                int cnt = 0;
                rep(w, N) {
                    if(depth[w] > K / 2) cnt ++;
                }
                ans = min(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}