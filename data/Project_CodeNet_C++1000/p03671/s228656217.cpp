#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> bell(3);
  cin >> bell.at(0) >> bell.at(1) >> bell.at(2);
  sort(bell.begin(), bell.end());
  cout << bell.at(0) + bell.at(1) << endl;
}
