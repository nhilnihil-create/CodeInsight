#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n,a[200005];
inline bool check(const int &k)
{
	if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))return 1;
	if((a[n-1]> k&&a[n]> k)||(a[n]> k&&a[n+1]> k))return 0;
	for(int i=1;i<n-1;i++)
    {
		if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))return 1;
		if((a[n+i]> k&&a[n+i+1]> k)||(a[n-i]> k&&a[n-i-1]> k))return 0;
	}
	return a[1]<=k;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n<<1;i++)scanf("%d",a+i);
	int l=1,r=(n<<1)-1;
	while(l<r)
    {
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
/*
我知道，我会，这是套路，二分变01。
然后陷入了沉默
30min之后看了眼sol
？？？？？
真就打表大胜利啊？
 
*/ 