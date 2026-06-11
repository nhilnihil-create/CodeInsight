#include <bits/stdc++.h>
using namespace std;
const int s = 2e5+10;
int arr[s];
long long pre[s];
int main()
{
	int n;
	long long sum,mn;
	while(~scanf("%d",&n)){
		mn=0xffffffffffffffl;
		sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		pre[0]=arr[0];
		for(int i=1;i<n;++i){
			pre[i]=pre[i-1]+arr[i];
		}
		for(int i=0;i<n-1;++i){
			mn=min(mn,abs(sum-2*pre[i]));
		}
		printf("%lld\n",mn);
	}
	return 0;
}
