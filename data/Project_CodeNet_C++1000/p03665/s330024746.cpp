#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}
void solve(long long N, long long P, std::vector<long long> A){
  ll e = 0;
  ll o = 0;
  ll ans = 0;
  rep(i,N) {
    if(A[i]%2)
      o++;
    else
      e++;
  }
  vector<vector<ll>> com(o+1, vector<ll>(o+1, 0));
  for(ll i=0; i<o+1; i++) {
    for(ll j=0; j<i+1; j++) {
      if(j==0) com[i][j] = 1;
      else if(j==i) com[i][j] = 1;
      else com[i][j] = com[i-1][j-1]+com[i-1][j];
    }
  }

  if(P==0) {
    for(ll i=0; i<=o; i+=2) {
      ans += com[o][i];
    }
    ans *= pow(2,e);
  } else {
    for(ll i=1; i<=o; i+=2)
      ans += com[o][i];
    ans *= pow(2,e);
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long P;
  scanf("%lld",&P);
  std::vector<long long> A(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, P, std::move(A));
  return 0;
}

