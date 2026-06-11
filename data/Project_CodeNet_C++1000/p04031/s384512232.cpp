#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               int n;
               cin>>n;
               int a[n],sum=0,mid=0;
               for(int i=0;i<n;++i)
               {
                    cin>>a[i];
                    sum += a[i];
               }
               mid = sum/n;
               ll ans1=0;
               for(int i=0;i<n;++i)
               {
                    ans1 += (a[i]-mid)*(a[i]-mid);
               }
               mid++;
               ll ans2=0;
               for(int i=0;i<n;++i)
               {
                    ans2 += (a[i]-mid)*(a[i]-mid);
               }
               cout<<min(ans1,ans2);
       }
}