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
            int n,k;
            cin>>n>>k;
            int x,y;
            cin>>x>>y;
            ll sum=0;
            for(int i=1;i<=min(n,k);++i)
            {
                 sum += x;
            }
            for(int i=k+1;i<=n;++i)
               sum += y;
            cout<<sum;
       }
}
