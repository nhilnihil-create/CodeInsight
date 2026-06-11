#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll>a(n);
  rep(i,n) cin >> a[i];
  ll ans=INF;
  
  for(int bit=0;bit<(1<<(n-1));bit++){
    vector<bool>tower(n-1);
    int cnt=0;
    rep(i,n-1){
      if(bit&(1<<i)){
        cnt++;
        tower[i]=true;
      }
      else tower[i]=false;
    }
    if(cnt<k-1)continue;
    ll sum=0;
    ll nowmax=a[0];
    rep(i,n-1){
      if(!tower[i]) nowmax=max(a[i+1],nowmax);
      else{
        sum+=max(0ll,nowmax-a[i+1]+1);
        nowmax=max(nowmax+1,a[i+1]);
      }
    }
    ans=min(ans,sum);    
  }
  cout << ans << endl;
  return 0;
}
