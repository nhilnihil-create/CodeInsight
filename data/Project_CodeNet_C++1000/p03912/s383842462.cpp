#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll N, M;
std::map<ll, ll> mp, mod, dup;
ll ans;

int main()
{
  std::cin >> N >> M;

  rep( i, N )
  {
    ll X;
    std::cin >> X;

    ++mp[X];
    ++mod[X%M];
  }

  itr( it, mp )
  {
    if( it->second >= 2 )
    {
      dup[it->first%M] += it->second/2;
    }
  }

  ans += mod[0]/2;

  if( !(M&1) )
    ans += mod[M/2]/2;
  
  repi( i, 1, (M+1)/2 )
  {
    ans += std::min( mod[i], mod[M-i] );

    if( mod[i] > mod[M-i] )
      ans += std::min( (mod[i]-mod[M-i])/2, dup[i] );
    
    if( mod[i] < mod[M-i] )
      ans += std::min( (mod[M-i]-mod[i])/2, dup[M-i] );
  }
  
  std::cout << ans << std::endl;

  return 0;
}