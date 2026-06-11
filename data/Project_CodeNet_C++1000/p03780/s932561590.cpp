#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[5005];

int main(){

	int N;

	ll K;

	scanf("%d %lld",&N,&K);

	int i;

	for(i=0;i<N;i++){
		scanf(" %lld",&a[i]);
	}

	sort(a,a+N);

	ll t=0ll;
	int ans=N;

	for(i=N-1;i>=0;i--){
		if(t+a[i]<K){
			t+=a[i];
		}
		else{
			ans=min(ans,i);
		}
	}
	printf("%d\n",ans);

	return 0;
}
