#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll table[1005];


int main(){

	ll N;
	scanf("%lld",&N);

	for(ll i = 1; i <= N; i++){

		table[i] = 0;
	}

	for(ll i = 2; i <= N; i++){
		ll tmp = i;
		for(ll k = 2; k*k <= tmp; k++){
			if(tmp%k == 0){
				while(tmp%k == 0){
					table[k]++;
					tmp /= k;
				}
			}
		}
		if(tmp > 1){
			table[tmp]++;
		}
	}

	ll ans = 1;

	for(ll i = 1; i <= N; i++){

		ans *= (table[i]+1);
		ans %= MOD;
	}

	printf("%lld\n",ans);

	return 0;
}
