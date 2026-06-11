#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000005
#define ll long long
using namespace std;
ll map[maxn];
int dx[9]={0,-1,-2,0,0,-1,-1,-2,-2};
int dy[9]={0,0,0,-1,-2,-1,-2,-1,-2};
ll ans;
ll h,w;
ll result[20];
int n;
int sum;
int main()
{ while(~scanf("%lld%lld%d",&h,&w,&n))
    {ll x,y;
    sum=0;
    ans=(h-2)*(w-2);
    memset(map,0,sizeof(map));
    memset(result,0,sizeof(result));
        for(int i=1;i<=n;i++)
    {scanf("%lld%lld",&x,&y);
for(int j=0;j<9;j++)
{
    ll xx=x+dx[j];
    ll yy=y+dy[j];
    if(xx>=1&&xx<=h-2&&yy>=1&&yy<=w-2)
    map[sum++]=(xx-1)*w+yy;
    }
    }

    sort(map,map+sum);


    int cnt=1;
    map[sum]=-1;
    for(int i=0;i<sum;i++)
    {
        if(map[i]==map[i+1])
    {
        cnt++;

    }
    else
    {
        result[cnt]++;
        cnt=1;
        ans-=1;
    }

}
printf("%lld\n",ans);
for(int i=1;i<=9;i++)
    printf("%lld\n",result[i]);
    }
return 0;
    }
