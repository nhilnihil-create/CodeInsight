#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;


void solve(long long N, long long x){
  if (x == 1 || x == (2*N-1)) {
    std::cout << "No" << std::endl;
    return;
  }

  vector<int> ans(2*N-1);
  if (N == 2) {
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 3;
  } else {
    if (x == 2) {
      ans[N-2] = 4;
      ans[N-1] = 1;
      ans[N] = 2;
      ans[N+1] = 3;
    } else if (x == (2*N-2)) {
      ans[N-2] = 2*N - 4;
      ans[N-1] = 2*N - 1;
      ans[N] = 2*N - 2;
      ans[N+1] = 2*N - 3;
    } else {
      ans[N-2] = x+2;
      ans[N-1] = x-1;
      ans[N] = x;
      ans[N+1] = x+1;
    }

    int a = 1;
    for (int i = 0; i < 2*N-1; ++i) {
      if (i >= N-2 && i <= N+1) continue;
      while (a == ans[N-2] || a == ans[N-1] || a == ans[N] || a == ans[N+1]) a++;
      ans[i] = a;
      a++;
    }
  }

  std::cout << "Yes" << std::endl;
  for (int i = 0; i < 2*N-1; ++i) {
    std::cout << ans[i] << std::endl;
  }
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long x;
  scanf("%lld",&x);
  solve(N, x);
  return 0;
}
