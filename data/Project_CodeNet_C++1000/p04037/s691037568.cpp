#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
int a[100010],n;
 
inline int rd()
{
    int x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
 
inline bool cmp(int x,int y) { return x>y; }
 
int main()
{
    n=rd();
    for (int i=1;i<=n;i++) a[i]=rd();
    sort(a+1,a+n+1,cmp);
    int hh=1;
    while (a[hh+1]>=hh+1) hh++;
    bool ans=1;
    for (int i=hh+1;a[i]==hh;i++) ans^=1;
    ans&=(a[hh]-hh+1)&1;
    puts(ans?"Second":"First");
    return 0;
}