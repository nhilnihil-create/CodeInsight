#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N,X;
ll A[SIZE];

int main(){

	scanf("%lld %lld",&N,&X);

	scanf("%lld",&A[0]);

	ll ans = 0;

	//より右のキャンディを多く食べるのが適切なはず

	for(int i = 1; i < N; i++){

		scanf("%lld",&A[i]);
		if(A[i]+A[i-1] > X){
			ll diff = (A[i]+A[i-1]-X);
			if(A[i] >= diff){

				A[i] -= diff;
				ans += diff;
			}else{

				ans += A[i];
				diff -= A[i];
				A[i] = 0;

				A[i-1] -= diff;
				ans += diff;
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
}
