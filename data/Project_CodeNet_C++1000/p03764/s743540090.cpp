#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m;
int x[100001],y[100001];
const ll MOD=(ll)1e9+7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin);
    freopen("out","w",stdout);
#endif
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=0;i<m;i++){
    cin>>y[i];
  }
  ll xsum=0,ysum=0;
  ll now=n-1;
  for(int i=n-1;i>=0;i--){
    xsum+=now*x[i];
    now-=2;
  }
  now=m-1;
  for(int i=m-1;i>=0;i--){
    ysum+=now*y[i];
    now-=2;
  }
  cout<<((xsum%MOD)*(ysum%MOD))%MOD<<"\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}