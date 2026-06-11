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
               int a[2*n];
               for(int i=0;i<2*n;++i)
                    cin>>a[i];
               sort(a,a+2*n);
               int count=0;
               for(int i=0;i<2*n;i+=2)
               {
                    count += a[i];
               }
               cout<<count;
       }
}
