#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll table[SIZE];

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}

int main(){


	ll N;
	scanf("%lld",&N);

	for(ll i = 0; i < N; i++){

		table[i] = 0;
	}

	int tmp;
	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		table[tmp]++;
	}

	if(N%2 == 1 && table[0] != 1){

		printf("0\n");
		return 0;
	}
	for(ll i = 1; i <= N; i++){

		int loc = abs(N-2*i+1);
		if(loc == 0)continue;

		if(table[loc] != 2){

			printf("0\n");
			return 0;
		}
	}

	printf("%lld\n",mod_pow(2,N/2,MOD));

	return 0;
}
