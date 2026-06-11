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

int main() {
  int N;
  LL X;
  cin >> N >> X;
  vector<LL> v(N);
  REP(i, N) {
    cin >> v[i];
  }
  LL ret = accumulate(v.begin(), v.end(), 0LL);
  for(int i=1; i<N; ++i) {
    vector<LL> nv(N);
    REP(j, N) {
      nv[j] = min(v[j], v[(j-1+N)%N]);
    }
    v = nv;
    ret = min(ret, accumulate(v.begin(), v.end(), 0LL) + X * i);
  }
  cout << ret << endl;
}