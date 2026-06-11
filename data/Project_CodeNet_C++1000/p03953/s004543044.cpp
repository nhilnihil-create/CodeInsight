#include <iostream>
#include <cstdio>
using namespace std;

long long N, M, K, x[1000010], p[1000010], a, last, ans[100010], P[100010];

int main(){
	scanf("%lld", &N);
	for(int i=1; i<=N; i++)	scanf("%lld", &x[i]);
	for(int i=N; i; i--)	x[i]-=x[i-1], p[i]=i;
	scanf("%lld%lld", &M, &K);
	for(int i=1; i<=M; i++){
		scanf("%lld", &a);
		swap(p[a], p[a+1]);
	};
	for(int i=1; i<=N; i++)	ans[i]=i, P[i]=p[i];
	while(K){
		if(K&1)	
			for(int i=1; i<=N; i++)
				ans[i]=p[ans[i]];
		for(int i=1; i<=N; i++)
			P[i]=p[P[i]];
		for(int i=1; i<=N; i++)
			p[i]=P[i]; 
		K>>=1; 
	}
	for(int i=1; i<=N; i++){
		last+=x[ans[i]];
		printf("%lld\n", last);
	}
	return 0;
}