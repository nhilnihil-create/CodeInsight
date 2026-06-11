#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

void ok() {
	cout << "YES" << endl;
	exit(0);
}

void ng() {
	cout << "NO" << endl;
	exit(0);
}

vector<Int> edge[216000];
Int deg[216000];
Int A[216000];
Int a, b, n;

int dfs(int x, int last = -1) {
	if (deg[x] == 1) return A[x];
	Int mx = 0;
	Int sum = 0;
	for (auto to : edge[x]) {
		if (to == last)continue;
		Int u = dfs(to, x);
		mx = max(mx, u);
		sum += u;
	}
	Int flip = sum - A[x];
	Int res = sum - 2 * flip;
	if (flip < 0)ng();
	if (flip > min(sum - mx, sum / 2))ng();
	if (res < 0)ng();
	return res;
}

void solve()
{
	cin >> n;
	REP(i,n) cin >> A[i];
	REP(i,n-1) {
		cin >> a >> b; a--, b--;
		deg[a]++, deg[b]++;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	if (n == 2) {
		if (A[0] == A[1])ok();
		else ng();
	}
	int root = 0;
	while (deg[root] == 1) root++;
	if (dfs(root) == 0)ok();
	ng();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
