#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main() {
  int N;
  cin >> N;
  vector<LL> A(N);
  REP(i, N) { cin >> A[i]; }
  vector<LL> sA(A), sumA(N+1, 0);
  sort(sA.begin(), sA.end());
  
  for(int i=N-1; i>=0; --i) {
    sumA[i] = sA[i] + sumA[i+1];
  }
  LL tmax = 0, put = 0;
  REP(i, N) {
    if(A[i] > tmax) {
      tmax = A[i];
      int idx = upper_bound(sA.begin(), sA.end(), tmax) - sA.begin();
      LL tput = sumA[0] - put - (sumA[idx] - (N - idx) * tmax);
      cout << tput << endl;
      put += tput;
    } else {
      cout << 0 << endl;
    }
  }
}