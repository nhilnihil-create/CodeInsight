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

// class segtree {
// public:
// 	int p = 2;
// 	vector<int> B;
// 	segtree(vector<int> &A) {
// 		while (A.size() > p) p *= 2;
// 		B = vector<int>(2*p-1,INF);
// 		for (int i = 0;i < A.size();i++) {
// 			B[p-1+i] = A[i];
// 		}
// 		for (int i = p - 2;i >= 0;i--) {
// 			B[i] = min(B[i*2+1],B[i*2+2]);
// 		}
// 	}

// 	void update(int pos) {
// 		pos += p-1;
// 		B[pos] = {'~',0};
// 		pos = (pos-1)/2;
// 		while (pos >= 0) {
// 			B[pos].first = min(B[pos*2+1].first,B[pos*2+2].first);
// 			B[pos].second = B[pos*2+1].second + B[pos*2+2].second;
// 			if (pos == 0) break;
// 			pos = (pos-1)/2;
// 		}
// 	}

// 	int getval(int start,int end,int k = 0,int l = 0,int r = -1) {
// 		if (r < 0) r = p - 1;
// 		if (start <= l && r <= end) {return B[k];}
// 		if (r < start || end < l) {return INF;}
// 		int L,R;
// 		L = getval(start,end,k*2+1,l,(l+r)/2);
// 		R = getval(start,end,k*2+2,(l+r)/2+1,r);
// 		return min(L,R);
// 	}
// };

int dis[100005];
int cnt[100005];
vector<vector<pair<int,bool>>> hen(100005);
int n;

pair<int,bool> dfs(int now, int here) {
	int count = 0;
	dis[now] = here;
	bool rd = false;
	REP (i,hen[now].size()) {
		if (-1 == dis[hen[now][i].first]) {
			pair<int,bool> x;
			x = dfs(hen[now][i].first,here+1);
			count += x.first;
			hen[now][i].second = x.second;
			if (hen[now][i].second) rd = true;
		}
	}
	cnt[now] = count + 1;
	if (now == n-1) rd = true;
	return {cnt[now],rd};
}

signed main() {
	REP (i,100005) dis[i] = -1;
	cin >> n;
	REP (i,n-1) {
		int a,b; cin >> a >> b; a--; b--;
		hen[a].push_back({b,false}); hen[b].push_back({a,false});
	}
	dfs(0,0);
	vector<int> sima;
	queue<int> p;
	p.push(0);
	while (!p.empty()) {
		int x = p.front(); p.pop();
		int has = cnt[x];
		REP (i,hen[x].size()) {
			if (hen[x][i].second) {
				has -= cnt[hen[x][i].first];
				p.push(hen[x][i].first);
			}
		}
		sima.push_back(has);
	}
	int man = (sima.size() + 1) / 2;
	int fen = 0, sun = 0;
	REP (i,sima.size()) {
		if (i < man) {
			fen += sima[i];
		} else {
			sun += sima[i];
		}
	}
	if (fen <= sun) cout << "Snuke" << endl;
	else cout << "Fennec" << endl;
}
