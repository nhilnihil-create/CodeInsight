#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){


	ll N;
	scanf("%lld",&N);

	ll T = 1,A = 1;

	ll t,a;
	ll num_t,num_a;

	for(int i = 0; i < N; i++){

		scanf("%lld %lld",&t,&a);

		if(T%t == 0){

			num_t = T/t;
		}else{

			num_t = T/t+1;
		}
		if(A%a == 0){

			num_a = A/a;
		}else{

			num_a = A/a+1;
		}

		ll mult = max(1LL,max(num_t,num_a));

		T = mult*t,A = mult*a;
	}

	printf("%lld\n",T+A);

	return 0;
}
