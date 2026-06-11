#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int p[100000];
//long long int x[1000000000]={0};

int main()
{
    long long int n,i,a[100000],ans,q;
   // cin>>n;
   map<ll,ll>x;
   scanf("%lld",&n);
    ans=0;q=0;
    for(i=0;i<n;i++)
    {
       // cin>>a[i];
       scanf("%lld",&a[i]);
        x[a[i]]++;
        if(x[a[i]]==2)
        {
            p[q++]=a[i];
        }

    }
    sort(p,p+q);
   if(q>=2)
     {
         if(x[p[q-1]]>=4)
            ans=p[q-1]*p[q-1];
         else
            ans=p[q-1]*p[q-2];
     }
   else if(q==1&&x[p[0]]>=4)
     ans=p[0]*p[0];
   else
    ans=0;

   // cout<<ans<<endl;
   printf("%lld\n",ans);
}
