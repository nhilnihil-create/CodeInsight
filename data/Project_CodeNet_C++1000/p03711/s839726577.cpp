#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> MA;
  vector<int> V1 = {1,3,5,7,8,10,12};
  vector<int> V2 = {4,6,9,11};
  vector<int> V3 = {2};
  for (auto v : V1) MA[v] = 1;
  for (auto v : V2) MA[v] = 2;
  for (auto v : V3) MA[v] = 3;
  int x, y;
  cin >> x >> y;
  cout << ((MA[x] == MA[y]) ? "Yes" : "No") << "\n";
}