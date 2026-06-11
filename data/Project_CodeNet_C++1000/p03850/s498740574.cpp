#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
const ll INF = 1e18;

int n;
int a[maxn], pos[maxn];
ll ans;
ll dp[maxn][3];

inline int calc(int x, int y){
	if(y & 1) return -x;
	return x;
}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		if(!i) pos[i] = 1;
		else{
			char c;
			scanf("%*c%c", &c);
			if(c == '-') pos[i] = -1;
			else pos[i] = 1;
		}
		scanf("%d", a + i);
	}
//	FOR(i, 0, n) cout << pos[i] << " " << a[i] << endl;
	REP(i, 0, n) FOR(j, 0, 3) dp[i][j] = -INF;
	dp[0][0] = 0;
	FOR(i, 0, n) FOR(j, 0, 3) if(dp[i][j] != -INF){
//		cout << "i = " << i << " j = " << j << " " << dp[i][j] << " " << calc(pos[i] * a[i], j) << endl;
		if(pos[i] == 1){
			REP(nj, 0, j)
				dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + calc(a[i], j));
		}
		else{
			if(j + 1 < 3)
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + calc(-a[i], j));
			REP(nj, 0, j)
				dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + calc(-a[i], j));
		}
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}