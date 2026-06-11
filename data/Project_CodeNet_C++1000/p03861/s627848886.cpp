#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,n,p,q,ans=0;
    cin>>a>>b>>n;
    q=b/n;
    b=q*n;
    if(a==0) a=0;
    else if(a<=n) a=n;
    else if(a%n==0)  a=a;
    else
    {
      p=a/n;
      a=n*(p+1);
    }
    ans=((b-a)/n)+1;
    cout<<ans<<endl;
    return 0;
}
