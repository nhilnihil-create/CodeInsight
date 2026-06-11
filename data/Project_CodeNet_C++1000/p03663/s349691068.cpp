#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long LL;

const LL MAXN = 1000000000, MAXQN = MAXN * MAXN;

bool makeGuess(LL n) {
  printf("? %lld\n", n);
  fflush(stdout);
  char c;
  scanf(" %c", &c);
  return (c == 'Y');
}

void giveAnswer(LL n) {
  printf("! %lld\n", n);
  fflush(stdout);
}

void treatSpecialCase() {
  for (LL i = MAXN; i > 1; i /= 10)
  if (!makeGuess(i - 1))
    return giveAnswer(i);
  giveAnswer(1);
}

LL getUBound() {
  for (LL i = 10;; i *= 10)
  if (!makeGuess(i)) return i;
}

void treatNormalCase() {
  LL right = getUBound(), left = right / 10;
  --right, ++left;
  LL found = -1;
  while (left <= right) {
    LL mid = left + (right - left) / 2;
    if (makeGuess(mid * MAXN)) {
      found = mid;
      right = mid - 1;
    }
    else left = mid + 1;
  }
  giveAnswer(found);
}

int main() {
  if (makeGuess(MAXN))
    treatSpecialCase();
  else treatNormalCase();
  return 0;
}
