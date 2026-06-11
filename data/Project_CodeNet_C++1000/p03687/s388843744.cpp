//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  string s;cin>>s;
  ll ans=INF;
  rep(i,26){
    char c=abc[i];
    ll part=0;
    ll count=0;
    rep(j,s.size()){
      if(s[j]==c)count=0;
      else count++;
      part=max(part,count);
    }
    ans=min(ans,part);
  }
  cout<<ans<<endl;
}
    