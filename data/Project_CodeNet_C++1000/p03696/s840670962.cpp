#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  st s,t="";
  cin >> n >> s;
  ll mn=0,mx=0,cnt=0,tnc=0;
  rep(i,n){
    if(s[i]=='('){
      cnt++;
    }
    else{
      cnt--;
    }
    mn=min(cnt,mn);
    if(s[n-1-i]=='('){
      tnc++;
    }
    else{
      tnc--;
    }
    mx=max(tnc,mx);
  }
  st a,b;
  rep(i,(ll)abs(mn)){
    a+='(';
  }
  rep(i,(ll)abs(mx)){
    b+=')';
  }
  cnt+=abs(mn)-abs(mx);
  t=a+s+b;
  if(cnt>0){
    rep(i,cnt){
      t+=')';
    }
    cout << t << endl;
  }
  else{
    rep(i,abs(cnt)){
      t='('+t;
    }
    cout << t << endl;
  }
}