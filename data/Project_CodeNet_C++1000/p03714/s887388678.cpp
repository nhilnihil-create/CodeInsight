#include<bits/stdc++.h>
using namespace std;
long long arr[1000000+10];
priority_queue<long long>que;
long long temparr1[1000000+10];
long long temparr2[1000000+10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)
	scanf("%lld",&arr[i]);
	long long sum = 0;
	for(int i=1;i<=n;i++) que.push(-arr[i]),sum+=arr[i],temparr1[i]=sum;
	for(int i=n+1;i<=2*n;i++) que.push(-arr[i]),sum+=arr[i]+que.top(),que.pop(),temparr1[i]=sum;
	while(!que.empty()) que.pop();sum = 0;
	for(int i=3*n;i>2*n;i--) que.push(arr[i]),sum+=arr[i],temparr2[i]=sum;
	for(int i=2*n;i>=n+1;i--) que.push(arr[i]),sum+=arr[i]-que.top(),que.pop(),temparr2[i]=sum;
	long long ans = 0x8000000000000000;
	for(int i=n;i<=2*n;i++)ans = max(ans,temparr1[i]-temparr2[i+1]);
	printf("%lld\n",ans);
	return 0;
}