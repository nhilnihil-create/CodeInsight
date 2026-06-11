#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  set<int> V={4,6,9,11};
  if (x==2 || y==2 || (V.count(x) && !(V.count(y))) || (V.count(y) && !(V.count(x)))) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
