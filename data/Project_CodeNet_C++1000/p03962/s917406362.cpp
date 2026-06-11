#include<bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> n = {a, b, c};
  sort(n.begin(), n.end());
  int count = 3;
  if (n.at(0) == n.at(1)) {
    count--;
  }
  if (n.at(1) == n.at(2)) {
    count--;
  }
  cout << count << endl;
}