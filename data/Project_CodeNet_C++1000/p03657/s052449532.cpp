/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc067_a.cpp
 * time   : Tue Apr 28 23:06:16 2020
 * quest  : A - Sharing Cookies
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
  int a, b;
  cin >> a >> b;
  cout << (((a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0)) ? "Possible" : "Impossible") << "\n";
  return 0;
}
