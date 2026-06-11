#include<bits/stdc++.h>
#define L long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define aa first
#define bb second
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,x[100010],y[100010];
char s[5];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	L k,l,u;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   if(i>1)
	     {
		  scanf("%s",s);
		  if(s[0]=='-')
		    y[i]=1;
		 }
	   scanf("%d",&x[i]);
	  }
	p=1e18;
	for(i=1,j=0,k=0,l=0,u=0;i<=n;i++)
	  {
	   if(y[i])
	     {
	      if(!j)
	        j=1,k=0;
	      else
	        p=min(p,k+l),k=0;
	      l+=u;
	      u=x[i];
		 }
	   k+=x[i];
	  }
	if(j)
	  p=min(p,k+l);
	if(p>1e17)
	  p=0;
	else
	  p*=-2;
	for(i=1;i<=n;i++)
	  p+=x[i];
	printf("%lld\n",p);
	return 0;
}
