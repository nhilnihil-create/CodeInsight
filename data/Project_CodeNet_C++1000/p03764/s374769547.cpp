#include <iostream>
#include <vector>
#include <string>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P; const ll mod=1e9+7;

int main() {
  ll n,m; cin>>n>>m;
  ll x[n], y[m];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<m;i++) cin>>y[i];

  ll xx=0, yy=0;
  for(int i=0;i<n;i++) {
    xx+=x[i]*(i - (n-1-i));
  }
  xx%=mod;
  for(int j=0;j<m;j++) {
    yy+=y[j]*(j - (m-1-j));
  }
  yy%=mod;
  //cout<<xx<<" "<<yy<<endl;
  cout<<xx*yy%mod<<endl;
}
