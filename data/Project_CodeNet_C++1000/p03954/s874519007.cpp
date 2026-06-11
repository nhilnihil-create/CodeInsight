#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define For(i,x,y)for(i=x;i<=y;i++)
#define Down(i,x,y)for(i=x;i>=y;i--)
#define Memc(i,j)memcpy(i,j,sizeof i)
bool bo[N];
int a[N],n;
bool check(int num)
{
	int i;
	For(i,1,(n<<1)-1)bo[i]=a[i]>num/*,printf("%d ",bo[i]);
	printf("\n")*/;
	For(i,1,n-1)
	{
		if(bo[n+i]==bo[n+i-1]&&bo[n+i])return 0;
		if(bo[n+i]==bo[n+i-1]&&!bo[n+i])return 1;
		if(bo[n-i]==bo[n-i+1]&&bo[n-i])return 0;
		if(bo[n-i]==bo[n-i+1]&&!bo[n-i])return 1;
	}
	return bo[n]^(n&1);
}
int main()
{
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	int i,left=0,right,mid;
	scanf("%d",&n);
	right=(n<<1)-1;
	For(i,1,(n<<1)-1)scanf("%d",&a[i]);
	while(left<right)
	{
		/*printf("%d %d\n",left,right);*/
		mid=(left+right)>>1;
		if(check(mid))right=mid;
		else left=mid+1;
	}
	printf("%d",left);
	return 0;
}