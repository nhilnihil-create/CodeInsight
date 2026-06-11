#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
//#define fill(x,y) memset(x,y,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int>P;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };


const int MAX = 500010;
const int MOD = 1000000007;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;


vector<int>G[100010];

int dfs(int s) {
	int res = 0;
	vector<int>v;
	for (auto ns : G[s]) {
		v.pb(dfs(ns));
	}
	VSORT(v);
	REP(i, v.size()) {
		res = max(res + 1, v[i]);
	}
	return res + 1;
}

signed main() {
	int N; cin >> N;
	REP(i, N - 1) {
		int a; cin >> a;
		a--;
		G[a].pb(i + 1);
	}
	print(dfs(0) - 1);
}