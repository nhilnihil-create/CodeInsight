#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[100010],cnt=0,id;
int gcd(int a,int b){if (!b) return a;return gcd(b,a%b);}
bool dfs()
{
    id=-1;cnt=0;
    for (int i=1;i<=n;i++) if (!(a[i]&1)) cnt++;else if (a[i]!=1) id=i;
    if (cnt&1) return 1;
    if (cnt!=n-1||(cnt==n-1&&id==-1)) return 0;
    a[id]--;int g=a[id];
    for (int i=1;i<=n;i++) g=gcd(g,a[i]);
    for (int i=1;i<=n;i++) a[i]/=g;
    return !dfs();
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    printf("%s",dfs()?"First":"Second");
}