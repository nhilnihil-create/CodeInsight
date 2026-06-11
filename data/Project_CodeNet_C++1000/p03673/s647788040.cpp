#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  list<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i % 2) {
      a.push_back(x);
    } else {
      a.push_front(x);
    }
  }
  if (n % 2) {
    for (auto i = a.begin(); i != a.end(); i++) {
      cout << *i << " ";
    }
  } else {
    for (auto i = a.rbegin(); i != a.rend(); i++) {
      cout << *i << " ";
    }
  }
  cout << endl;
  return 0;
}
