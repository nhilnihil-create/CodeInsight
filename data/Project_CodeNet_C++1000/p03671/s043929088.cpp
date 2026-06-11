#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> list(3);
  for (int i=0; i<3; i++) {
    int t;
    cin >> t;
    list.at(i) = t;
  }
  sort(list.begin(),list.end());
  cout << list.at(0)+list.at(1) << endl;
}