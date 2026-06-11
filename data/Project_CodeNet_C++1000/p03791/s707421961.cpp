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
#define INF 1000000007

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
long long N,ans=1,dp[NMAX];
vector<int > p;
void solve(){
	for (int i = 0; i < N; ++i)
	{
		int k = p.size()+1;
		if(dp[i] >= 2*k-1){
			p.push_back(dp[i]);
		}else{
			ans = ans * (k);
			ans = ans % INF;
		}
	}
	for (int i = 1; i < p.size(); ++i)
	{
		ans = ans * (i+1);
		ans = ans % INF;
	}
}

void debug(){

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
	#ifdef DEBUG
	debug();
	#endif
	answer();

	return 0;
}