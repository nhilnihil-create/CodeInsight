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
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>
#include<random>



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
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;


vector<int>G[200020];
bool visited[200020];

int dp[100010][30];
vector<int>a;
int N, L, Q;
int func(int n,int k){
	if (dp[n][k] != 0)return dp[n][k];
	int pos = a[n];
	if (k == 0) {
		int nex = pos + L;
		auto itr = ub(a, nex);
		itr--;
		int res = itr - a.begin();
		dp[n][k] = res;
		return res;
	}
	else {
		int b = func(n, k - 1);
		int res = func(b, k - 1);
		dp[n][k] = res;
		return res;
	}
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	a.resize(N);
	REP(i, N) {
		cin >> a[i];
	}
	a.pb(INF);
	cin >> L >> Q;
	REP(i, Q) {
		int a, b; cin >> a >> b;
		a--, b--;
		if (a > b)swap(a, b);
		int ans = 0;
		bool ok = false;
		REPR(j, 29) {
			if (func(a, j) < b) {
				ans+=1<<j;
				a = func(a, j);
			}
		}
		ans++;
		//pe("ans:");
		print(ans);
	}
}
