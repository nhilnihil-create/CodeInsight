#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};

ll N;
ll A[100010];
std::vector<ll> crds;
std::map<ll, ll> mp;
bool fl[100010];

int main()
{
  scanf( "%lld", &N );
  
  rep( i, N )
  {
    scanf( "%lld", A+i );

    crds.emplace_back( A[i] );
  }

  std::sort( all(crds) );

  rep( i, N )
    mp[crds[i]] = i;

  rep( i, N )
    fl[mp[A[i]]] = i&1;

  ll cnt = 0;
  rep( i, N )
    cnt += (fl[mp[crds[i]]] != (i&1));

  printf( "%lld\n", cnt/2 );

  return 0;
}