#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[3];
  cin >> x[0] >> x[1] >> x[2];
  set<int> set{{x[0]}, {x[1]}, {x[2]}};
  cout << set.size() << endl;
  getchar();
}