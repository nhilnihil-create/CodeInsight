#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  string s;
  cin >> s;
  ll ans=INF,k=s.size();
  rep(i,26){
    bool a=false,b=true;
    ll cnt=INF;
    rep(j,s.size()){
      if(abc[i]==s[j]){
        a=true;
      }
      else{
        b=false;
      }
    }
    if(a){
      cnt=0;
      string S=s;
      ll l=k;
      while(!b){
        string t="";
        b=true;
        l--;
        rep(j,l){
          if(abc[i]==S[j]||abc[i]==S[j+1]){
            t+=abc[i];
          }
          else{
            t+='0';
            b=false;
          }
        }
        S=t;
        cnt++;
      }
    }
    ans=min(ans,cnt);
  }
  cout << ans << endl;
}