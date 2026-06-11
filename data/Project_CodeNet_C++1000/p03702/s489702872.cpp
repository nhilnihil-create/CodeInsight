#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define N 100005
#define maxn 10005
#define INF 0x3f3f3f3f
#define mase(a,b) memset(a,b,sizeof(a))
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define DS DisputeSegement
using namespace std;
int Healthy[N];
int n;
int da,db;
bool isAce(LL At)
{
    LL damage=At*db;
    LL daTimes=0;
    for(int i=0;i<n;i++)
    {
        if(Healthy[i]>damage)
        {
            daTimes+=(LL)ceil((Healthy[i]-damage)/((da-db)*1.0));
            if(daTimes>At||daTimes<0)
                return false;
        }
    }
    return true;
}
int main()
{
    int maxH;
    int re;
    scanf("%d %d %d",&n,&da,&db);
    maxH=-INF;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Healthy[i]);
        maxH=MAX(Healthy[i],maxH);
    }
    LL l=1,r=maxH/db+1;
    while(l<=r)
    {
        LL mid=(l+r)/2;
        if(isAce(mid))
        {
            re=mid;
            r=mid-1;

        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d\n",re);
    return 0;
}
