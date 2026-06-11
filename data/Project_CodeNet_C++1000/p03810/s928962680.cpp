#include<bits/stdc++.h>
using namespace std;
int n,x[100010];
inline int gcd(int n,int m)
{
    return m?gcd(m,n%m):n;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	while(1)
	  {
       for(i=1,j=0;i<=n;i++)
         if(!(x[i]&1))
           j++;
       if(j&1)
         break;
       if(n-j>1)
         {
          k^=1;
          break;
         }
       for(i=1;i<=n;i++)
         if(x[i]&1)
           {
            x[i]--;
            if(!x[i])
              break;
           }
       if(i<=n)
         {
          k^=1;
          break;
         }
       for(i=1,j=0;i<=n;i++)
         j=gcd(j,x[i]);
       for(i=1;i<=n;i++)
         x[i]/=j;
       k^=1;
      }
    if(k)
      printf("Second\n");
    else
      printf("First\n");
	return 0;
}
