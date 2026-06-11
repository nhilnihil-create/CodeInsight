#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

int main(){  
  ll n,capa;
  cin >> n >> capa;
  vector<ll> v[4];
  ll w=0;
  rep(i,n){ 
    int a,b; cin>>a>>b;
    if(i==0){w=a;}
    v[a-w].emplace_back(b);
  }
  rep(i,4){sort(v[i].rbegin(),v[i].rend());}

  vector<vector<ll>> r(4, vector<ll>(110,0));
  
  rep(i,4)rep(j,v[i].size()){
    r[i][j+1]=r[i][j]+v[i][j];
  }
  ll a=v[0].size()+1;
  ll b=v[1].size()+1;
  ll c=v[2].size()+1;
  ll d=v[3].size()+1;

  ll ans=0;
  rep(i,a)rep(j,b)rep(k,c)rep(l,d)if(capa>=i*w+j*(w+1)+k*(w+2)+l*(w+3)){
    ll tmp=r[0][i]+r[1][j]+r[2][k]+r[3][l];
    ans = max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}