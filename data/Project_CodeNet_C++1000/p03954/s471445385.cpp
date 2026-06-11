#include<bits/stdc++.h>
#define rap(i,first,last) for(int i=first;i<=last;++i)
using namespace std;
const int maxN=2333333;
const int INF=114514233;
int N;
int arr[maxN];
bool boo[maxN];
bool check(int middle)
{
	rap(i,1,N*2-1)
	boo[i]=(arr[i]>=middle);
	int len1=INF,len0=INF;
	rap(i,1,N*2-2)
	if(boo[i]==boo[i+1])
	{
		if(boo[i])
		len1=min(len1,min(abs(N-i),abs(N-i-1)));
		else
		len0=min(len0,min(abs(N-i),abs(N-i-1)));
	}
	if(len1!=INF||len0!=INF)return len1<len0;
	return (N&1)==boo[N];
}
int main()
{
	scanf("%d",&N);
	rap(i,1,N*2-1)scanf("%d",&arr[i]);
	int l=-1,r=N*2,mid,answer=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			answer=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d",answer);
	return 0;
}