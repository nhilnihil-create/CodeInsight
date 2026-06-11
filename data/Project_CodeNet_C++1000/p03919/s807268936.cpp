/*  -*- coding: utf-8 -*-
 *
 * a.cc: A: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int h, w;
  cin >> h >> w;

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      string s;
      cin >> s;
      if (s == "snuke") printf("%c%d\n", 'A' + x, y + 1);
    }
  return 0;
}
