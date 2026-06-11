#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0,x,y,k;
    cin>>n;
    cin>>k;
    vector<int> v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
   }
   
   for(int i=0;i<n;i++)
   {   x=abs(k-v[i]);
       y=abs(v[i]-0);
       s+=min(2*x,2*y);
   }
   cout<<s<<"\n";
   return 0;
}
