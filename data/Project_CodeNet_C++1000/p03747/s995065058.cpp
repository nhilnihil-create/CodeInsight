#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct jie
{
    int x,w;
}mp[100005];
int a[100005],b[100005];
int main()
{
    int n,l,T,ans=0,i;
    scanf("%d %d %d",&n,&l,&T);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&mp[i].x,&mp[i].w);
    }
    for(i=0;i<n;i++)
    {
        if(mp[i].w==1)
        {
            ans+=(mp[i].x+T)/l;
        }
        else
        {
            ans+=(mp[i].x-T)/l;
            if((mp[i].x-T)%l<0)
            {
                ans--;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(mp[i].w==1)
        {
            a[i]=(mp[i].x+T)%l;
        }
        else
        {
            a[i]=((mp[i].x-T)%l+l)%l;
        }
    }
    sort(a,a+n);
    ans=(ans%n+n)%n;
    for(i=ans;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    for(i=0;i<ans;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
