#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
const int N=100005;
LL a[N];
LL Get_gcd(LL x,LL y)
{
    if (x>y) swap(x,y);
    if (!x) return y; else return Get_gcd(y%x,x);
}
int check(int n)
{
    int i,f0=0,f1=0;LL sum=0;
    for (i=1;i<=n;i++)
    {
        if (a[i]%2==0) f0++; else if (a[i]==1) f1=1;
        sum+=a[i];
    }
    if ((sum-n)%2) return 1;
    if (f1) return 0;
    if (f0==n-1) return -1; else return 0;
}
void work(int n)
{
    int i;LL gcd=0;
    for (i=1;i<=n;i++) {if (a[i]%2) a[i]--;gcd=Get_gcd(gcd,a[i]);}
    for (i=1;i<=n;i++) a[i]/=gcd;
}
int main()
{
   // freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int i,n;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%lld",&a[i]);
    if (n==1) {puts("Second");return 0;}
    if (n==2) {if ((a[1]+a[2])%2) puts("First"); else puts("Second");return 0;}
    int ans=check(n),ff=0;
    while (ans<0) {work(n);ans=check(n);ff^=1;}
    ans^=ff;
    if (ans) puts("First"); else puts("Second");
    
    return 0;
}
