#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans=INF;
  ll cnt=0;
  ll k;
  vl sum(n,0);
  sum[0]=a[0];
  if(a[0]==0){
    cnt++;
    sum[0]=1;
  }
  FOR(i,1,n){
    sum[i]=a[i]+sum[i-1];
    if(sum[i]*sum[i-1]>=0){
      k=sum[i];
      sum[i]=-sum[i-1]/abs(sum[i-1]);
      cnt+=abs(k-sum[i]);
    }
  }
  ans=min(ans,cnt);
  cnt=0;
  if(a[0]==0){
    sum[0]=-1;
    cnt++;
  }
  else{
    k=a[0];
    sum[0]=-abs(a[0])/a[0];
    cnt+=abs(sum[0]-k);
  }
  FOR(i,1,n){
    sum[i]=sum[i-1]+a[i];
    if(sum[i]*sum[i-1]>=0){
      k=sum[i];
      sum[i]=-abs(sum[i-1])/sum[i-1];
      cnt+=abs(k-sum[i]);
    }
  }
  ans=min(ans,cnt);
  cout << ans << endl;
}