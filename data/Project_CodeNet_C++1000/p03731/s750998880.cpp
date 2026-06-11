#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

ll N,T;
ll A[SIZE];

int main(){

	scanf("%lld %lld",&N,&T);

	ll ans = 0;

	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		if(i == 0)continue;

		ans += min(T,A[i]-A[i-1]);
	}

	ans += T;

	printf("%lld\n",ans);

	return 0;
}
