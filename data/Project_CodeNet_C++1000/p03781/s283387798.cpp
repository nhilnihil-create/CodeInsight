#include <stdio.h>
int sum[200005];
int main()
{
	int n=0,i,j,k,s,t;
	sum[0]=0;
	for(i=1;sum[i-1]<=1e9;i++)
	sum[++n]=sum[i-1]+i;
	int x;
	while(~scanf("%d",&x))
	 {
	 	int l=1,r=n,mid;
	 	while(l<r)
	 	{
	 		mid=(l+r)/2;
	 		if(sum[mid]>=x) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	 }
	 return 0;
}