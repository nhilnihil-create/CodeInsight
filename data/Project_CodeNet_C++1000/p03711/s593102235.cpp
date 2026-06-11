#include <iostream>
#include <string>
#include <vector>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int x, y;
  cin >> x >> y;

  std::set<int> a = {1, 3, 5, 7, 8, 10, 12};
  std::set<int> b = {4, 6, 9, 11};
  if (x == y) cout << "Yes" << endl;
  else {
    if (a.find(x) != a.end() && a.find(y) != a.end()) cout << "Yes" << endl;
    else if (b.find(x) != b.end() && b.find(y) != b.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
