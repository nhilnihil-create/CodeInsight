#include<bits/stdc++.h>
#define rep(i,k,n) for(int i =k;i<n;i++)
#define INF 1e15
typedef long long ll;
using namespace std;
int main()
{

  int n;
  ll x;
  cin >> n >> x;
  
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  
  vector<vector<ll>>cost(n,vector<ll>(n,INF));
  rep(i,0,n)cost[i][0]=a[i];
  rep(i,1,n){
     rep(j,0,n){
        cost[j][i]=min(cost[j][i-1],a[(j-i+n)%n]);
     }
  }
  ll ans = INF;
  rep(i,0,n){
    ll sum=0;
rep(j,0,n){
    sum+=cost[j][i];
}
    ans=min(ans,sum+i*x);
  }
   
  cout << ans << endl;
}