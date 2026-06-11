#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,t;
     cin>>n>>t;
     long long ans=0;
     int c=0;
     vector<int>a(n);
     cin>>a[0];
     for(int i=1;i<n;i++)
     {
         cin>>a[i];
         ans=a[i]-a[i-1];



     if(ans<t)
     {
         c+=ans;
     }
     else
     {
         c+=t;
     }
     }
     c+=t;

     cout<<c;
}
