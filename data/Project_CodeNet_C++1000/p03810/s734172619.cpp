#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define N 110000
using namespace std;
int n,a[N],cnt;
int p1,p2; 
int main()
{
//	freopen("Decrementing.in","r",stdin);
//	freopen("Decrementing.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(;;)
    {
        for(int i=1;i<=n;i++)
        if(a[i]&1)++p1;
        else ++p2;
		if(p2&1)break;
        else if(p1>=2){++cnt;break;}
        bool flag=0;
        for(int i=n;i;i--)
        if(a[i]&1){
		  if(a[i]==1)flag=1;
		  else --a[i];
		  break;
        }
        if(flag){++cnt;break;}
        int gd=a[1];
        for(int i=2;i<=n;i++)gd=__gcd(gd,a[i]);
        for(int i=1;i<=n;i++)a[i]/=gd;
        ++cnt,p1=p2=0;
    }
    if(n==1||(cnt&1))puts("Second");
    else puts("First");
    return 0;
}