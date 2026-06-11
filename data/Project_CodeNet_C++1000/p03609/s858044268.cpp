/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc072_a.cpp
 * time   : Tue Apr 28 23:40:54 2020
 * quest  : A - Sandglass2
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x, t;
  cin >> x >> t;
  cout << ((x - t) > 0 ? (x - t) : 0) << "\n";
  return 0;
}
