#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;
int main(){
  int n;
  cin>>n;
  vector<ll> t(n);
  rep(i,n) cin>>t[i];
  if(n==1) cout<<t[0];
else{
  ll ans=lcm(t[0],t[1]);
  rep2(i,2,n) ans=lcm(ans,t[i]);
  cout<<ans;
}
return 0;
}