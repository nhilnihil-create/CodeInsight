/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc066_a.cpp
 * time   : Tue Apr 28 22:57:18 2020
 * quest  : A - ringring
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
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a + b, min(b + c, a + c)) << "\n";
  return 0;
}
