#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> data = {a, b, c};
  sort(data.begin(), data.end());
  if (data.at(0) + data.at(1) == data.at(2)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
