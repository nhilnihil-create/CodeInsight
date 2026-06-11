#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define maxn 100010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[maxn];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    sort(a+1,a+n+1,cmp);
    int x;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>=i)
        {
            x=i;
            break;
        }
    }
    int y=0;
    while(a[x+y+1]==x)  y++;
    if(((a[x]-x)&1)||(y&1))  puts("First");
    else                     puts("Second");
    return 0;
}