#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define pb push_back
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
#define pos first
#define index second
#define mp make_pair
using namespace std;
#define int ll
const int inf=1e9+10;
const ll llinf=1e16+10;
const int maxn=2e5+10;
const int maxm=1e2+10;
const int mod=1e9+7;
int n;
char op[10];
int init()
{
    int k=10;
    for(int i=1;i<=9;i++)
    {
        printf("? %lld\n",k);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='N')
            return i;
        k=k*10;
    }
    k=9;
    for(int i=1;i<=9;i++)
    {
        printf("? %lld\n",k);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='Y')
            return i;
        k=k*10+9;
    }
    return 10;
}
signed main()
{
    //freopen("in.txt","r",stdin);
    int len=init();
    if(len==10)
    {
        printf("! %d\n",(int)1e9);
        return 0;
    }
    int ans=0;
    for(int i=1;i<len;i++)
    {
        int l=0,r=9,t=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            printf("? %d\n",ans*10+mid);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='Y')
            {
                t=max(t,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        ans=ans*10+t;
    }
    for(int i=(len==1?1:0);i<=9;i++)
    {
        printf("? %lld\n",((ll)ans*10+i)*10);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='Y')
        {
            ans=ans*10+i;
            break;
        }
    }
    printf("! %d\n",ans);
    return 0;
}