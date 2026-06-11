#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main(){
  string s;ll k;cin>>s>>k;
  rep(i,0,s.size()-1){
    if(k<26-(s[i]-'a')){
      continue;
    }
    if(s[i]=='a')continue;
    k-=26-(s[i]-'a');
    s[i]='a';
    
  }
  k%=26;
  if(26-(s[s.size()-1]-'a')<=k){
    k-=26-(s[s.size()-1]-'a');
    s[s.size()-1]='a';
    s[s.size()-1]+=k;
  }
  else{
    s[s.size()-1]+=k;
  }
  cout<<s<<endl;
}





