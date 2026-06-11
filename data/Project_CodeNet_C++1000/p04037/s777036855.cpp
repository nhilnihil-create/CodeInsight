#include <bits/stdc++.h>
using namespace std;
const int N   = 1e5+10;
#define rep(i,x,y) for (int i=x;i<=y;++i)
int n,a[N],flag;
signed main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	rep(i,1,n) if (i+1>a[i+1]) 
	{
		for (int j=i+1;a[j]==i;++j)flag^=1;
	    flag|=a[i]-i&1;
	    break;
	}
	return printf("%s",flag?"First":"Second"),0;	
}