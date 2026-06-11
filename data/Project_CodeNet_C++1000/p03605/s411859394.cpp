/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc073_a.cpp
 * time   : Wed Apr 29 00:35:53 2020
 * quest  : A - September 9
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
  int n;
  cin >> n;
  cout << (((n % 10 == 9) || (n / 10 == 9)) ? "Yes" : "No") << "\n";
  return 0;
}
