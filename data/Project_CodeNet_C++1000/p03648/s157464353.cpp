#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll K;
ll N=50;
ll A[52];
int main()
{
	scanf("%lld",&K);
	for(ll i=0;i<N;i++){
		A[(int)i]=N-1;
	}
	for(ll i=0;i<N;i++){
		A[(int)i]+=K/N;
	}
	for(ll i=0;i<(K%N);i++){
		for(ll j=0;j<N;j++){
			if(i==j){A[j]+=N;}
			else{A[j]-=1;}
		}
	}
	printf("%lld\n",N);
	for(int i=0;i<N;i++){
		printf("%lld",A[i]);
		if(i!=N-1)printf(" ");
	}
	printf("\n");
	return 0;
}
