#include<cstdio>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000ll;
const int MAXN = 2010;

ll a[MAXN << 1], mn[MAXN][MAXN];

inline ll Min(ll a, ll b){return a < b ? a : b;}

inline void chkmin(ll& a, ll b){if (b < a) a = b;}

int main(){
	int N; ll x;
	scanf("%d %lld", &N, &x);
	for (int i = 1; i <= N; ++i){
		scanf("%lld", &a[i]), a[N + i] = a[i];
		mn[i][0] = a[i];
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j < N; ++j)	
			mn[i][j] = Min(mn[i][j - 1], a[N + i - j]);
	ll ans = Inf, tmp;
	for (int i = 0; i < N; ++i){
		tmp = x * i;
		for (int j = 1; j <= N; ++j)
			tmp += mn[j][i];
		chkmin(ans, tmp);
	}
	printf("%lld", ans);
	return 0;
}
