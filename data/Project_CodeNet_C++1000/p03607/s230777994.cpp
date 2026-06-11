#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, bool> in;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (in[tmp]) {
      in.erase(tmp);
    }
    else {
      in[tmp] = true;
    }
  }
  cout << in.size() << endl;
}
