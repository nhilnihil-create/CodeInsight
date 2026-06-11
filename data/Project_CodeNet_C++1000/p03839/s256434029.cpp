#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;


int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  ll b=0,s=0,ans=0;
  rep(i,k) b+=a.at(i);
  for (int i=k;i<n;i++){
      if (a.at(i)>0) s+=a.at(i);
  } 
  for (int i=0;i+k<n;i++){
      ans=max(ans,s+max(b,0LL));
      if (a.at(i)>0) s+=a.at(i);
      if (a.at(i+k)>0) s-=a.at(i+k);
      b+=a.at(i+k);
      b-=a.at(i);
  }
  ans=max(ans,s+max(b,0LL));
  cout << ans << endl;
}
