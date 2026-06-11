// https://blog.csdn.net/forever_shi/article/details/83189155 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,j,ans,a[N];
int main()
{
    scanf("%d",&n);
    for (register int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
	reverse(a+1,a+n+1);	
    for (register int i=1; i<=n; ++i)
    if (i+1>a[i+1])
	{
    	j=i+1,ans=0; 
		while (a[j]==i) ans++,j++;
		if (ans%2==1 || (a[i]-i)%2==1) puts("First");
		else puts("Second");
		return 0;
    }
}