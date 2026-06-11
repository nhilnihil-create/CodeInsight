#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int n,m;
    cin>>n;
    int t[n],a[n];
    for(int i=1;i<=n;i++)
      cin>>t[i],a[i]=t[i];
    cin>>m;
    while(m--)
    {
       int sum=0,p,x;
       cin>>p>>x;
       t[p]=x;
       for(int i=1;i<=n;i++)
       {
         sum+=t[i];
       }
       cout<<sum;
       nl;
       t[p]=a[p];
    }
    return 0;
}
