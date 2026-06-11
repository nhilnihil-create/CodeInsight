# include <bits/stdc++.h>

using namespace std;

# define int long long

int d,s,h,q,n,p;

signed main()
{
 	scanf("%lld%lld%lld%lld\n",&q,&h,&s,&d);
  	scanf("%lld\n",&n);
  	p=min(min(q*8,h*4),s*2);
  	if(d<p){
     	if(n%2==1)printf("%lld\n",(n-1)/2*d+p/2);
      	else printf("%lld\n",n/2*d);
    }
    else printf("%lld\n",p/2*n);
    return 0;
}