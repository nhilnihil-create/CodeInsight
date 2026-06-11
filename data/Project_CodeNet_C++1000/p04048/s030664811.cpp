#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
#define mod 1000000007
ll n,m,i,j,k,l,t,a,b;
int main()
{
    scanf("%lld %lld",&n,&m);
    j=2*m;
    if(j==n)
    {
        printf("%lld\n",n+m);
        return 0;
    }
    if(j<=n)
    {
        t=n+j;
        a=m;
        b=n-j;
        while(b>0 && a%b!=0)
        {
            n=a/b;
            n*=b;
            t+=(n*2);
            n=a%b;
            a=b;
            b=n;
        }
        n=a/b;
        m=((n-1)*2)+1;
        t+=(m*b);
        printf("%lld\n",t);
    }
    else
        {
          t=n+((n-m)*2);
          a=n-m;
          b=n-((n-m)*2);
           while(b>0 && a%b!=0)
        {
            n=a/b;
            n*=b;
            t+=(n*2);
            n=a%b;
            a=b;
            b=n;
        }
        n=a/b;
        m=((n-1)*2)+1;
        t+=(m*b);
        printf("%lld\n",t);
        }
}
