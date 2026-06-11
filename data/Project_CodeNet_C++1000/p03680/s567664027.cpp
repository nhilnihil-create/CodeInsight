#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N;cin>>N;
  ll a[N];
  rep(i,N) cin>>a[i];
  ll ans=0;
  vector<bool> judge(N+10,true);
  judge[1]=false;
  ll hv=1;
  for(int i=0;i<N;i++){
    hv=a[hv-1];
    ans++;
    if(!judge[hv]){
      ans=-1;
      break;
    }
    
    else if(hv==2) break;
    
    else{
      judge[hv]=false;
    }
  }
  cout<<ans<<endl;
}