#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
void Digvijay()
{
   int n;
   cin>>n;
   vector<int> a(n);
   for(auto& it:a)cin>>it;
   map<int,int> mp;
   for(auto it:a)mp[it]++;
   if(mp[0]>1)
   {
       cout<<0<<"\n";
   }
   else
   {
       bool ok=true;
       for(auto it:a)
       {
           if(it==0)continue;
           if(mp[it]!=2)ok=false;
       }
       if(ok)
       {
           int ans=1;
           for(auto it:mp)
           {
               //cout<<ans<<"\n";
               if(it.second)
               ans*=it.second;
               ans%=mod;
           }
           cout<<ans<<"\n";
       }
       else cout<<0<<"\n";
   }
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