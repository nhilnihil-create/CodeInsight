#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
   cin >> n;
   ll ans = 1e18;
   vector<ll> a(n);
   for(int i = 0;i<n;i++)cin >> a[i];
   for(int aaa = 0;aaa<2;aaa++)
   {
      if(aaa)for(auto &i:a)i = -i;
      ll sum = 0;
      ll now = 0;
      for(int i = 0;i<n;i++)
      {
         sum += a[i];
         if(i%2)//負になるようにする
         {
            now += max(0LL,sum-(-1));
            sum = min<ll>(-1,sum);
         }
         else//正になるようにする
         {  
            now += max(0LL,(1)-sum);
            sum = max<ll>(1,sum);
         }
      }
      ans = min<ll>(now,ans);
   }
   cout<<ans<<endl;
}