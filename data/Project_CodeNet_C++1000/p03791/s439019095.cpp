#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define NMAX 100005
#define MOD (int)(1e9+7)

using namespace std;

long long N,ans=1,dp[NMAX];
vector<int > p;

void solve(){
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
}

void answer(){
	printf("%lld\n",ans);
}

int main(){
	scanf("%lld",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld",&dp[i]);
	}
	solve();
	answer();

	return 0;
}