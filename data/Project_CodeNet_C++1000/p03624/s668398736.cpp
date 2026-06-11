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
  string s;
  cin>>s;
  bool exist[26];
  rep(i,26) exist[i]=false;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      if(s[i]==alp[j]) exist[j]=true;
    }
  }
  bool judge=false;
  char ans;
  for(int i=0;i<26;i++){
    if(!exist[i]){
      judge=true;
      ans=alp[i];
      break;
    }
  }
  if(!judge) cout<<"None"<<endl;
  else cout<<ans<<endl;
}