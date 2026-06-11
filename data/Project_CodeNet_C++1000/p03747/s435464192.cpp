#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,t,a[100010],b[100010],x[100010],w[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++)
	  {
       scanf("%d%d",&a[i],&b[i]);
       if(b[i]==1)
         x[i]=(a[i]+t)%m;
       else
         x[i]=((a[i]-t)%m+m)%m;
      }
    j=x[1];
    sort(x+1,x+n+1);
    for(i=2,k=0;i<=n;i++)
      if(b[i]!=b[1])
        if(b[1]==1)
          {
           if((a[i]-a[1]+m)%m<2*t)
             k=(k+(2*t-(a[i]-a[1]+m)%m-1)/m+1)%n;
          }
        else
          if((a[1]-a[i]+m)%m<=2*t)
            k=(k-(2*t-(a[1]-a[i]+m)%m)/m-1)%n;
    k=(k+n)%n+1;
    for(i=1;i<=n;i++)
      if(x[i]==j)
        break;
    for(j=i;;j=j%n+1,k=k%n+1)
      {
       w[k]=x[j];
       if(j%n+1==i)
         break;
      }
    for(i=1;i<=n;i++)
      printf("%d\n",w[i]);
	return 0;
}
