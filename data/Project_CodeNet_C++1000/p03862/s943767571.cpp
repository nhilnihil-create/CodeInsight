#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int n,x;
   cin>>n>>x;
   vector<int> a(n);
   for(auto& it:a)cin>>it;
   int ans=0;
   for(int i=0;i<n-1;i++)
   {
       int val=a[i]+a[i+1];
       if(val>x)
       {
           val-=x;
           if(val<=a[i+1])
           {
               ans+=val;
               a[i+1]-=val;
           }
           else
           {
               ans+=val;
               val-=a[i+1];
               a[i+1]=0;
               a[i]-=val;
           }
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