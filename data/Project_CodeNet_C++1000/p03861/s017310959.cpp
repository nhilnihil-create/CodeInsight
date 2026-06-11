#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int a,b,x;
   cin>>a>>b>>x;
   int val1=a/x;
   if(a%x==0)val1--;
   int ans = (b/x)-val1;
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