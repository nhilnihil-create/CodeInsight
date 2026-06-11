#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main()
{
	int n;
   cin >> n;
   vector<ll> t(n),a(n),b(n);
   for(int i = 0;i<n;i++)cin >> t[i];
   for(int i = 0;i<n;i++)cin >> a[i];
   vector<bool> is(n,true);

   is.front() = false;
   is.back() = false;
   if(n==1)
   {
      if(a[0]!=t[0])
      {
         cout<<0<<endl;
         return 0;
      }
   }
   for(int i = 0;i<n-1;i++)
   {
      if(t[i]!=t[i+1])
      {
         b[i+1] = t[i+1];
         is [i+1] = false;
         
      }
   }

   for(int i = 0;i<n-1;i++)
   {
      if(a[i]!=a[i+1])
      {
         
         b[i]=a[i];
         is [i] = false;
         
      }
   }
   ll mx = 0;
   for(int i = 0;i<n;i++)
   {
      mx = max(mx,b[i]);
      if(mx>t[i])
      {
         cout<<0<<endl;
         return 0;
      }
   }
   mx = 0;
   for(int i = n-1;i>=0;i--)
   {
      mx = max(mx,b[i]);
      if(mx>a[i])
      {
         cout<<0<<endl;
         return 0;
      }
   }
   ll ans = 1;
   for(int i = 0;i<n;i++)
   {
      if(is[i])
      {
         //cout<<i<<endl;
         (ans *= min(t[i],a[i]))%=MOD;
      }
   }
   cout<<ans<<endl;
}