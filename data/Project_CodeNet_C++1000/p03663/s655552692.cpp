
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

inline bool query(ll x) {
  char buf[10];
  printf("? %lld\n", x);
  fflush(stdout);
  scanf("%s", buf);
  return buf[0] == 'Y';
}

inline void answer(ll x) {
  printf("! %lld\n", x);
  fflush(stdout);
  exit(0);
}


int main(void) {
  ll res = 0;
  bool all9 = true;
  { // 1桁目
    ll left = 0;
    ll right = 9;
    while(left+1 < right) {
      ll md = (left + right) / 2;
      bool q = query(md * 1000000000 + 999999999);
      if(q) { // str(md) > str(N)
        right = md;
      } else {
        left = md;
      }
    }
    if(right != 9) {
      all9 = false;
    }
    res = right;
  }

  for(ll t = 100000000; ; t /= 10) { // 2桁目以降
    // まずあるか無いか
    if(query(res + 1) == !all9) {
      answer(res);
      break;
    } else {
      ll left = -1;
      ll right = 9;
      while(left+1 < right) {
        ll md = (left + right) / 2;
        bool q = query(res * 10*t + md * t + t-1);
        if(q) { // str(md) > str(N)
          right = md;
        } else {
          left = md;
        }
      }
      if(right != 9) {
        all9 = false;
      }
      res = res * 10 + right;
    }
  }
  return 0;
}
