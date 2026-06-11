#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	REP(i, 0, n) scanf("%d", &a[i]);

	ll ans[2][n];
	REP(i, 0, n) ans[0][i] = i+1;
	REP(i, 0, n) ans[1][i] = 1e9-i;

	REP(i, 0, n) ans[1][a[n-i-1]-1] -= i;

	int pre0 = 1e9+1, pre1 = 0;
	for(int i=n-1; i>=0; i--){
		int move = std::min(pre0-1-ans[0][i], ans[1][i]-pre1-1);
		ans[0][i] += move;
		ans[1][i] -= move;
		pre0 = ans[0][i];
		pre1 = ans[1][i];
	}	

	REP(i, 0, n) printf("%ld ", ans[0][i]);puts("");
	REP(i, 0, n) printf("%ld ", ans[1][i]);puts("");
	return 0;
}


