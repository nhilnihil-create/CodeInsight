#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

const int MAXN = 234567;
LL sum[MAXN];

int main() {
    int N;
    while (~scanf("%d", &N)) {
          for (int i = 1; i <= N; i++) {
              LL tmp;
              scanf("%lld", &tmp);
              sum[i] = sum[i - 1] + tmp;
          }
          LL ans = (LL)1e18;
          for (int i = 1; i < N; i++) {
              LL f = sum[i], s = sum[N] - sum[i];
              ans = min(ans, abs(f - s));
          }
          printf("%lld\n", ans);
    }
    return 0;
}
