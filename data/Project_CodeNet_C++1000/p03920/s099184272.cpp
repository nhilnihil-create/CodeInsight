/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: 
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
  int n;
  cin >> n;

  int sum = 0, k = 0;
  while (sum < n) {
    ++k;
    sum += k;
  }
  //printf("k=%d,sum=%d\n", k, sum);

  int d = sum - n;
  for (int i = 1; i <= k; i++)
    if (i != d) printf("%d\n", i);
  return 0;
}
