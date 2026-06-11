
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;

int vs[100000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
  }
  int res = 0;
  REP(i, n) {
    if(vs[i] == i+1) {
      ++res;
      swap(vs[i], vs[i+1]);
    }
  }
  printf("%d\n", res);
 
  return 0;
}
