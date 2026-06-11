#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int C = 10;
int n;
int arr[N];
int op[N];
char tmp[5];
long long dp[N][C];
bool calc[N][C];
long long solve(int pos , int open){
	if(pos > n){
		return 0;
	}
	if(calc[pos][open]){
		return dp[pos][open];
	}
	long long res = -1LL << 50;
	if(op[pos + 1] == 1){
		res = max(res , solve(pos + 1 , open) + ((open & 1) ? -1 : 1) * arr[pos]);
		if(open){
			res = max(res , solve(pos + 1 , open - 1) + ((open & 1) ? -1 : 1) * arr[pos]);
		}
	}
	else{
		if(open + 1 < C){
			res = max(res , solve(pos + 1 , open + 1) + ((open & 1) ? -1 : 1) * arr[pos]);
		}
		if(open){
			res = max(res , solve(pos + 1 , open) + ((open & 1) ? -1 : 1) * arr[pos]);
		}
	}
	calc[pos][open] = 1;
	return dp[pos][open] = res;
}
int main(){
	scanf("%d" , &n);
	scanf("%d" , arr + 1);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%s" , tmp);
		op[i] = (tmp[0] == '-') ? -1 : 1;
		scanf("%d" , arr + i);
	}
	printf("%lld\n" , solve(1 , 0));
}
