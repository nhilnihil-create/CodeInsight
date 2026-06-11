#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<deque>
#include<map>
#include<queue>
#define maxn 106
using namespace std;
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,mx;
int cnt[maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        mx=max(mx,x);
        cnt[x]++;
    }
    for(int i=mx;i>(mx+1)/2;i--)
    {
        if(cnt[i]<2)
        {
            puts("Impossible");
            return 0;
        }
    }
    if(mx&1&&cnt[(mx+1)/2]!=2)  puts("Impossible");
    else if(!(mx&1)&&cnt[mx/2]!=1)  puts("Impossible");
    else puts("Possible");
    return 0;
}