/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc071_a.cpp
 * time   : Tue Apr 28 23:35:59 2020
 * quest  : A - Meal Delivery
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
  int x, a, b;
  cin >> x >> a >> b;
  cout << (abs(a - x) > abs(b - x) ? 'B' : 'A') << "\n";
  return 0;
}
