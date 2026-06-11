#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<58;
const ll mod=1e9+7;

int main(){
  ll i,j;
  ll n,m;
  cin>>n>>m;
  VI x(n),y(m);
  for(i=0;i<n;i++) cin>>x[i];
  for(i=0;i<m;i++) cin>>y[i];
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ll a=0,b=0;
  for(i=0;i<n;i++) a-=x[i]*(n-1-i-i);
  for(i=0;i<m;i++) b-=y[i]*(m-1-i-i);
  cout<<(a%mod)*(b%mod)%mod<<endl;
  return 0;
}