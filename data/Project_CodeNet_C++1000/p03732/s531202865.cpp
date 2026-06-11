#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define MOD 1e9+7
#define EPS 1e-8
#define INF 1e9+10
typedef long long ll;
using namespace std;
int main()
{
   int N,W;
   cin >> N >> W;
   vector<vector<ll>>w(4,vector<ll>());
   ll mw;
   rep(i,0,N){
       ll a,b;
       cin >> a >> b;
       if(i==0){mw=a;}
       w[a-mw].push_back(b);
   } 
   rep(i,0,4){
       sort(w[i].begin(),w[i].end(),greater<ll>());
   }
   vector<vector<ll>>imos(4,vector<ll>());
   
   rep(i,0,4){
       imos[i].push_back(0);
       rep(j,0,w[i].size()){
           imos[i].push_back(imos[i][j]+w[i][j]);
       }
   }
   ll ans=0;
   
   rep(i,0,imos[0].size()){
       rep(j,0,imos[1].size()){
           rep(k,0,imos[2].size()){
               rep(l,0,imos[3].size()){
                   ll sum=i*mw+j*(mw+1)+k*(mw+2)+l*(mw+3);
                   
                   if(sum<=W){
                       ans=max(ans,imos[0][i]+imos[1][j]+imos[2][k]+imos[3][l]);
                   }
               }
           }
       }
   }

   cout << ans << endl;
   return 0;
}

