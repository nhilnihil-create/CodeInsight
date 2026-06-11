#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

LL comb(int a, int b, int c = -1) {
  LL ar[51] = {1};
  for(int i=1; i<=a; ++i) {
    for(int j=i; j>=0; --j) {
      ar[j+1] += ar[j];
    }
  }
  if(c == -1) {
    return ar[b];
  } else {
    LL ret = 0;
    for(int i=b; i<=c; ++i) {
      ret += ar[i];
    }
    return ret;
  }
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<LL> v(N);
  REP(i, N) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<LL>());
  
  cout << fixed << setprecision(9) << (double)accumulate(v.begin(), v.begin() + A, 0LL) / A << endl;
  
  int rmin = -1, rmax;
  REP(i, N) {
    if(v[i] == v[A-1]) {
      if(rmin < 0) {
        rmin = i;
      }
      rmax = i;
    }
  }
  if(v[0] == v[A-1]) {
    B = min(B, rmax + 1);
    //cerr << rmax + 1 << " C " << A << "-" << B << endl;
    LL ret = comb(rmax + 1, A, B);
    cout << ret << endl;
  } else {
    //cerr << rmax - rmin + 1 << " C " << A - rmin << endl;
    LL ret = comb(rmax - rmin + 1, A - rmin);
    cout << ret << endl;  
  }
}