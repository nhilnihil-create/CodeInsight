#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define endl "\n"
using ll=long long;
using ld=long double;
using namespace std;
const ll mod= 1e9+7;
const ll INF = 1LL<<40;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

ll v1[110];
void comb(vector<vector <ll> > &v) {
	
	rep (i,0,v.size()) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	rep (k,1,v.size()) {
		rep (j,1,k) {
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}

int main(){
  ll n,a,b;
  ld ans=0;
  cin>>n>>a>>b;
  rep(i,0,n)cin>>v1[i];
  sort(v1,v1+n,greater<ll>());
  rep(i,0,a)ans+=v1[i];

  
  cout<<fixed<<setprecision(12)<<ans/a<<endl;
  ans/=a;

  vector<vector<ll> > v(n + 1, vector<ll>(n + 1, 0));
  comb(v);

  ll pos=-1;
  ll cnt=0,cnt2=0;
  ll ans2=0;
  ll x=v1[a-1];
  bool p=false;

  rep(i,0,n){
    if(!p&&v1[i]==x&&ans!=(ld)v1[i]){cnt++;p=true;pos=i;}
    else if(v1[i]==x&&ans!=(ld)v1[i])cnt++;
    
  }
  rep(i,0,n){
    if(ans==(ld)v1[i])cnt2++;
  }

  ans2+=v[cnt][a-pos];
  rep(i,a,min(b,cnt2)+1)ans2+=v[cnt2][i];
  cout<<ans2<<endl;
  //rep(i,0,n)cout<<v1[i]<<endl;
}
