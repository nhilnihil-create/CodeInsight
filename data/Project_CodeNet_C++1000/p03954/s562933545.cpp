#include<cstdio>
using namespace std;
int N,A[200005],a[200005],l=1,r=200000,mid;
bool check(int n)
{
	int re=-1;
	for(int i=1;i<=N*2-1;i++)
	if(A[i]>=n)
	a[i]=1;
	else
	a[i]=0;
	for(int i=1;i<=N-1;i++)
	{
		if(a[N+i]==a[N+i-1])
		{
			re=a[N+i];
			break;
		}
		if(a[N-i]==a[N-i+1])
		{
			re=a[N-i];
			break;
		}
	}
	if(re!=-1)
	return re;
	else
	return a[1];
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N*2-1;i++)
	scanf("%d",&A[i]);
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		l=mid;
		else
		r=mid;
	}
	printf("%d",l);
	return 0;
}