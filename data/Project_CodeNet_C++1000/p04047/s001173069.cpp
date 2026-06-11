#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

   ll n,x,sum=0,mn;
   vector<int>v;
   cin>>n;
   n*=2;
   while(n--)
   {
       cin>>x;
       v.push_back(x);
   }
   sort(v.begin(),v.end());
   for(int i=0;i<v.size()-1;i++)
   {
     sum+=min(v[i],v[i++]);

   }
    cout<<sum;
}
