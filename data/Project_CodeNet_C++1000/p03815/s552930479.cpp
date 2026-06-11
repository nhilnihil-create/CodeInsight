#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	ll X;
	scanf("%lld",&X);

	ll ans = 2*(X/11);
	X %= 11;

	if(X == 0){

		printf("%lld\n",ans);
		return 0;
	}

	if(X <= 6){

		ans++;
	}else{

		ans += 2;
	}

	printf("%lld\n",ans);

	return 0;
}
