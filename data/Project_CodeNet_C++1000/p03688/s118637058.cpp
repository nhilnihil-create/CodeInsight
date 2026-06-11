#include<bits/stdc++.h>
using namespace std;
int a[100010],n;
int main()
{
	scanf("%d",&n);
    int mn=n+1,mx=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    if(mx>mn+1) 
    {
    	printf("No\n");
    	return 0;
	}
    if(mx==mn)
    {
        if(mn==n-1)
        {
        	printf("Yes\n");
        	return 0;
		}
        if(2*mn<=n)
        {
        	printf("Yes\n");
        	return 0;
		}
        else
        {
        	printf("No\n");
        	return 0;
		}
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++) 
		cnt+=(a[i]==mn);
        if(mn<cnt)
        {
        	printf("No\n");
        	return 0;
		}
        if(n-cnt<2*(mx-cnt))
        {
        	printf("No\n");
        	return 0;
		}
        else
        {
        	printf("Yes\n");
        	return 0;
		}
    }
    return 0;
}