//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int i,j,k;
main()
{
   int n,k;cin>>n>>k;int a[n];
   int b[n],c[n]={0};
   for(i=1;i<=n;i++)
   {
       cin>>a[i];
       b[i]=a[i];
       c[i]=i;
   }
   sort(b+1,b+n+1);
   vector<int> ans;
   for(i=1;i<n;i++)
   {
       if(a[i]+a[i+1]>=k)
       {
           for(j=1;j<i;j++)
           {
               ans.push_back(j);
           }
           for(j=n-1;j>i;j--)
           {
               ans.push_back(j);
           }
     ans.push_back(i);
           break;
       }

   }
  // cout<<b[n]<<endl;
   if(ans.size()==0) cout<<"Impossible"<<endl;
   else
   {
       cout<<"Possible"<<endl;
       for(i=0;i<ans.size();i++)
       {
           cout<<ans[i]<<endl;
       }
   }
}
