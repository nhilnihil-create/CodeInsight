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

int n, m;
int q;
vector<int> edge[108000];
int query[11][108000];
int a, b, v, d;
int c[108000];

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> v >> d >> c[i];
		query[d][v] = i;
	}
	for (int d = 10; d >= 1; d--) {
		for (int i = 1; i <= n; i++) {
			query[d - 1][i] = max(query[d - 1][i], query[d][i]);
			for (auto to : edge[i]) {
				query[d - 1][to] = max(query[d - 1][to], query[d][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << c[query[0][i]] << endl;
	}	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
