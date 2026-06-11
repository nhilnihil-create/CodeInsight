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
  ll N;
  cin>>N;
  ll a[N];
  vl b(100010,0);
  rep(i,N){
    cin>>a[i];
    b[a[i]]++;
  }
  ll ans=b[0]+b[1]+b[2];
  ll cnt=ans;
  for(int i=3;i<100010;i++){
    cnt-=b[i-3];
    cnt+=b[i];
    ans=max(cnt,ans);
  }
  cout<<ans<<endl;
}
