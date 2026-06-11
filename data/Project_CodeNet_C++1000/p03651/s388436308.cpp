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
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, K;
ll A[100010];
ll g, ma;

ll gcd( ll a, ll b )
{ return b ? gcd(b,a%b) : a; }

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> A[i], g = gcd( g, A[i] ), chmax( ma, A[i] );

  std::cout << (K % g == 0 && K <= ma ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;

  return 0;
}