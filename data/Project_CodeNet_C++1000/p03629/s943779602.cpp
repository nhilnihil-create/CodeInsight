#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}

template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }

  ll x = 1;

  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin>>s;

  ll n=s.size();

  std::vector<std::vector<ll>> occur(26);

  rep(i,0,n)occur[s[i]-'a'].push_back(i);

  std::vector<ll> len(n,1);

  std::vector<ll> temp(26,0);

  temp[s[n-1]-'a']++;

  for(ll i=n-2;i>=0;i--){
    temp[s[i]-'a']++;
    len[i]=len[i+1];
    bool flag=true;
    rep(j,0,26)flag&=(temp[j]>0);

    if(flag){
      len[i]++;
      rep(j,0,26)temp[j]=0;
    }
  }

  std::string ans="";
  ll now=0;

  rep(i,0,len[0]){
    rep(j,0,26){
      auto itr=std::lower_bound(all(occur[j]),now);
      if(itr==occur[j].end()||len[now]-1==len[*itr+1]){
        ans+=(char)('a'+j);
        if(itr!=occur[j].end())now=*itr+1;
        break;
      }
    }
  }

  std::cout<<ans;

  return 0;
}