#include<bits/stdc++.h>
using namespace std;
long long st=1,ed=1.2e9;
long long arr[100005];
main()
{
	int t,r;
    long long a,b,mn=1e18;
    scanf("%d%lld%lld",&t,&a,&b);
    for(int i = 0;i < t;i++)
    {
        scanf("%lld",&arr[i]);
    }
    while(st<=ed)
    {
        long long md=(st+ed)/2;
        long long co=0,ck=0;
        long long s=0;
        for(int i = 0;i < t;i++)
        {
            co+=(max(arr[i]-b*md,s)+(a-1-b))/(a-b);
            if(co>md)
            {
                ck=1;
                break;
            }
        }
        //printf("\n\n");
        if(co>md || ck==1)
        {
            st=md+1;
        }
        else
        {
            mn=min(mn,md);
            ed=md-1;
        }
    }
    printf("%lld",mn);
}
