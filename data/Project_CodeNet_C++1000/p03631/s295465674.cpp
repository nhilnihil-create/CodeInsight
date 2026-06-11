/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc070_a.cpp
 * time   : Tue Apr 28 23:30:28 2020
 * quest  : A - Palindromic Number
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
  cout << ((n % 10) == (n / 100) ? "Yes": "No") << "\n";
  return 0;
}
