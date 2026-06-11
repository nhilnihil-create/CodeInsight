#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<deque>
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
int n,tmp;
int a[maxn];
int state()
{
    int sum1=0,sum0=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)  sum1++;
        else        sum0++;
    }
    if(sum0&1&&sum1)  return 1;
    if(!(sum0&1)&&sum1>=2)  return 2;
    return 3;
}
int gcd(int x,int y)
{
    if(!y)  return x;
    return gcd(y,x%y);
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    if(n==1)
    {
        if(a[1]==1)  puts("Second");
        else         puts("First");
        return 0;
    }
    while(state()==3)
    {
        int pos;
        for(int i=1;i<=n;i++)
        {
            if(a[i]&1)
            {
                pos=i;
                break;
            }
        }
        if(a[pos]==1)
        {
            for(int i=1;i<=n;i++)
            {
                tmp^=((a[i]-1)&1);
            }
            if(tmp&1)  puts("First");
            else       puts("Second");
            return 0;
        }
        a[pos]--;
        int g=0;
        for(int i=1;i<=n;i++)  g=gcd(g,a[i]);
        for(int i=1;i<=n;i++)  a[i]/=g;
        tmp^=1;
    }
    if((state()==1)^tmp) puts("First");
    else            puts("Second");
    return 0;
}