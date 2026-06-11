#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  vector<int> A, B;
  REP(i, M) {
    int x;
    scanf("%d", &x);
    if (x % 2) {
      B.push_back(x);
    } else {
      A.push_back(x);
    }
  }

  vector<int> a = A;
  if (B.size() > 0) {
    a.insert(a.begin(), B.back());
    B.pop_back();
  }

  if (B.size() > 0) {
    a.push_back(B.back());
    B.pop_back();
  }

  if (B.size() > 0) {
    puts("Impossible");
    return 0;
  }

  vector<int> b;
  if (a.size() == 1) {
    b.push_back(1);
    if (a[0] > 1) b.push_back(a[0] - 1);
  } else {

  REP(i, (int)a.size()) {
    int x = a[i];
    if (i == 0) {
      x--;
    } else if (i == (int)a.size() - 1) {
      x++;
    }

    if (x > 0) b.push_back(x);
  }
  }

  for (int x: a) printf("%d ", x);
  printf("\n");
  printf("%d\n", (int)b.size());
  for (int x: b) printf("%d ", x);
  printf("\n");

  return 0;
}
