#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   double sum=0;
   long long ans=0;
   cin>>n;
   int a[n],i;
   for(i=0;i<n;i++)
   {
       cin>>a[i];
       sum=sum+a[i];
   }
   sum=round(sum/n);
   for(i=0;i<n;i++)
   {
       ans=ans+pow((sum-a[i]),2);
   }
   cout<<ans<<endl;
    return 0;
}







