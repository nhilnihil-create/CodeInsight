#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX=1e5+5;
const ll INF=1e9;
char re[20];
ll shi[11]={1},wei;
ll get_wei()
{
    printf("? %lld\n",INF);
    fflush(stdout);
    scanf("%s",re);
    fflush(stdout);
    if(re[0]=='Y')
    {
        for(ll i=1;i<=10;i++)
        {
            printf("? %lld\n",2LL*shi[i-1]);
            fflush(stdout);
            scanf("%s",re);
            if(re[0]=='Y')
                return i;
            fflush(stdout);
        }
    }
    else
    {
        for(ll i=1;i<=10;i++)
        {
            printf("? %lld\n",shi[i-1]);
            fflush(stdout);
            scanf("%s",re);
            if(re[0]=='N')
                return i-1;
            fflush(stdout);
        }
    }
}
ll get_an(ll wei)
{
    ll l=shi[wei-1],r=shi[wei]-1;
    ll an=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        printf("? %lld\n",10LL*mid);
        fflush(stdout);
        scanf("%s",re);
        if(re[0]=='Y')
        {
            an=mid;
            r=mid-1;
        }
        else
            l=mid+1;
        fflush(stdout);
    }
    return an;
}
int main()
{
    for(ll i=1;i<=10;i++)
        shi[i]=10LL*shi[i-1];
    wei=get_wei();
    printf("! %lld\n",get_an(wei));
    fflush(stdout);
    return 0;
}
