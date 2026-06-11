#include <cstdio>
#include <vector>
#define NMAX 100005
#define MOD (int)(1e9+7)

using namespace std;

long long N,ans=1,dp[NMAX];
vector<int > p;

int main(){
	scanf("%lld",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld",&dp[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		int k = p.size()+1;
		if(dp[i] >= 2*k-1){
			p.push_back(dp[i]);
			ans *= (k);
		}else{
			ans = ans * (k);
		}
		ans = ans % MOD;
	}
	printf("%lld\n",ans);

	return 0;
}