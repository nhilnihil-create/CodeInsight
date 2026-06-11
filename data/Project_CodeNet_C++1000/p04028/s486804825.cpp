#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;

int k, n;
int memo[5005][5005];

int dp(int pos, int len){
	if(pos == k){
		if(len == n){
			return 1;
		}else{
			return 0;
		}
	}else{
		int &ret = memo[pos][len];
		if(ret == -1){
			ret = 0;
			ret = (dp(pos+1, max(0, len-1)))%mod + (2*dp(pos+1, len+1))%mod;
			ret%= mod;
		}
		return ret;
	}
}

int powMod(int x, int y){
	if(y == 0) return 1;
	else if(y == 1) return x;
	else{
		long long ret = powMod(x, y/2);
		ret = (ret*ret)%mod;
		if(y%2) ret = (ret*x)%mod;
		return ret;
	}
}

int main(){
	memset(memo, -1, sizeof memo);
	n = 0;
	scanf("%d", &k);
	getchar();
	while(getchar() != '\n') n++;

	long long ans = dp(0, 0);
	int tmp = powMod(2, mod-2);
	tmp = powMod(tmp, n);
	ans = (ans*tmp)%mod;
	printf("%lld\n", ans);

}