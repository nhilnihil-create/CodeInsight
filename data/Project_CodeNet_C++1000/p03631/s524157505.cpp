#include <algorithm>
#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

std::string N;

int main()
{
  std::cin >> N;

  std::string R = N;

  std::reverse( all(R) );

  bool fl = true;

  rep( i, N.size() )
    fl &= N[i]==R[i];

  std::cout << (fl ? "Yes" : "No" ) << std::endl;

  return 0;
}