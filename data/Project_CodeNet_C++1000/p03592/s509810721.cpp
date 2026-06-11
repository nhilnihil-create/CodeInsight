#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define ALL(x) (x).begin(),(x).end()

inline cpp_int between(cpp_int n, cpp_int x) {
  if(n >= 0)
    return (n/x)+1;
  else
    return 0;
}

int main () {
  int w, h, k;
  cin >> w >> h >> k;

  REP(i, h+1) {
    REP(j, w+1) {
      if((i * (w-j)) + ((h-i) * j) == k) {
        cout << "Yes" << endl;
        return 0;
      }

    }
  }

  cout << "No" << endl;
  return 0;
}
