#include <algorithm>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

const long P = 1e9+7;
tuple<long,long,long> ext_gcd(long a, long b) {
  if (b==0)
    return make_tuple(a,1,0);
  auto gxy = ext_gcd(b,a%b);
  auto y = get<2>(gxy);
  return make_tuple(get<0>(gxy),y,get<1>(gxy)-a/b*y);
}
long invmod(long a) {
  auto gxy = ext_gcd(a,P);
  return (get<1>(gxy)+P) % P;
}
long powmod(long a,long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long c = powmod(a, b/2);
  c = c*c%P;
  if (b%2) c = c*a%P;
  return c;
}
long N, M;
string S;
int main() {
  cin >> N;
  cin >> S;
  M = S.size();
  vector<long> dp(N+1,0);
  dp[0] = 1;
  for (int n=0; n<N; ++n) {
    vector<long> ndp(N+1,0);
    for (int m=max(0l,M-(N-n)); m<=min(1l*n,M+(N-n)); ++m) {
      auto c = dp[m]%P;
      ndp[max(0,m-1)] += c;
      ndp[m+1] += c*2;
    }
    dp.swap(ndp);
  }
  cout << (1ll*dp[M]*invmod(powmod(2,M)))%P << endl;
}
