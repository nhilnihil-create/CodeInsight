#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int k,s;
   cin>>k>>s;
   int ans=0;
   for(int y=0;y<=k;y++)
   {
       int val=s-y;
       for(int j=0;j<=k;j++)
       {
           if((val-j)<=k&&(val-j)>=0)
           {
               //cout<<s<<" "<<y<<" "<<j<<" "<<s-y-j<<"\n";
               ans++;
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