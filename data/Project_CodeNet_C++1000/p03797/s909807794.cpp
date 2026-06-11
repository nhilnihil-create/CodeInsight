#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	ll N,M;
	scanf("%lld %lld",&N,&M);

	if(N >= M/2){

		printf("%lld\n",M/2);

	}else{

		ll ans = N;  //Nを前部使う
		M -= 2*N;

		ans += M/4; //c4個でScc1つができる

		printf("%lld\n",ans);
	}

	return 0;
}
