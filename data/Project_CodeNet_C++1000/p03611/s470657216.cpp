#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
     int n;
     cin>>n;
     int a[n];
     map<int,int> m;
     for(int i=0;i<n;i++)
     {
      cin>>a[i];m[a[i]]++;
      
     }
      sort(a,a+n);
   
     int ans=INT_MIN;
      for(int i=0;i<n;i++)
      {
          int ans1=upper_bound(a,a+n,a[i]-1)-lower_bound(a,a+n,a[i]-1);
          int ans2=upper_bound(a,a+n,a[i]+1)-lower_bound(a,a+n,a[i]+1);
           ans=max(ans,ans1+m[a[i]]+ans2);
      }
      cout<<ans<<endl;
      return 0;


    
}