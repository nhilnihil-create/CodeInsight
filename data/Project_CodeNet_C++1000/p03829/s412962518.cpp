#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int n,a,b;
   cin>>n>>a>>b;
   vector<int> arr(n);
   for(auto& it:arr)cin>>it;
   int ans=0;
   for(int i=1;i<n;i++)
   {
       int val=arr[i]-arr[i-1];
       if(val*a<b)ans+=val*a;
       else ans+=b;

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