#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxN = 2e6 + 10;
int n;
long long val[maxN];
long long sum[maxN];

int main(){
	//freopen("b2.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1; i<=n;i++){
		sum[i] = sum[i-1] + val[i];
	//	printf("%d\n",sum[i] );
	}	
	long long res = 5e18;
	for(int i=1; i<=n-1;i++){
		long long t =abs(sum[i] - (sum[n] - sum[i]));

		res = min(res, t);

	}
	printf("%lld\n",res);


	return 0;
}