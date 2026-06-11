#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int n;
   cin>>n;
   int prime[1001]={0};
   prime[0]=1;
   prime[1]=1;
   for(int i=2;i*i<1001;i++)
   {
       if(!prime[i])
       {
           for(int j=i*i;j<=1000;j+=i)
           {
               prime[j]=1;
           }
       }
   }
   vector<int> p_fact(1001,0);
   for(int i=1;i<=n;i++)
   {
       int val=i;
       while(val%2==0)
       {
           p_fact[2]++;
           val/=2;
       }
       for(int j=3;j*j<=val;j+=2)
       {
           while(val%j==0)
           {
               p_fact[j]++;
               val/=j;
           }
       }
       if(val>2)p_fact[val]++;
   }
   int ans =1;
   int mod=1e9+7;
   for(int i=2;i<=n;i++)
   {
       if(prime[i]==0)
       {
           ans*=(p_fact[i]+1);
           ans%=mod;
       }
   }
   cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}