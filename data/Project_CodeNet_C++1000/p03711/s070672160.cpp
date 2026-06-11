#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool contains(const vector<T>& vec, const T& item) {
  return std::find(vec.begin(), vec.end(), item) != vec.end();
}

int main() {
  int x, y;
  cin >> x >> y;

  vector<int> a = {1, 3, 5, 7, 8, 10, 12};
  vector<int> b = {4, 6, 9, 11};

  if (x == 2 || y == 2) {
    cout << "No" << endl;
    return 0;
  }

  if (contains(a, x) && contains(a, y)) {
    cout << "Yes" << endl;
    return 0;
  }

  if (contains(b, x) && contains(b, y)) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
