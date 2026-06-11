#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
#define Inf 1000000000000
using namespace std;

int main() {
  int64_t x, y, A, B, C, D;
  cin >> x >> y;
  if (x<=y) {
    A=y-x;
  }
  else {
    A=Inf;
  }
  if (-x<=y) {
    B=y+x+1;
  }
  else {
    B=Inf;
  }
  if (x<=-y) {
    C=-y-x+1;
  }
  else {
    C=Inf;
  }
  if (-x<=-y) {
    D=-y+x+2;
  }
  else {
    D=Inf;
  }
  C=min(C,D);
  B=min(B,C);
  A=min(A,B);
  cout << A << endl;
}