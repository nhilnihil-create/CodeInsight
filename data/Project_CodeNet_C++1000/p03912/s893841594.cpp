#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=acos(-1);
const ll INF=1e18;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n,m;
  cin >> n >> m;
  vl x(n),K(m),M(m,0);
  rep(i,n){
    cin >> x[i];
    K[x[i]%m]++;
  }
  sort(x.begin(),x.end());
  ll cnt=1;
  rep(i,n-1){
    if(x[i]==x[i+1]){
      cnt++;
    }
    else{
      M[x[i]%m]+=cnt/2;
      cnt=1;
    }
  }
  M[x[n-1]%m]+=cnt/2;
  ll ans=0;
  rep(i,m){
    if(i!=0&&2*i!=m){
    ll z=min(K[i],K[(m-i)%m]);
    ans+=z;
    M[i]=min(M[i],K[i]-z);
    K[i]-=z;
    K[(m-i)%m]-=z;
    }
    if(i==0||2*i==m){
      ans+=K[i]/2;
      K[i]-=(K[i]/2)*2;
    }
  }
  rep(i,m){
    M[i]=min(M[i],K[i]/2);
  }
  rep(i,m){
    if(M[i]>=1){
      ans+=M[i];
    }
  }
  cout << ans << endl;
}