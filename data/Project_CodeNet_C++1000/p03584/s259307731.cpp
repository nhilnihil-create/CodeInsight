#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

string print_ll(LL v) {
  string s = "";
  while(v != 0) {
    s = (v % 2 == 0 ? '0' : '1') + s;
    v >>= 1;
  }
  return s;
}

int main() {
  LL N, K;
  cin >> N >> K;
  vector<LL> A(N), B(N);
  REP(i, N) { cin >> A[i] >> B[i]; }
  LL ret = 0;
  REP(i, 32) {
    if(i == 0 || K & (1 << i)) {
      LL tret = 0;
      LL nK = ((K >> i) << i) - (i == 0 ? 0 : 1);
      cerr << print_ll(nK) << endl;
      REP(i, N) {
        if((nK | A[i]) == nK) {
          tret += B[i];
        }
      }
      ret = max(ret, tret);
    }
  }
  cout << ret << endl;
}