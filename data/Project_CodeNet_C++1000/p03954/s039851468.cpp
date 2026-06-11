#include<cstdio>
using namespace std;

const int N=1e5+10;
int A[N*2],n;

bool judge(int k)
{
    if(A[n-1]<=k&&A[n]<=k) return 1;
    if(A[n-1]>k&&A[n]>k) return 0;
    if(A[n]<=k&&A[n+1]<=k) return 1;
    if(A[n]>k&&A[n+1]>k) return 0;
	for(register int i=1;i<n;i++)
	{
		if(A[n+i]<=k&&A[n+i+1]<=k) return 1;
		if(A[n+i]>k&&A[n+i+1]>k) return 0;
		if(A[n-i-1]<=k&&A[n-i]<=k) return 1;
		if(A[n-i-1]>k&&A[n-i]>k) return 0;
	}
	return (A[1]<=k);
}

signed main()
{
	scanf("%d",&n);
	for(register int i=1;i<2*n;i++)
		scanf("%d",A+i);
	int L=1,R=2*n-1;
	while(R-L>1)
	{
		int mid=(L+R)>>1;
		if(judge(mid)) R=mid;
		else L=mid;
	}
	printf("%d\n",R);
	return 0;
}