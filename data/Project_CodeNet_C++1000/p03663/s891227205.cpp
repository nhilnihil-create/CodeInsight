#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 10
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char st[MN+5];
int res1[MN+5],res2[MN+5];
int Solve(long long x)
{
    printf("? %lld\n",x);fflush(stdout);
    scanf("%s",st+1);return st[1]=='Y';
}
void Search(int l,int r)
{
    int mid,res;
    while(l<=r)
    {
        mid=l+r>>1;
        if(Solve(10LL*mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    printf("! %d\n",res);
}
int main()
{
  //  10^x  ->   > || 10^y(y<=x)
  //  10^x-1  ->  < || 10^y-1(y>=x)
    bool r1=1;
    for(int i=1,x=1;i<=9;++i)
    {
        x*=10;
        res1[i]=Solve(x);
        res2[i]=Solve(x-1);
        r1&=res1[i];
    }
    if(r1)
    {
        int l=1,r=1000000000;
      //  is 10^x  -> no-> > yes-><=
        for(int i=1,x=1;i<=9;++i)
        {
            x*=10;
            if(!res2[i]) l=x;
            else r=min(r,x-1);
        }
        Search(l,r);
    }
    else
    {
        int last=9,result=1000000000;
        for(;last&&!res1[last];--last,result/=10);++last;
        Search(result,result*10-1);
    }
    return 0;
}
