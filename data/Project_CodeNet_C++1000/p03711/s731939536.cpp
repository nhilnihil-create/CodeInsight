#include <iostream>
#include <set>

using namespace std;

namespace {
const set<int> group_a = {1, 3, 5, 7, 8, 10, 12};
const set<int> group_b = {4, 6, 9, 11};
}

int main() {
  int X, Y;
  cin >> X >> Y;
  
  if ((group_a.count(X) != 0 && group_a.count(Y) != 0) 
       || (group_b.count(X) != 0 && group_b.count(Y) != 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}
