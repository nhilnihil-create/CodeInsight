#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

vector<int32> G[112345];
int32 N;
vector<int64> A;

int64 dfs(int32 v, int32 p){
	if(G[v].size() == (p != -1)) return A[v];
	vector<int64> c;
	int64 sum = 0;
	REP(i, G[v].size()){
		if(G[v][i] == p) continue;
		c.push_back(dfs(G[v][i], v));
		sum += c[c.size()-1];
		if(c[c.size()-1] == -1) return -1;
	}
	sort(all(c), greater<int64>());
	int64 x = 2*A[v]-sum;
	if(A[v] > sum || (sum-x)%2) return -1;
	if(p == -1){
		if(G[v].size() > 1 && x != 0) return -1;
	}
	if((sum-x)/2 <= (sum-c[0]) && (sum-x)/2 <= sum/2) return x;
	return -1;
}

int main(void){
	cin >> N;
	A.resize(N);
	REP(i, N) cin >> A[i];
	REP(i, N-1){
		int32 a, b;
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(dfs(0, -1) == -1) cout << "NO" << endl;
	else cout << "YES" << endl;
}
