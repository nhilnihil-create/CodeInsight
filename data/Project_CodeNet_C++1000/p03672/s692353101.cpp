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
  string s;cin>>s;
  
  ll ans=s.size()-2;
  
  bool judge=true;
  
  while(true){
    judge=true;
    for(int i=0;i<ans/2;i++){
      if(s[i]!=s[(ans/2)+i]){
        ans-=2;
        judge=false;
        break;
      }
    }
    if(judge) break;
  }
  cout<<ans<<endl;
}
