#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

ll llmax(ll a, ll b){
  if(a > b) return a;
  return b;
}
int main(int argc, char const *argv[]) {
  ll N, K, ans = 0;
  std::cin >> N >> K;
  std::vector<ll> S(N, 0), A(N), plus(N);
  for(int i=0;i<N;i++){
    std::cin >> A[i];
    S[i] = (i==0?A[0]:S[i-1]+A[i]);
    plus[i] = (i==0?0:plus[i-1]) + (A[i]>0?A[i]:0);
  }
  for(int i=0;i<N-K+1;i++){
    //std::cout << plus[N-1] << " " << plus[i+K-1] << " " << (i==0?0:plus[i-1]) << '\n';
    //std::cout << llmax(0, S[i+K] - (i==0?0:S[i-1])) << '\n';
    ans = max(ans, plus[N-1] - plus[i+K-1] + (i==0?0:plus[i-1]) + llmax(0, S[i+K-1] - (i==0?0:S[i-1])));
  }
  std::cout << ans << '\n';
  return 0;
}
