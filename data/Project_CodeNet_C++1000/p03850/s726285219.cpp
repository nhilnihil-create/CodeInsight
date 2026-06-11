#include<iostream>
#include<algorithm>

using namespace std;

int const N = 1e5 + 41;
long long const INF = 1e18;

int n, a[N];
long long dp[N][4];


void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<4;++j){
			dp[i][j] = -INF;
		}
	}

	dp[0][0] = 0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=2;++j){
			long long sign = (j & 1 ? -1LL : 1LL);
			dp[i][j] = dp[i-1][j] + sign * a[i];
		}
		
		for(int j=1;j>=0;--j){
			dp[i][j] = max(dp[i][j], dp[i][j+1]);
		}
		if(a[i] < 0){
			for(int j=2;j>0;--j){
				long long sign = (j & 1 ? 1LL : -1LL);
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i] * sign);
			}
		}
	}
	printf("%lld\n",dp[n][0]);
}

void read(){
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;++i){
		char s;
		scanf(" %c %d",&s,&a[i]);
		if(s == '-'){
			a[i] = -a[i];
		}
	}
}

void prepare(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

int main(){
	prepare();
	read();
	solve();




	return 0;
}