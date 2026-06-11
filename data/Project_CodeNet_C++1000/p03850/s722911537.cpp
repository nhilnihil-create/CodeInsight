#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>

#define FOR(n) for(int cnt=0;cnt<(n);++cnt)
#define FOR_R(it,cont) for(auto it=rbegin(cont);it!=rend(cont);++it)
#define FOR_F(it,cont) for(auto it=begin(cont);it!=end(cont);++it)
#define ALL(cont) begin(cont), end(cont)
#define LB(b,e,v) lower_bound(b,e,v)
#define UB(b,e,v) upper_bound(b,e,v)

using namespace std;
typedef pair<int,int> P;
int N;
int A[100010];
long long dp[100010][10];
long long INF= 1ll * 1000 * 1000 * 1000* 1000* 1000;
int pow1(int i) {
  return i%2==0?1:-1;
}
long long doDP(int current, int brackets) {
  if (brackets < 0) {
    return 0;
  }
  if (brackets > 2) {
    return 0;
  }
  if (dp[current][brackets]!=-INF) {
    return dp[current][brackets];
  }
  if (current == N) {
    return dp[current][brackets]=0;
  }
  long long sub=-INF;
  if (A[current] < 0) {
    for(int i=0;i<=brackets+1;++i) {
      sub = max(sub, 1ll * pow1(brackets) * A[current] + doDP(current+1, i));
    }
  } else {
    for(int i=0;i<=brackets;++i) {
      sub = max(sub, 1ll * pow1(brackets) * A[current] + doDP(current+1, i));
    }
  }
  return dp[current][brackets] = sub;
}
int main() {
  scanf("%d", &N);
  FOR(N) {
    int factor=1;
    if (cnt > 0) {
      char buf[2];
      scanf("%s", buf);
      if (buf[0]=='-') {
        factor=-1;
      }
    }
    scanf("%d", &A[cnt]);
    A[cnt] *= factor;
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<5;++j) {
      dp[i][j] = -INF;
    }
  }

  doDP(0,0);

  long long answer=0;
  for(int i=0;i<3;++i) {
    answer = max(answer, dp[0][i]);
  }
  printf("%lld\n", answer);
  return 0;
}
