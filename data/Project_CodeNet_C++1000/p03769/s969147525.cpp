#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

typedef long long i64;

i64 N;

int dig[50], tot;
deque<int> res;

int main() {
  scanf("%lld", &N);
  int num;
  for (int i = 40; i; --i) {
    i64 X = (1LL << i) - 1;
    if (X <= N) {
      num = i, N -= X;
      break;
    }
  }

  for (int i = num, now = 0; i >= 0; --i) {
    i64 X = 1LL << i;
    if (N >= X) {
      res.push_front(++now);
      N -= X;
    } 
    if (i) res.push_back(++now);
  }

  printf("%d\n", res.size() * 2);

  for (int i = 0; i < res.size(); ++i)
    printf("%d ", res[i]);
  
  // static i64 f[205];

  // i64 way = 0;
  // for (int i = 0; i < res.size(); ++i) {
  //   f[i] = 1;
  //   for (int j = 0; j < i; ++j)
  //     if (res[j] < res[i]) f[i] += f[j];
  //   way += f[i];
  // }
  // printf("%lld\n", way);
  
  for (int i = 0; i < res.size(); ++i)
    printf("%d ", i + 1);
  puts("");
  return 0;
}