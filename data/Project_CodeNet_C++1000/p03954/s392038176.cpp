#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+20;
int a[N],n;
bool check(int k)
{
	for(int i=0;i<n-1;i++)
	{
		if((a[n-i]<=k&&a[n-i-1]<=k)||(a[n+i]<=k&&a[n+i+1]<=k))return 1;
		if((a[n-i]>k&&a[n-i-1]>k)||(a[n+i]>k&&a[n+i+1]>k))return 0;
	}
	return a[1]<=k;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<(n<<1);i++)
	  scanf("%d",&a[i]);
	int l = 1,r=(n<<1)-1;
	while(l<r)
	{
		int mid = l + r >> 1 ;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n",l);
	return 0;
}