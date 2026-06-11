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
               int n,m;
               cin>>n>>m;
               int a[n+1];
               int b[n+1];
               memset(b,0,sizeof(b));
               b[1]=1;
               for(int i=1;i<=n;++i)
                    a[i] = 1;
               int count=0;
               int x,y;

               for(int i=1;i<=m;++i)
               {
                    cin>>x>>y;
                    if(b[x]==1)
                    {
                         b[y]=1;
                    }
                    a[x]--;
                    a[y]++;
                    if(a[x]==0)
                         b[x]=0;

               }
               for(int i=1;i<=n;++i)
               {
                    //cout<<b[i]<<" ";
                    if(b[i])
                         count++;
               }
               cout<<count;

       }
}
