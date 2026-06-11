#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){


	ll N,K;
	scanf("%lld %lld",&N,&K);

	int ans = K;

	for(int i = 1; i < N; i++){

		ans *= (K-1);
	}

	printf("%lld\n",ans);

	return 0;
}
