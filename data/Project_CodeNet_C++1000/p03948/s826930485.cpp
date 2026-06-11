#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define inf 0x3f3f3f3f
int a[maxn];
using namespace std;
int main()
   {
       int n,t;
       scanf("%d%d",&n,&t);
       for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

        int maxx=0;
        int maxl=0;
        for(int i=n;i>=1;i--)
        {maxx=max(maxx,a[i]);
        maxl=max(maxl,maxx-a[i]);

        }

maxx=0;
int ans=0;

for(int i=n;i>=1;i--)
    {
        maxx=max(maxx,a[i]);
        if(maxx-a[i]==maxl)
           ans++;
   }
   printf("%d\n",ans);
   return 0;
   }

