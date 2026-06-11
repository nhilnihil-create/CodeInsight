#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
  string S; cin >> S;
  int N = S.size();
  long long ans = 0;
  REP(bit, (1<<(N-1))){
    long long res = 0;
    long long tmp = 0;
    REP(i, N){
      tmp *= 10;
      tmp += S[i] - '0';
      if ((bit>>i) & 1) res += tmp, tmp = 0;
    }
    ans += res + tmp;
  }
  cout << ans << endl;
  return 0;
}
