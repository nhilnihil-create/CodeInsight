#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=1e2+10;
const int mod=1e9+7;

bool flag[10];

bool Check(ll n)
{
    while(n)
    {
        if(flag[n%10])
            return false;
        n/=10;
    }
    return true;
}

int main()
{
    ll ans;
    int k;
    while(scanf("%lld%d",&ans,&k)!=EOF)
    {
        memset(flag,false,sizeof(flag));
        while(k--)
        {
            int x;
            scanf("%d",&x);
            flag[x]=true;
        }
        while(!Check(ans))
        {
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
