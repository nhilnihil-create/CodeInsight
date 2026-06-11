#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int d[300][300];
int a[10];
int n,m,r;
void floyd()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(d[i][k]!=inf)
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
}
ll slove()
{
    ll ans=0;
     for(int i=1;i<r;i++){
     ans+=d[a[i]][a[i+1]];
   }
   return ans;
}
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>r;
   for(int i=1;i<=r;i++)
    cin>>a[i];
   memset(d,0x3f,sizeof d);
   for(int i=1;i<=m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       d[a][b]=d[b][a]=c;
   }
   floyd();
   ll ans=1e18;
   sort(a+1,a+1+r);
   do{
      ans=min(ans,slove());
   }while(next_permutation(a+1,a+1+r));

   cout<<ans<<endl;
   return 0;
}

