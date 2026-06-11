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
using namespace std;

int main() {
  int sx, sy, tx, ty, dx, dy;
  cin >> sx >> sy >> tx >> ty;
  dx=tx-sx;
  dy=ty-sy;
  for (int i=0; i<dx; i++) {
    cout << "R";
  }
  for (int i=0; i<dy; i++) {
    cout << "U";
  }
  for (int i=0; i<dx; i++) {
    cout << "L";
  }
  for (int i=0; i<dy; i++) {
    cout << "D";
  }
  cout << "D";
  for (int i=0; i<dx+1; i++) {
    cout << "R";
  }
  for (int i=0; i<dy+1; i++) {
    cout << "U";
  }
  cout << "L" << "U";
  for (int i=0; i<dx+1; i++) {
    cout << "L";
  }
  for (int i=0; i<dy+1; i++) {
    cout << "D";
  }
  cout << "R" << endl;
}