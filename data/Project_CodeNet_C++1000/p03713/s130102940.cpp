#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	ll H,W;
	scanf("%lld %lld",&H,&W);

	if(H%3 == 0 || W%3 == 0){

		printf("0\n");
		return 0;
	}

	ll ans = min(H,W); //縦に3つor横に3つ

	for(int right = 0; right <= W-2; right++){
		ll base = H*(right+1);

		ll A = (W-(right+1))*(H/2);
		ll B = (W-(right+1))*(H/2);
		if(H%2 == 1){

			B += (W-(right+1));
		}
		ll tmp = max(base,B)-min(base,A);
		ans = min(ans,tmp);
	}

	for(int under = 0; under <= H-2; under++){

		ll base = W*(under+1);

		ll A = (H-(under+1))*(W/2);
		ll B = (H-(under+1))*(W/2);

		if(W%2 == 1){

			B += (H-(under+1));
		}
		ll tmp = max(base,B)-min(base,A);
		ans = min(ans,tmp);
	}

	printf("%lld\n",ans);

	return 0;
}
